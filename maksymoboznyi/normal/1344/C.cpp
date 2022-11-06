#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 2e5 + 3;

int used[N], is = 0, n, m, ans[N], kol = 0, down[N], up[N];
vector<int> g[N], c, gt[N];

void dfs(int v) {
    used[v] = 1;
    for (auto u: g[v])
        if (used[u] == 1)
            is = 1;
        else
            if (used[u] != 2)
                dfs(u);
    used[v] = 2;
    c.pb(v);
}

int pos[N];

void dfs2(int v) {
    used[v] = 1;
    down[v] = v;
    for (auto u: g[v])
        if (used[u])
            down[v] = min(down[v], down[u]);
        else
            dfs2(u), down[v] = min(down[v], down[u]);
}


void dfs3(int v) {
    used[v] = 1;
    up[v] = v;
    for (auto u: gt[v])
        if (used[u])
            up[v] = min(up[v], up[u]);
        else
            dfs3(u), up[v] = min(up[v], up[u]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[b].pb(a);
        gt[a].pb(b);
    }
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs(i);
    if (is) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        used[i] = 0;
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs2(i);
    for (int i = 1; i <= n; i++)
        used[i] = 0;
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs3(i);

    int kol = 0;
    for (int i = 1; i <= n; i++)
        if (min(up[i], down[i]) == i)
            kol++, ans[i] = 1;
    cout << kol << "\n";
    for (int i = 1; i <= n; i++)
        cout << (ans[i] ? 'A': 'E');

    return 0;
}