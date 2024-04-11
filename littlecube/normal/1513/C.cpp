/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<int> p[200005];
int t;
signed main()
{
    fast;

    p[1] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 2};
    for (int i = 2; i <= 200005; i++)
    {
        p[i] = vector<int>(10, 0);
        for (int a = 0; a < 9; a++)
            p[i][a] = p[i - 1][a + 1];
        p[i][9] = (p[i - 1][0] + p[i - 1][1]) % MOD;

    }
    cin >> t;
    while (t--)
    {
        string s;
        int k, ans = 0;
        cin >> s >> k;
        for (int i = 0; i < s.length(); i++)
            ans = (ans  + p[k][s[i] - '0']) % MOD;

        cout << ans << '\n';
    }
}