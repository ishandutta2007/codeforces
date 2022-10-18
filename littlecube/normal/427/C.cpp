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

int n, m, arr[100005], ans, vis[100005], ans2 = 1;
vector<vector<int>> v;
vector<int> e[100005], re[100005], ts;

void dfs1(int k)
{
    vis[k] = 1;
    for (int i : e[k])
        if (!vis[i])
            dfs1(i);
    ts.pb(k);
}

void dfs2(int k)
{
    vis[k] = 0;
    for (int i : re[k])
        if (vis[i])
            dfs2(i);
    v.back().pb(k);
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].pb(y);
        re[y].pb(x);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs1(i);
    reverse(ts.begin(), ts.end());
    for (int i : ts)
        if (vis[i])
        {
            v.pb(vector<int>(0));
            dfs2(i);
        }
    for (auto i : v)
    {
        int res = 1000000000000, cnt = 1;
        //cout << "SCC:";
        for (int j : i)
        {
            //cout << j << " ";
            if (arr[j] < res)
                res = arr[j], cnt = 1;
            else if (arr[j] == res)
                cnt++;
        }
        //cout << '\n';
        ans2 = ans2 * cnt % MOD;
        ans += res;
    }
    cout << ans << " " << ans2;
}