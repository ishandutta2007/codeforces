#include <bits/stdc++.h>
using namespace std;

int n;

string text;

int main()
    {
    cin >> n >> text;
    int tmp = 0;


    for (int i = 0; i < n; i++)
        {
        tmp = 0;
        if (text[i] == '0')
            {
            if (i > 0)
                if (text[i-1] == '1') tmp++;

            if (i < n-1)
                if (text[i+1] == '1') tmp++;

            if (!tmp)
                {
                cout << "No";
                return 0;
                }
            }
        else
            {
            if (i > 0)
                if (text[i-1] == '1') tmp++;

            if (i < n-1)
                if (text[i+1] == '1') tmp++;

            if (tmp)
                {
                cout << "No";
                return 0;
                }
            }
        }
    cout << "Yes";
    return 0;
    }