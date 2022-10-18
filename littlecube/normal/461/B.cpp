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

ll n, dp[500005][2], pre[500005], color[500005];
vector<int> e[500005];

void dfs(ll k)
{
    if (color[k])
        dp[k][1] = 1;
    else
        dp[k][0] = 1;
    for (int i : e[k])
        if (pre[k] != i)
        {

            pre[i] = k;
            dfs(i);

            dp[k][1] = (dp[k][0] * dp[i][1] + dp[k][1] * dp[i][0] + dp[k][1] * dp[i][1]) % MOD;
            dp[k][0] = (dp[i][0] * dp[k][0] + dp[k][0] * dp[i][1]) % MOD;
        }
}

signed main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        e[i].pb(x);
        e[x].pb(i);
    }
    for (int i = 0; i < n; i++)
        cin >> color[i];
    dfs(0);
    //for (int i = 0; i < n; i++)
        //cout << i << "  " << dp[i][0] << " " << dp[i][1] << '\n';
    cout << dp[0][1];
}