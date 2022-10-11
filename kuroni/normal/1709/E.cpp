#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int>> adj(n);
    vector<set<int>> val(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    function<void(int, int, int)> DFS = [&](int u, int p, int top) {
        bool ok = true;
        top ^= a[u];
        val[u].insert(top);
        for (int v : adj[u]) {
            if (v != p) {
                DFS(v, u, top);
                if (val[u].size() < val[v].size()) {
                    swap(val[u], val[v]);
                }
                for (int x : val[v]) {
                    if (val[u].count(x ^ a[u])) {
                        ok = false;
                    }
                }
                for (int x : val[v]) {
                    val[u].insert(x);
                }
            }
        }
        if (!ok) {
            val[u].clear();
            ans++;
        }
    };
    DFS(0, -1, 0);
    cout << ans;
}