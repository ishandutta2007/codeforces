/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define pii128 pair<__int128, __int128>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

int n, q, t = -1, pre[100005][20], dis[100005], v[100005], p[100005], order[100005], bit[100005], ans[100005];
pii io[100005];
vector<int> dis_bucket[100005], E[100005];

void modify(int idx, int val)
{
    for (int i = idx; i <= n; i += (i & -i))
        bit[i] += val;
}

int query(int idx)
{
    int ans = 0;
    for (int i = idx; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

void dfs(int k)
{
    io[k].F = ++t;
    for (int i : E[k])
    {
        dis[i] = dis[k] + 1;
        dfs(i);
    }
    dis_bucket[dis[k]].emplace_back(k);
    io[k].S = t;
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> pre[i][0];
        E[pre[i][0]].emplace_back(i);
    }
    dfs(0);
    for (int p = 1; p < 20; p++)
        for (int i = 1; i <= n; i++)
            pre[i][p] = pre[pre[i][p - 1]][p - 1];
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> v[i] >> p[i];
        order[i] = i;
    }
    sort(order + 1, order + 1 + q, [&](int i, int j)
         { return dis[v[i]] < dis[v[j]]; });
    int odx = 1; 
    for (int i = 1; i <= n; i++)
    {
        for (int j : dis_bucket[i])
            modify(io[j].F, 1);
        while (odx <= q && dis[v[order[odx]]] == i)
        {
            int anc = v[order[odx]], d = p[order[odx]];
            for (int p = 19; p >= 0; p--)
                if (d >= (1 << p))
                    anc = pre[anc][p], d -= (1 << p);
            if (anc == 0)
                ans[order[odx]] = 0;
            else
                ans[order[odx]] = query(io[anc].S) - query(io[anc].F - 1) - 1;
            odx++;
        }
        for (int j : dis_bucket[i])
            modify(io[j].F, -1);
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << " \n"[i == q];
}