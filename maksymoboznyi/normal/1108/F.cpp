#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 2e5 + 5;

struct cell {
    int a, b, c;
};


int n, m, l = 0, ans, used[N], up[N][30], go[N][30], dep[N], par[N], sz[N];
vector<cell> e;
vector<pair<int, int> > g[N];

bool cmp(cell a, cell b) {
    return a.c < b.c;
}

void dfs1(int v, int p = 0, int val = 0) {
    go[v][0] = val;
    up[v][0] = p;
    dep[v] = dep[p] + 1;
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i].first != p)
            dfs1(g[v][i].first, v, g[v][i].second);
}

void precalc() {
    int x = 1;
    while (x < n)
        x *= 2, l++;
    for (int j = 1; j <= l; j++)
        for (int i = 1; i <= n; i++)
            up[i][j] = up[up[i][j - 1]][j - 1], go[i][j] = max(go[i][j - 1], go[up[i][j - 1]][j - 1]);
}

int lca(int u, int v) {
    if (dep[u] < dep[v])
        swap(u, v);
    int ans = 0;
    for (int j = l; j > -1; j--)
        if (dep[u] - (1 << j) >= dep[v])
            ans = max(go[u][j], ans), u = up[u][j];
    if (u == v)
        return ans;
    for (int j = l; j >= 0; j--)
        if (up[u][j] != up[v][j])
            ans = max(ans, max(go[u][j], go[v][j])), u = up[u][j], v = up[v][j];
    ans = max(ans, max(go[u][0], go[v][0]));
    return ans;
}

void calc_lca(int a, int b, int c) {
    ans += (lca(a, b) == c);
}

int find(int v) {
    if (par[v] == v)
        return v;
    return par[v] = find(par[v]);
}

void un(int a, int b, int c, int i) {
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    used[i] = 1;
    if (sz[a] > sz[b])
        swap(a, b);
    par[a] = b;
    sz[b] += sz[a];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e.pb({a, b, c});
    }
    sort(e.begin(), e.end(), cmp);
    for (int i = 1; i <= n; i++)
        par[i] = i, sz[i] = 1;
    for (int i = 0; i < e.size(); i++)
        un(e[i].a, e[i].b, e[i].c, i);
    for (int i = 0; i < e.size(); i++)
        if (used[i])
            g[e[i].a].pb({e[i].b, e[i].c}), g[e[i].b].pb({e[i].a, e[i].c});
    dfs1(1);
    precalc();
    for (int i = 0; i < e.size(); i++)
        if (!used[i])
            calc_lca(e[i].a, e[i].b, e[i].c);
    cout << ans;
    return 0;
}