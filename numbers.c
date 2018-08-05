#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // accepts an input in the form of xx-0000
    // the letters will be initials
    // numbers will be age passcodes
    // accpet 2 arguments 1) [the code]
    // 2) hash integer 1-9999
    if(argc != 3) {
        printf("Usage: ./mumbers xx-000 1-9999\n");
        return 1;
    }
    string passcode = argv[1];
    double hash = atol(argv[2]);
    // validate prameters
    if (strlen(argv[1]) != 7) {
        printf("Parameter 1 must be 7 characters\n");
    }
    // setup and array for the numeric code
    char numbers[5];
    char letters[3];
    int x = 0;
    int y = 0;
    int z = 0;
    while(x < 8) {
        if(isdigit(passcode[x])) {
            numbers[y++] = passcode[x];
            // y++;
        } else if (isalpha(passcode[x])) {
            letters[z++] = passcode[x];
            // z++;
        }
        x++;
    }
    // print out the array of numbers as a string
    printf("%s\n", numbers);
    int code = atoi(numbers);
    if (strcmp(letters, "xy") != 0) {
        printf(" Your 4-digit code is %i\n", code);
        // disgusie the code for incryption
        double securecode = code/2;
        printf("Your super secure code is %lf\n", pow(securecode, hash));
    } else {
        // if letters not equal to xy add one to the input code
        printf("Your super-secure xy code is %i\n", code+1);
    }
    return 0;
}