// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int size;
    cin >> size;
    int min = -2000000000;
    int max = 2000000000;
    bool minOpen = false;
    bool maxOpen = false;

    int _mode = -1;
    string mode,type;
    int n;
    for (int i = 0; i < size; i++)
    {
        cin >> mode >> n >> type;
        if (mode == "<")
            _mode = 0;
        else if (mode == "<=")
            _mode = 1;
        else if (mode == ">")
            _mode = 2;
        else if (mode == ">=")
            _mode = 3;
        if (type == "N")
            _mode = 3 - _mode;

        if (_mode == 0)
        {
            if (n <= min)
            {
                cout << "Impossible\n";
                return 0;
            }
            if (n <= max)
            {
                max = n;
                maxOpen = true;
            }
        }
        else if (_mode == 1)
        {
            if (n < min)
            {
                cout << "Impossible\n";
                return 0;
            }
            if (n < max)
            {
                max = n;
                maxOpen = false;
            }
        }
        else if (_mode == 2)
        {
            if (n >= max)
            {
                cout << "Impossible\n";
                return 0;
            }
            if (n >= min)
            {
                min = n;
                minOpen = true;
            }
        }
        else
        {
            if (n > max)
            {
                cout << "Impossible\n";
                return 0;
            }
            if (n > min)
            {
                min = n;
                minOpen = false;
            }               
        }
    }
    if (max - min > 1)
    {
        cout << min + 1 << "\n";
        return 0;
    }
    if (max - min == 0)
    {
        if (minOpen || maxOpen)
        {
            cout << "Impossible\n";
            return 0;
        }
    }
    if (!minOpen)
    {
        cout << min << "\n";
        return 0;
    }
    if (!maxOpen)
    {
        cout << max << "\n";
        return 0;
    }
    cout << "Impossible\n";
}