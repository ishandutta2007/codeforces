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

int n, m, in[100005], out[100005], pre[100005][21], dis[100005], dp[100005], ans[100005], t, x, y;
vector<pii> e[100005];
void dfs(int k)
{
    in[k] = ++t;
    for (pii i : e[k])
        if (pre[k][0] != i.F)
        {
            pre[i.F][0] = k;
            dis[i.F] = dis[k] + 1;
            for (int j = 1; j <= 20; j++)
                pre[i.F][j] = pre[pre[i.F][j - 1]][j - 1];
            dfs(i.F);
        }
    out[k] = ++t;
}
void dfs2(int k)
{
    for (pii i : e[k])
        if (pre[k][0] != i.F)
        {
            dfs2(i.F);
            dp[k] += dp[i.F];
            ans[i.S] = dp[i.F];
        }
}

signed main()
{
    //fast;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        e[x].pb((pii{y, i}));
        e[y].pb((pii{x, i}));
    }
    dfs(1);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        dp[x]++;
        dp[y]++;
        for (int j = 20; j >= 0; j--)
        {
            if (pre[x][j] == 0)
                continue;
            if (!(in[pre[x][j]] <= in[y] && out[y] <= out[pre[x][j]]))
                x = pre[x][j];
        }
        if(!(in[x] <= in[y] && out[y] <= out[x]))
            x = pre[x][0];
        dp[x]-=2;
    }
    dfs2(1);
    for (int i = 1; i < n; i++)
        cout << ans[i] << " ";
}