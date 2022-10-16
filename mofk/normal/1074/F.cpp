#include <bits/stdc++.h>

using namespace std;

int n, q;
vector <int> adj[200005];
int h[200005];
int dad[200005][20];
int b[200005], e[200005], _time;
set <pair <int, int> > extra;

void dfs(int u) {
    b[u] = ++_time;
    for (auto v: adj[u]) {
        if (v == dad[u][0]) continue;
        dad[v][0] = u;
        h[v] = h[u] + 1;
        dfs(v);
    }
    e[u] = _time;
}
int near_lca(int u, int v) {
    if (h[u] > h[v]) swap(u, v);
    for (int j = 18; j >= 0; --j) if (h[v] - (1 << j) > h[u]) v = dad[v][j];
    return v;
}

int len[2000005], cnt[2000005];
void update(int node, int l, int r, int u, int v, int type) {
    if (l > v || r < u || u > v) return;
    if (u <= l && r <= v) {
        cnt[node] += type;
        if (type == 1) len[node] = r - l + 1;
        else if (cnt[node] == 0) len[node] = len[node * 2] + len[node * 2 + 1];
        return;
    }
    int m = l + r >> 1;
    update(node * 2, l, m, u, v, type);
    update(node * 2 + 1, m + 1, r, u, v, type);
    if (cnt[node] == 0) len[node] = len[node * 2] + len[node * 2 + 1];
}

void add(int u, int v, int type) {
    if (type == 1) extra.insert(make_pair(u, v));
    else extra.erase(make_pair(u, v));
    if (h[u] > h[v]) swap(u, v);
    if (b[u] < b[v] && e[v] <= e[u]) {
        int p = near_lca(u, v);
        update(1, 1, n, b[p], b[v] - 1, type);
        update(1, 1, n, e[v] + 1, e[p], type);
    }
    else {
        if (b[u] > b[v]) swap(u, v);
        update(1, 1, n, 1, b[u] - 1, type);
        update(1, 1, n, e[u] + 1, b[v] - 1, type);
        update(1, 1, n, e[v] + 1, n, type);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for (int j = 1; j < 19; ++j) for (int i = 1; i <= n; ++i) dad[i][j] = dad[dad[i][j-1]][j-1];
    while (q--) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        if (extra.find(make_pair(u, v)) != extra.end()) add(u, v, -1);
        else add(u, v, 1);
        cout << n - len[1] << '\n';
    }
    return 0;
}