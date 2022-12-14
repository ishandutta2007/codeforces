#include <bits/stdc++.h>
using namespace std;

const int MAX = 500001;

int mp;

string text;

int main()
    {
    cin >> mp >> text;

    int sum = 0;
    int j = 0;


    for (size_t i = 0; i < text.size(); i++)
        {
        if (text[i] == 'x')
            {
            if (j == 2) sum++;
            else j++;
            }
        else j = 0;
        }



    cout << sum << endl;

    return 0;
    }