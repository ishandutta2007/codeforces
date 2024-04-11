#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, x, y, u, v, te, f[N][3], g[N], h[N], col[N];
bool chk[N];
vector<int> pat, pre, suf, adj[N];

void init() {
    pat.clear(); pre.clear(); suf.clear();
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        f[i][0] = f[i][1] = f[i][2] = g[i] = h[i] = 0;
        col[i] = -1;
        chk[i] = false;
        adj[i].clear();
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool find_path(int u, int p = 0) {
    pat.push_back(u);
    if (u == y) {
        return true;
    }
    for (int v : adj[u]) {
        if (v != p && find_path(v, u)) {
            return true;
        }
    }
    pat.pop_back();
    return false;
}

int init_subtree(int u, int c, int p = 0) {
    col[u] = c;
    h[u] = -1;
    for (int v : adj[u]) {
        if (v != p && col[v] == -1) {
            h[u] = max(h[u], init_subtree(v, c, u));
        }
    }
    return ++h[u];
}

int DFS_1(int u, int p = 0) {
    for (int v : adj[u]) {
        if (v != p) {
            int tmp = DFS_1(v, u) + 1;
            for (int i = 0; i < 3; i++) {
                if (tmp > f[u][i]) {
                    swap(tmp, f[u][i]);
                }
            }
        }
    }
    return f[u][0];
}

void DFS_2(int u, int p = 0) {
    for (int v : adj[u]) {
        if (v != p) {
            g[v] = max(g[u], f[v][0] + 1 == f[u][0] ? f[u][1] : f[u][0]) + 1;
            DFS_2(v, u);
        }
    }
}

bool solve() {
    find_path(x);
    int m = pat.size();
    pre = suf = vector<int>(m);
    for (int v : pat) {
        col[v] = 0;
    }
    for (int i = 0; i < m; i++) {
        int tmp = init_subtree(pat[i], i);
        pre[i] = tmp - i;
        suf[i] = tmp + i;
    }
    for (int i = 1; i < m; i++) {
        pre[i] = max(pre[i], pre[i - 1]);
    }
    for (int i = m - 2; i >= 0; i--) {
        suf[i] = max(suf[i], suf[i + 1]);
    }
    int le = 0, ri = m - 1;
    bool upd = true;
    while (upd) {
        upd = false;
        int ml = m - 1 - min(m - 1, pre[le]), mr = min(m - 1, suf[ri] - (m - 1));
        if (ml < ri) {
            ri = ml;
            upd = true;
        }
        if (mr > le) {
            le = mr;
            upd = true;
        }
    }
    DFS_1(1);
    DFS_2(1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            if (g[i] > f[i][j]) {
                swap(g[i], f[i][j]);
            }
        }
        if (f[i][2] >= m - 1 && (col[i] <= le || col[i] >= ri)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> te;
    while (te--) {
        init();
        cout << (solve() ? "YES\n" : "NO\n");
    }
}