#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5;

int t, n, m, u, v, cnt = 0, num[N], low[N];
bool fl, cat[N];
vector<int> ve, ans[2], adj[N];

void DFS(int u) {
    num[u] = low[u] = ++cnt;
    ve.push_back(u);
    for (int &v : adj[u]) {
        if (num[v] == 0) {
            DFS(v);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u] && !fl) {
        fl = true;
        while (cat[u]) {
            cat[ve.back()] = false;
            ve.pop_back();
        }
    }
}

void solve() {
    cin >> n >> m;
    ve.clear(); ans[0].clear(); ans[1].clear();
    fl = false;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        cat[i] = true;
        num[i] = low[i] = 0;
    }
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    DFS(1);
    for (int i = 1; i <= n; i++) {
        ans[cat[i]].push_back(i);
    }
    if (ans[0].empty() || ans[1].empty()) {
        cout << "No\n";
    } else {
        cout << "Yes\n" << ans[0].size() << " " << ans[1].size() << '\n';
        for (int i = 0; i < 2; i++, cout << '\n') {
            for (int &v : ans[i]) {
                cout << v << " ";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}