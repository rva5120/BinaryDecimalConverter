//
//  main.cpp
//  BinaryDecimalConverter
//
//  Created by Raquel Alvarez on 11/14/14.
//  Copyright (c) 2014 R. All rights reserved.
//


#include<iostream>
#include <cmath>
//using namespace std;

std::string decimalToBinary(int n)
{
    if (n == 0)
        return "0";
    if (n == 1)
        return "1";
    if (n % 2 == 0)
        return decimalToBinary(n/2) + "0";
    else
        return decimalToBinary(n/2) + "1";
}

int binaryToDecimal(std::string b, int size)       // size = getSize(binary)
{
    int temp = 0;
    int decimal = 0;
    
    for (int i = size - 1 ; i >= 0; i--)
    {
        if (b.at(i) == '1')
            decimal = decimal + pow(2, temp);
        temp++;
    }
    return decimal;
}

void printArray (int b[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << b[i];
    }
}

int getSize (std::string s)
{
    int i = 0;
    int size = 0;
    while (s.at(i) != 'n')
    {
        size++;
        i++;
    }
    return size;
}

int main ()
{
    char conversionType = NULL;
    int decimal = 0;         // decimal number to convert
    std::string binary;     // binary number to convert
    bool cont = true;
    
    binary.clear();
    
    std::cout << "Binary/Decimal converter" << std::endl;
    std::cout << " -- To go from decimal to binary use d when promped" << std::endl;
    std::cout << " -- To go from binary to decimal use b when promped" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << std::endl;
    
    
    while (cont)
    {
        std::cout << "Enter the type of conversion you need (d or b): ";
        std::cin >> conversionType;
        
        if (conversionType == 'd')
        {
            std::cout << "Enter the decimal value that you would like to convert to binary: ";
            std::cin >> decimal;
            binary = decimalToBinary(decimal);
            std::cout << decimal << " -> " << binary << std::endl;
            std::cout << "Would you like to start a new conversion? Yes? enter 1, otherwise enter 0: ";
            std::cin >> cont;
            std::cout << std::endl;
        }
        else if (conversionType == 'b')
        {
            std::cout << "Enter the binary value that you would like to convert to decimal, for example if you would like to convert 101 to decimal, enter 101n (add n to the end of the value): ";
            std::cin >> binary;
            decimal = binaryToDecimal(binary, getSize(binary));
            std::cout << binary << " -> " << decimal << std::endl;
            std::cout << "Would you like to start a new conversion? Yes? enter 1, otherwise enter 0: ";
            std::cin >> cont;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Error: The value entered is not d or b." << std::endl;
            cont  = true;
        }
        
        binary.clear();
        decimal = 0;
    }
    
    return 0;
    
}