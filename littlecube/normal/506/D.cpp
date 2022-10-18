/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma loop_opt(on)
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
//using namespace __gnu_pbds;

const int b = 505;
int n, m, q, dsu[205][100005], rk[205][100005], islarge[100005], lcnt;
vector<pii> E[100005];
vector<int> V[100005];
vector<ll> cc[100005];
map<int, int> ans[100005];

int find(int idx, int k)
{
    return dsu[idx][k] == k ? k : dsu[idx][k] = find(idx, dsu[idx][k]);
}

void merge(int idx, int x, int y)
{
    if (x == y)
        return;
    if (rk[idx][x] <= rk[idx][y])
    {
        dsu[idx][x] = y;
        rk[idx][y] += rk[idx][x];
    }
    else
        merge(idx, y, x);
}

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 0; i <= 200; i++)
        for (int j = 1; j <= n; j++)
            dsu[i][j] = j, rk[i][j] = 1;

    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        E[c].emplace_back(pii{u, v});
        V[c].emplace_back(u);
        V[c].emplace_back(v);
    }
    for (int i = 1; i <= m; i++)
    {
        if (E[i].size() >= b)
            islarge[i] = ++lcnt;
        sort(V[i].begin(), V[i].end());
        V[i].resize(unique(V[i].begin(), V[i].end()) - V[i].begin());
        if (islarge[i])
            for (auto [u, v] : E[i])
                merge(islarge[i], find(islarge[i], u), find(islarge[i], v));
        else
        {
            for (auto [u, v] : E[i])
                merge(0, find(0, u), find(0, v));
            for (int u : V[i])
                cc[u].emplace_back((ll)i * m + (ll)find(0, u));
            for (int u : V[i])
                dsu[0][u] = u, rk[0][u] = 1;
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        if (make_pair(cc[u].size(), u) > make_pair(cc[v].size(), v))
            swap(u, v);
        if (!ans[u][v])
        {
            int cnt = 0;
            for (int j = 1; j <= lcnt; j++)
                if (find(j, u) == find(j, v))
                    cnt++;
            for (ll c : cc[u])
                if (upper_bound(cc[v].begin(), cc[v].end(), c) - lower_bound(cc[v].begin(), cc[v].end(), c) > 0)
                    cnt++;
            ans[u][v] = cnt + 1e8;
        }
        cout << ans[u][v] - 1e8 << '\n';
    }
}