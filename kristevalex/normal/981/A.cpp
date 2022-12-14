#include <bits/stdc++.h>
using namespace std;



string text;


int main()
    {

    cin >> text;
    int SIZE = text.size();


    for (int i = 0; i < (SIZE+1)/2; i++)
        {
        if (text[i] != text[SIZE - i - 1])
            {
            cout << SIZE;
            return 0;
            }
        }

    char letter = text[0];

    for (int i = 0; i < SIZE; i++)
        {
        if (letter != text[i])
            {
            cout << SIZE-1;
            return 0;
            }
        }

    cout << 0;



    return 0;
    }