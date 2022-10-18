/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

signed main()
{
    fast;
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        s += 'W';
        bool acc[2] = {};
        for (char c : s)
        {
            if(c == 'W')
            {
                if(acc[0] ^ acc[1])
                {
                    cout << "NO\n";
                    goto de;
                }
                acc[0] = acc[1] = 0;
            }
            else
                acc[(c == 'B' ? 0 : 1)] = 1;
        }
        cout << "YES\n";
    de:
#define littlecubeisdian false
        if (littlecubeisdian)
            cout << "I weak\n";
    }
}