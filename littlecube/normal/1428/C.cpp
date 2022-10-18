#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string s;

        cin >> s;
        int result = s.length();
        int i = 0, A = 0, B = 0;
        for (; i < s.length(); i++)
        {
            if (s[i] == 'A')
                A++;
            else if (s[i] == 'B' && A == 0)
            {
                if (B)
                {
                    B--;
                    result -= 2;
                }
                else
                    B++;
            }
            else
            {
                result -= 2;
                A--;
            }
        }
        cout << result << '\n';
    }
}