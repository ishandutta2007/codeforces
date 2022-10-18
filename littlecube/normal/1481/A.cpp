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
    int t;
    cin >> t;
    while (t--)
    {
        int x = 0, y = 0, r = 0, u = 0, d = 0, l = 0;
        string s;
        cin >> x >> y;
        cin >> s;
        for (char c : s)
        {
            if (c == 'R')
                r++;
            else if (c == 'U')
                u++;
            else if (c == 'D')
                d++;
            else if (c == 'L')
                l++;
        }
        if (-l <= x && x <= r && -d <= y && y <= u)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}