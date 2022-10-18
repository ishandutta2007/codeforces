#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{

    fast;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            if (i % 2 == 0)
            {
                if (s[i] == 'a')
                    s[i] = 'b';
                else
                    s[i] = 'a';
            }
            else
            {
                if (s[i] == 'z')
                    s[i] = 'y';
                else
                    s[i] = 'z';
            }
        }
        cout << s << '\n';
    }
}