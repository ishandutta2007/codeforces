#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, u, v, par[N], nim[N];
vector<int> adj[N];

int DFS(int u, int p = 0) {
    par[u] = p;
    for (int v : adj[u]) {
        if (v != p) {
            nim[u] ^= DFS(v, u) + 1;
        }
    }
    return nim[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << (DFS(1) ? 1 : 2);
    for (int i = 2; i <= n; i++) {
        int cnt = 0, lst = 0;
        for (int u = i, cur = 0; par[u] != 0;) {
            cnt ^= 1;
            lst = nim[u] + 1;
            for (int v : adj[u]) {
                if (v != par[u] && par[v] != 0) {
                    par[v] = 1;
                    nim[1] ^= nim[v] + 1;
                }
            }
            int tu = par[u]; par[u] = 0; u = tu;
        }
        nim[1] ^= cnt ^ lst;
        cout << (nim[1] ? 1 : 2);
    }
}