#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int t, n, m, u, v, sub[N], p[N], cal[N];
vector<int> adj[N];

int DFS_1(int u, int p = 0) {
    for (int v : adj[u]) {
        if (v != p) {
            sub[u] += DFS_1(v, u);
        }
    }
    return sub[u];
}

bool DFS_2(int u, int p = 0) {
    int sum = cal[u];
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (!DFS_2(v, u) || (sum -= cal[v]) < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> sub[i];
            adj[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        DFS_1(1);
        bool chk = true;
        for (int i = 1; i <= n && chk; i++) {
            if ((p[i] + sub[i]) % 2 != 0) {
                chk = false;
            }
            cal[i] = (p[i] + sub[i]) / 2;
            if (cal[i] < 0 || cal[i] > sub[i]) {
                chk = false;
            }
        }
        cout << (chk && DFS_2(1) ? "YES\n" : "NO\n");
    }
}