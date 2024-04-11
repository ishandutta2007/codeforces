#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 5;

int n, u, v, mx = 0;
vector<int> adj[N];
vector<pair<int, int>> ans;

void DFS(int u, int t, int p = 0) {
    int st = t - 1, ch = adj[u].size() - 1;
    ans.push_back({u, t});
    for (int &v : adj[u]) {
        if (v != p) {
            if (t == mx && p != 0) {
                ans.push_back({u, t = st - ch});
            }
            DFS(v, ++t, u);
            ans.push_back({u, t});
            ch--;
        }
    }
    if (t > st && p > 0) {
        ans.push_back({u, st});
    }
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
    for (int i = 1; i <= n; i++) {
        mx = max(mx, (int)adj[i].size());
    }
    DFS(1, 0);
    cout << ans.size() << '\n';
    for (auto [u, t] : ans) {
        cout << u << " " << t << '\n';
    }
}