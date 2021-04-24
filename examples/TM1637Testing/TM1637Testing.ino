//#include <Arduino.h>
#include "TM1637Display.h"

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3
//ESP8266
/*
  IO-1/TX  * GND
  CH-PD   * IO-2
  RST     * IO-0
  VCC     * IO-3  RX
*/
//#define CLK 3
//#define DIO 1

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000

const uint8_t SEG_DONE[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
};

TM1637Display display(CLK, DIO);

void setup()
{
  // pinMode(1, FUNCTION_3);
  //GPIO 3 (RX) swap the pin to a GPIO.
  //pinMode(3, FUNCTION_3);
  //pinMode(CLK, OUTPUT);
  //pinMode(CLK, OUTPUT);
  //display.begin();
  //display.setBrightness(5, true);
  //display.setBrightness(2, true); // Turn on
  display.setBrightness(0x01);
}

void loop()
{
  /*int k;
    uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
    uint8_t blank[] = { 0x00, 0x00, 0x00, 0x00 };

    // All segments on
    display.setSegments(blank);
    delay(TEST_DELAY);*/
  /*
      // Selectively set different digits
      data[0] = display.encodeDigit(0);
      data[1] = display.encodeDigit(1);
      data[2] = display.encodeDigit(2);
      data[3] = display.encodeDigit(3);
      display.setSegments(data);
      delay(TEST_DELAY);
      //Isi CALL
      data[0] = display.encodeDigit(12); // C
      data[1] = display.encodeDigit(10); // A
      data[2] = display.encodeDigit(21); // L
      data[3] = display.encodeDigit(21); // L
      display.setSegments(data);
      delay(TEST_DELAY);
      //Isi rECL
      data[0] = display.encodeDigit(27); // r
      data[1] = display.encodeDigit(14); // E
      data[2] = display.encodeDigit(12); // C
      data[3] = display.encodeDigit(21); // L
      display.setSegments(data);
      delay(TEST_DELAY);
      //Isi Entr
      data[0] = display.encodeDigit(14); // E
      data[1] = display.encodeDigit(23); // n
      data[2] = display.encodeDigit(29); // t
      data[3] = display.encodeDigit(27); // r
      display.setSegments(data);
      delay(TEST_DELAY);
      data[0] = display.encodeDigit(10); // A
      data[1] = display.encodeDigit(0);  // 0
      data[2] = display.encodeDigit(0);  // 0
      data[3] = display.encodeDigit(7);  // 7
      display.setSegments(data);
      delay(TEST_DELAY);
  */
  //data[0] = display.encodeDigit(10); // A
  // display.setSegments(1, 3, 0);
  //display.show(1, 2, 3, 4);
  //delay(TEST_DELAY);
  for (byte k = 0; k < 38; k++) {
    //display.show(k, k - 1, k - 2, k - 3);
    display.show(k, k, k, k );
    //display.show(k, 1);
    delay(750);
  }
  /* for (k = 3; k >= 0; k--) {
     display.setSegments(data, 1, k);
     delay(TEST_DELAY);
    }*/

  /*
    display.clear();
    display.setSegments(data + 2, 2, 2);
    delay(TEST_DELAY);

    display.clear();
    display.setSegments(data + 2, 2, 1);
    delay(TEST_DELAY);

    display.clear();
    display.setSegments(data + 1, 3, 1);
    delay(TEST_DELAY);


    // Show decimal numbers with/without leading zeros
    display.showNumberDec(0, false); // Expect: ___0
    delay(TEST_DELAY);
    display.showNumberDec(0, true);  // Expect: 0000
    delay(TEST_DELAY);
    display.showNumberDec(1, false); // Expect: ___1
    delay(TEST_DELAY);
    display.showNumberDec(1, true);  // Expect: 0001
    delay(TEST_DELAY);
    display.showNumberDec(301, false); // Expect: _301
    delay(TEST_DELAY);
    display.showNumberDec(301, true); // Expect: 0301
    delay(TEST_DELAY);
    display.clear();
    display.showNumberDec(14, false, 2, 1); // Expect: _14_
    delay(TEST_DELAY);
    display.clear();
    display.showNumberDec(4, true, 2, 2);  // Expect: __04
    delay(TEST_DELAY);
    display.showNumberDec(-1, false);  // Expect: __-1
    delay(TEST_DELAY);
    display.showNumberDec(-12);        // Expect: _-12
    delay(TEST_DELAY);
    display.showNumberDec(-999);       // Expect: -999
    delay(TEST_DELAY);
    display.clear();
    display.showNumberDec(-5, false, 3, 0); // Expect: _-5_
    delay(TEST_DELAY);
    display.showNumberHexEx(0xf1af);        // Expect: f1Af
    delay(TEST_DELAY);
    display.showNumberHexEx(0x2c);          // Expect: __2C
    delay(TEST_DELAY);
    display.showNumberHexEx(0xd1, 0, true); // Expect: 00d1
    delay(TEST_DELAY);
    display.clear();
    display.showNumberHexEx(0xd1, 0, true, 2); // Expect: d1__
    delay(TEST_DELAY);

    // Run through all the dots
    for (k = 0; k <= 4; k++) {
      display.showNumberDecEx(0, (0x80 >> k), true);
      delay(TEST_DELAY);
    }

    /* // Brightness Test
      for (k = 0; k < 4; k++)
       data[k] = 0xff;
      for (k = 0; k < 7; k++) {
       display.setBrightness(k);
       display.setSegments(data);
       delay(TEST_DELAY);
      }

      // On/Off test
      for (k = 0; k < 4; k++) {
       display.setBrightness(7, false);  // Turn off
       display.setSegments(data);
       delay(TEST_DELAY);
       display.setBrightness(7, true); // Turn on
       display.setSegments(data);
       delay(TEST_DELAY);
      }


    // Done!
    //display.setSegments(SEG_DONE);

    //while (1);
  */
}
