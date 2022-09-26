#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int n, m, u, v, w, it, vis[N], mat[N];
vector<int> adj[N];
vector<array<int, 3>> ve;

bool DFS(int u) {
    vis[u] = it;
    for (int v : adj[u]) {
        if (mat[v] == 0) {
            mat[v] = u;
            return true;
        }
    }
    for (int v : adj[u]) {
        if (vis[mat[v]] < it && DFS(mat[v])) {
            mat[v] = u;
            return true;
        }
    }
    return false;
}

bool solve(int u) {
    it = 0;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        vis[i] = -1;
        mat[i] = 0;
    }
    for (int i = 0; i <= u; i++) {
        adj[ve[i][1]].push_back(ve[i][2]);
    }
    for (int i = 1; i <= n; i++) {
        if (DFS(i) && ++it == n) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        ve.push_back({w, u, v});
    }
    sort(ve.begin(), ve.end());
    int l = 0, r = ve.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (solve(m)) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << (l == ve.size() ? -1 : ve[l][0]);
}