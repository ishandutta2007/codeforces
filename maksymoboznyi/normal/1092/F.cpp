#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 2e5 + 5;

int n, a[N], suma[N], f[N], f2[N];
vector<int> g[N];

void dfs1(int v, int p = -1) {
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i] != p) {
            dfs1(g[v][i], v);
            suma[v] += suma[g[v][i]];
            f[v] += f[g[v][i]] + suma[g[v][i]];
        }
    suma[v] += a[v];
}

void dfs2(int v, int p, int sa, int ff) {
    f2[v] = f[v] + sa + ff;
    ff += sa + f[v];
    sa += suma[v];
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i] != p)
            dfs2(g[v][i], v, sa - suma[g[v][i]], ff - f[g[v][i]] - suma[g[v][i]]);
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs1(1);
    dfs2(1, 0, 0, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f2[i]);
    cout << ans;
    return 0;
}