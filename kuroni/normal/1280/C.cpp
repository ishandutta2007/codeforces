#include <bits/stdc++.h>
using namespace std;

const int N = 2E5 + 5;

int n, t, u[N], v[N], w[N], pr[N], sub[N];
vector<int> adj[N];

int DFS(int u, int p = 0) {
    pr[u] = p;
    for (int &v : adj[u]) {
        if (v != p) {
            sub[u] += DFS(v, u);
        }
    }
    return ++sub[u];
}

void solve() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        adj[i].clear();
        sub[i] = 0;
    }
    for (int i = 1; i < 2 * n; i++) {
        cin >> u[i] >> v[i] >> w[i];
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    DFS(1);
    long long g = 0, b = 0;
    for (int i = 1; i < 2 * n; i++) {
        if (pr[u[i]] != v[i]) {
            swap(u[i], v[i]);
        }
        if (sub[u[i]] % 2 == 1) {
            g += w[i];
        }
        b += 1LL * min(sub[u[i]], 2 * n - sub[u[i]]) * w[i];
    }
    cout << g << " " << b << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}