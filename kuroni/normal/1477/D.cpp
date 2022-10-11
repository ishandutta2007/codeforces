#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int t, n, m, u, v, p[N], q[N];
bool chk[N];
set<int> cur, adj[N];
vector<int> ch[N];

bool DFS(int u, bool rt = false) {
    cur.erase(u);
    int v = 0, z = 0;
    while (true) {
        auto it = cur.lower_bound(v);
        if (it == cur.end()) {
            break;
        }
        v = *it;
        if (adj[u].count(v)) {
            adj[u].erase(v);
        } else {
            // cout << u << " - " << v << '\n';
            z = v;
            if (!DFS(v)) {
                chk[u] = true;
                ch[u].push_back(v);
            }
        }
        v++;
    }
    if (!chk[u] && rt) {
        if (z == 0) {
            chk[u] = true;
        } else {
            ch[z].push_back(u);
        }
    }
    return chk[u];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        cur.insert(i);
        chk[i] = false;
        ch[i].clear();
    }
    while (m--) {
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (int i = 1; i <= n; i++) {
        if (cur.count(i)) {
            DFS(i, true);
        }
    }
    for (int i = 1, cur = 1; i <= n; i++) {
        if (chk[i]) {
            p[i] = cur;
            for (int v : ch[i]) {
                q[v] = cur;
                p[v] = ++cur;
            }
            q[i] = cur++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " \n"[i == n];
    }
    for (int i = 1; i <= n; i++) {
        cout << q[i] << " \n"[i == n];
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