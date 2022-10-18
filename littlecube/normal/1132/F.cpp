/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
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

int n, dp[505][505];
string s;
int DP(int l, int r)
{
    if (r == l)
        return 1;
    if (r < l)
        return 0;
    if (dp[l][r] == 0)
    {
        dp[l][r] = min({DP(l + 1, r), DP(l, r - 1)}) + (s[l] != s[r]);
        for (int i = l; i < r; i++)
            dp[l][r] = min(dp[l][r], DP(l, i) + DP(i + 1, r));
    }
    return dp[l][r];
}

signed main()
{
    cin >> n >> s;
    cout << DP(0, n - 1);
}