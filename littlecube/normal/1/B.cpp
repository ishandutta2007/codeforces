#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        ll state = 2, type = 0, row = 0, column = 0;

        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            if ((int)s[i] <= 57 && state != 0)
            {
                state = 0;
                type++;
            }
            if ((int)s[i] >= 65 && state != 1)
            {
                state = 1;
                type++;
            }
        }

        if (type == 2)
        {
            int i = 0;
            for (; i < s.length(); i++)
            {
                if ((int)s[i] <= 57)
                {
                    row = row * 10 + (int)s[i] - 48;
                }
                if ((int)s[i] >= 65)
                {
                    column = column * 26 + (int)s[i] - 64;
                }
            }
            cout << "R" << row << "C" << column << '\n';
        }
        else
        {
            int i = 1;
            string column_a;
            for (; i < s.length(); i++)
            {
                if ((int)s[i] <= 57)
                {
                    row = row * 10 + (int)s[i] - 48;
                }
                if ((int)s[i] >= 65)
                {
                    break;
                }
            }
            i++;
            for (; i < s.length(); i++)
            {
                if ((int)s[i] <= 57)
                {
                    column = column * 10 + (int)s[i] - 48;
                }
            }
            while (column > 0)
            {
                if (column % 26 == 0)
                {
                    column_a = "Z" + column_a;
                    column = column / 26 - 1;
                }
                else
                {
                    column_a = (char)(column % 26 + 64) + column_a;
                    column /= 26;
                }
            }
            cout << column_a << row << '\n';
        }
    }
}