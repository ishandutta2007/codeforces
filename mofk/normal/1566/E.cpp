#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[200005];
int dad[200005];
bool leaf[200005], bud[200005];
int cnt[200005];

void dfs(int u) {
    if (u != 1) {
        leaf[u] = true;
        bud[u] = true;
    }
    for (auto v: adj[u]) {
        if (v == dad[u]) continue;
        dad[v] = u;
        dfs(v);
        if (!leaf[v] && !bud[v]) leaf[u] = bud[u] = false;
        if (leaf[v]) ++cnt[u];
    }
    if (cnt[u]) leaf[u] = false;
    if (leaf[u]) bud[u] = false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) adj[i].clear();
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i) dad[i] = cnt[i] = 0, leaf[i] = bud[i] = false;

        dfs(1);
        int leaves = 0, buds = 0;
        //for (int i = 2; i <= n; ++i) cout << leaf[i] << ' '; cout << '\n';
        //for (int i = 2; i <= n; ++i) cout << bud[i] << ' '; cout << '\n';
        for (int i = 2; i <= n; ++i) leaves += leaf[i], buds += bud[i];
        int odd_leaf = 0;
        for (auto u: adj[1]) if (leaf[u]) odd_leaf = 1;
        cout << leaves - buds + 1 - odd_leaf << '\n';
    }
    return 0;
}