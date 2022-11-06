#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;

const int N = 3e5 + 5;

int n, m, k;
int is[N], c[N], w[N], br[N], fup[N], tin[N], id[N], c1[N], kol[N], dp[N];
int tt = 0;
int ans[N];
vector<pair<int, int> > g[N], g1[N];

///bridges
void dfs_br(int v, int p) {
    tt++;
    fup[v] = tin[v] = tt;
    for (auto [u, id]: g[v])
        if (u != p)
            if (tin[u] != 0)
                fup[v] = min(fup[v], tin[u]);
            else {
                dfs_br(u, v);
                if (fup[u] > tin[v])
                    br[id] = 1;
                fup[v] = min(fup[v], fup[u]);
            }
}

///compress
void dfs_comp(int v) {
    id[v] = tt;
    c1[tt] += c[v];
    kol[tt] += is[v];

    for (auto [u, i]: g[v])
        if (!br[i] && !id[u])
            dfs_comp(u);
}

int f(int u, int v, int id) {
    if (kol[u] == 0 || kol[u] == k) {
        return dp[u];
    }
    return max(0ll, dp[u] - w[id]);
}

///first time dp
void dfs_dp(int v, int p) {
    for (auto [u, id]: g1[v])
        if (u != p)
            dfs_dp(u, v), kol[v] += kol[u];
    dp[v] = c1[v];
    for (auto [u, id]: g1[v])
        if (u != p)
            dp[v] += f(u, v, id);
}

void dfs_ans(int v, int p) {
    ans[v] = dp[v];
    for (auto [u, id]: g1[v])
        if (u != p) {
            dp[v] -= f(u, v, id);

            kol[v] -= kol[u];
            kol[u] += kol[v];

            dp[u] += f(v, u, id);

            dfs_ans(u, v);

            dp[u] -= f(v, u, id);
            kol[u] -= kol[v];
            kol[v] += kol[u];
            dp[v] += f(u, v, id);
        }
}

signed main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        is[x] = 1;
    }
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb({b, i});
        g[b].pb({a, i});
    }
    dfs_br(1, 0);

    tt = 0;
    for (int i = 1; i <= n; i++)
        if (id[i] == 0) {
            tt++;
            dfs_comp(i);
        }
    for (int v = 1; v <= n; v++)
        for (auto [u, i]: g[v])
            if (br[i])
                g1[id[v]].pb({id[u], i});

    dfs_dp(1, 0);
    dfs_ans(1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[id[i]] << ' ';
    return 0;
}