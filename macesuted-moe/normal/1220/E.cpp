#include <bits/stdc++.h>
using namespace std;

#define int long long

#define maxn 200005
#define mod 1000000007

bool mem1;

vector<vector<int>> graph, tree;

int a[maxn], dfn[maxn], low[maxn], root[maxn], f[maxn], g[maxn], siz[maxn];
bool vis[maxn];

stack<int> S;

int tim = 0;
void tarjan(int p, int fa = -1) {
    dfn[p] = low[p] = ++tim;
    S.push(p);
    for (auto i : graph[p])
        if (!dfn[i])
            tarjan(i, p), low[p] = min(low[p], low[i]);
        else if (i != fa)
            low[p] = min(low[p], dfn[i]);
    if (low[p] == dfn[p]) {
        while (S.top() != p) root[S.top()] = p, S.pop();
        root[p] = p, S.pop();
    }
    return;
}
void dfs(int p) {
    vis[p] = true;
    for (auto i : tree[p])
        if (!vis[i]) dfs(i), f[p] = max(f[p], f[i] - g[i]), g[p] += g[i], siz[p] = max(siz[p], siz[i]);
    f[p] += g[p];
    f[p] += a[p], g[p] += a[p];
    if (siz[p] == 1) g[p] = 0;
    return;
}

void solve(void) {
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1), tree.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y), graph[y].push_back(x);
    }
    int S;
    cin >> S;
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i);
    // for (int i = 1; i <= n; i++) cerr << root[i] << ' ';
    // cerr << endl;
    for (int i = 1; i <= n; i++)
        for (auto j : graph[i])
            if (root[i] != root[j])
                tree[root[i]].push_back(root[j]);
    for (int i = 1; i <= n; i++)
        if (root[i] != i) a[root[i]] += a[i];
    for (int i = 1; i <= n; i++) siz[root[i]]++;
    dfs(root[S]);
    cout << f[root[S]] << endl;
    // for (int i = 1; i <= n; i++)
    //     if (root[i] == i) cerr << i << ' ' << f[i] << ' ' << g[i] << endl;
    // cerr << endl;
    return;
}

bool mem2;

signed main() {
#ifdef MACESUTED
    cerr << "Memory: " << abs(&mem1 - &mem2) / 1024. / 1024. << "MB" << endl;
#endif

    int _ = 1;
    while (_--) solve();

#ifdef MACESUTED
    cerr << "Time: " << clock() * 1000. / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}