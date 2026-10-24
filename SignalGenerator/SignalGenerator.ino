// Arduino + AD9833 DDS signal generator
// Course project: Signal Analysis and Communication Systems (ULACIT, Dec 2023)
//
// The waveform is chosen by editing WAVEFORM below and re-uploading the sketch.
// NOTE: cleaned-up version of the class code. Not re-tested after cleanup.
// Library: "AD9833" by Rob Tillaart (Arduino Library Manager).

#include <SPI.h>
#include "AD9833.h"

// Pick ONE: AD9833_SINE, AD9833_SQUARE1, AD9833_TRIANGLE
#define WAVEFORM AD9833_TRIANGLE

const uint8_t  SELECT_PIN = 10;      // hardware SPI chip select
const float    FREQUENCY_HZ = 1000;  // output frequency

AD9833 AD;

void setup() {
  Serial.begin(9600);
  Serial.println(__FILE__);

  AD.begin(SELECT_PIN);
  Serial.print("hardware SPI:\t");
  Serial.println(AD.usesHWSPI());

  AD.setWave(WAVEFORM);
  AD.setFrequency(FREQUENCY_HZ, 0);   // frequency register 0
  AD.setFrequencyChannel(0);

  Serial.print("waveform:\t");
  Serial.println(AD.getWave());
  Serial.print("frequency (Hz):\t");
  Serial.println(AD.getFrequency(0));
}

void loop() {
  // Nothing to do: the AD9833 keeps generating the selected waveform.
}
