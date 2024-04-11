#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m, u, v, w, lef;
long long rem, ans = 0;
set<int> ava;
vector<int> adj[N];
vector<array<int, 3>> ed;

struct dsu {
    int par[N];

    void init() {
        fill(par + 1, par + n + 1, -1);
    }

    int trace(int u) {
        return par[u] < 0 ? u : par[u] = trace(par[u]);
    }
    
    bool connect(int u, int v) {
        if ((u = trace(u)) == (v = trace(v))) {
            return false;
        }
        if (par[u] > par[v]) {
            swap(u, v);
        }
        par[u] += par[v];
        par[v] = u;
        return true;
    }
} all, ori;

void DFS(int u) {
    ava.erase(u);
    sort(adj[u].begin(), adj[u].end());
    for (int v = 0;;) {
        auto it = ava.lower_bound(v);
        if (it == ava.end()) {
            return;
        }
        v = *it;
        if (!binary_search(adj[u].begin(), adj[u].end(), v)) {
            all.connect(u, v);
            DFS(v);
            rem--;
        }
        v++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    rem = 1LL * n * (n - 1) / 2 - m;
    for (int i = 1; i <= n; i++) {
        ava.insert(i);
    }
    all.init(); ori.init();
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        lef ^= w;
        ed.push_back({w, u, v});
    }
    for (int i = 1; i <= n; i++) {
        if (ava.count(i)) {
            DFS(i);
        }
    }
    if (rem > 0) {
        lef = 0;
    }
    sort(ed.begin(), ed.end());
    for (auto [w, u, v] : ed) {
        if (all.connect(u, v)) {
            ans += w;
            ori.connect(u, v);
        } else if (ori.connect(u, v)) {
            lef = min(lef, w);
        }
    }
    cout << ans + lef << '\n';
}