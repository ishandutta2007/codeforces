#include <bits/stdc++.h>

using namespace std;

int n, k;
vector <int> adj[100005];
int dad[100005];
int h[100005];

void dfs(int u) {
    for (auto v: adj[u]) {
        if (v == dad[u]) continue;
        dad[v] = u;
        h[v] = h[u] + 1;
        dfs(v);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) if (adj[i].size() == 1) {
        dfs(i);
        break;
    }
    int id = max_element(h + 1, h + n + 1) - h;
    if (h[id] != k + k) return cout << "No" << endl, 0;
    while (h[id] != k) id = dad[id];
    if (adj[id].size() < 3) return cout << "No" << endl, 0;
    memset(dad, 0, sizeof dad);
    memset(h, 0, sizeof h);
    dfs(id);
    for (int i = 1; i <= n; ++i) if (i != id) {
        if (adj[i].size() == 1) {
            if (h[i] != k) return cout << "No" << endl, 0;
        }
        else if (adj[i].size() < 4) return cout << "No" << endl, 0;
    }
    cout << "Yes" << endl;
    return 0;
}