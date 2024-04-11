#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        bool b[110][110] = {{0}};
        string s;
        cin >> s;
        b[0][0] = 1;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j <= s.length(); j++)
            {
                if (s[i] == '(' || s[i] == '?')
                {
                    b[i + 1][j + 1] = max(b[i][j], b[i + 1][j + 1]);
                }
                if ((s[i] == ')' || s[i] == '?') && j != 0)
                {
                    b[i + 1][j - 1] = max(b[i][j],b[i + 1][j - 1]);
                }
            }
        }

        if (b[s.length()][0])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}