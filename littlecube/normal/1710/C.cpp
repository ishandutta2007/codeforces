/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
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

string s;

const ll mod = 998244353;
ll dp[200005][8][8];

signed main()
{
    fast;
    cin >> s;
    int i = 0;
    dp[0][0][7] = 1;
    for (char c : s)
    {
        if (c == '0')
        {
            for (short mask = 0; mask < 8; mask++)
            {
                bitset<3> acc = mask;
                acc = (acc << 2) ^ (acc >> 1) ^ acc;
                short cmp = (mask == 0 || mask == 7) ? 0 : (~acc).to_ulong();
                for (short sub = 0; sub < 8; sub++)
                    for (short j = 0; j < 8; j++)
                        if ((sub & mask) == 0)
                            dp[i + 1][j | cmp][sub] = (dp[i + 1][j | cmp][sub] + dp[i][j][sub]) % mod;
            }
        }
        else
        {
            for (short mask = 0; mask < 8; mask++)
            {
                bitset<3> acc = mask;
                acc = (acc << 2) ^ (acc >> 1) ^ acc;
                short cmp = (mask == 0 || mask == 7) ? 0 : (~acc).to_ulong();
                for (short sub = 0; sub < 8; sub++)
                    for (short j = 0; j < 8; j++)
                        dp[i + 1][j | cmp][sub & mask] = (dp[i + 1][j | cmp][sub & mask] + dp[i][j][sub]) % mod;
            }
        }
        i++;
    }
    ll ans = 0;
    for (int j = 0; j < 8; j++)
        ans = (ans + dp[i][7][j]) % mod;
    cout << ans << '\n';
}