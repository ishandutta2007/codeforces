#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, u, v, ans = 0, f[N][2], g[N][2];
vector<int> adj[N];

void DFS(int u, int p = 0) {
    int ch = (int)adj[u].size() - (p != 0);
    f[u][1] = 1;
    f[u][0] = ch;
    for (int &v : adj[u]) {
        if (v != p) {
            DFS(v, u);
            ans = max(ans, f[u][0] - 1 + (p != 0) + max(f[v][0], f[v][1]));
            ans = max(ans, f[u][1] + f[v][0]);
            f[u][0] = max(f[u][0], max(f[v][0], f[v][1]) + ch - 1);
            f[u][1] = max(f[u][1], f[v][0] + 1);
        }
    }
    ans = max(ans, f[u][0]);
    ans = max(ans, f[u][1]);
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
    DFS(1);
    cout << ans;
}