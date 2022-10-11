#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, q, u, v, k, l, r, cnt = 0, in[N], out[N], par[N];
vector<int> adj[N];

void DFS(int u, int p = 0) {
    par[u] = p;
    in[u] = ++cnt;
    for (int &v : adj[u]) {
        if (v != p) {
            DFS(v, u);
        }
    }
    out[u] = cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    while (q--) {
        l = 1, r = n;
        cin >> k;
        while (k--) {
            cin >> u;
            if (u != 1) {
                u = par[u];
            }
            l = max(l, in[u]);
            r = min(r, out[u]);
        }
        cout << (l <= r ? "YES\n" : "NO\n");
    }
}