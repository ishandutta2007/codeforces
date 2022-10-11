#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;

const int N = 200005, M = 2E6 + 5, DX[4] = {0, 1, 0, -1}, DY[4] = {1, 0, -1, 0};

int te, n, m, a[N], aw[N];
char ad[N];

struct flow_demands {
    vector<pair<int, int>> adj[N];
    int s, t, n, cnt, dem[N], cap[M];
    int sum, lv[N], ptr[N];

    void init(int _n) {
        s = 0; t = 1; n = _n; cnt = 0; sum = 0;
        for (int i = 0; i <= n + 4; i++) {
            adj[i].clear();
            dem[i] = 0;
        }
    }

    // add an edge from u to v with capacity c and demand d
    void add_edge(int u, int v, int d, int c) {
        adj[u].push_back({v, cnt});
        dem[u] += d; cap[cnt++] = c - d;
        adj[v].push_back({u, cnt});
        dem[v] -= d; cap[cnt++] = 0;
    }

    void normalize() {
        add_edge(t, s, 0, N);
        s = n + 2; t = n + 3;
        for (int i = 0; i < s; i++) {
            if (dem[i] > 0) {
                add_edge(i, t, 0, dem[i]);
                sum += dem[i];
            } else if (dem[i] < 0) {
                add_edge(s, i, 0, -dem[i]);
            }
        }
    }

    bool BFS(int lim) {
        fill(lv, lv + t + 1, -1);
        queue<int> q;
        for (lv[s] = 0, q.push(s); !q.empty(); q.pop()) {
            int u = q.front();
            for (auto [v, ind] : adj[u]) {
                if (lv[v] == -1 && cap[ind] >= lim) {
                    lv[v] = lv[u] + 1;
                    q.push(v);
                }
            }
        }
        return lv[t] != -1;
    }

    int DFS(int u, int p) {
        if (u == t || p == 0) {
            return p;
        }
        for (; ptr[u] < adj[u].size(); ptr[u]++) {
            auto [v, ind] = adj[u][ptr[u]];
            if (lv[v] != lv[u] + 1) {
                continue;
            }
            if (int np = DFS(v, min(p, cap[ind]))) {
                cap[ind] -= np;
                cap[ind ^ 1] += np;
                return np;
            }
        }
        return 0;
    }

    int flow() {
        int ans = 0;
        for (int i = 17; i >= 0; i--) {
            while (BFS(1 << i)) {
                fill(ptr, ptr + t + 1, 0);
                while (int f = DFS(s, N)) {
                    ans += f;
                }
            }
        }
        return ans;
    }
} fl;

int index(int i, int j) {
    return (i - 1) * n + j;
}

pair<int, int> convert(int ind) {
    return {(ind - 1) / n + 1, (ind - 1) % n + 1};
}

char direction(int sx, int sy, int tx, int ty) {
    if (sx == tx) {
        return sy < ty ? 'R' : 'L';
    } else if (sx < tx) {
        return 'D';
    } else {
        return 'U';
    }
}

void solve() {
    cin >> m >> n;
    fl.init(m * n);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[index(i, j)];
        }
    }
    for (int sx = 1; sx <= m; sx++) {
        for (int sy = 1; sy <= n; sy++) {
            bool chk = true, le = (sx + sy) % 2;
            for (int k = 0; k < 4; k++) {
                int tx = sx + DX[k], ty = sy + DY[k];
                if (tx == 0 || tx > m || ty == 0 || ty > n) {
                    continue;
                }
                if (a[index(sx, sy)] == a[index(tx, ty)] && le) {
                    fl.add_edge(index(sx, sy) + 1, index(tx, ty) + 1, 0, 1);
                } else if (a[index(sx, sy)] > a[index(tx, ty)]) {
                    chk = false;
                    aw[index(sx, sy)] = a[index(sx, sy)] - a[index(tx, ty)];
                    ad[index(sx, sy)] = direction(sx, sy, tx, ty);
                }
            }
            if (le) {
                fl.add_edge(0, index(sx, sy) + 1, chk, 1);
            } else {
                fl.add_edge(index(sx, sy) + 1, 1, chk, 1);
            }
        }
    }
    fl.normalize();
    if (fl.flow() == fl.sum) {
        cout << "YES\n";
        for (int sx = 1; sx <= m; sx++) {
            for (int sy = 1; sy <= n; sy++) {
                if ((sx + sy) % 2) {
                    for (auto [v, ind] : fl.adj[index(sx, sy) + 1]) {
                        if (v - 1 >= 1 && v - 1 <= m * n && fl.cap[ind] == 0) {
                            auto [tx, ty] = convert(v - 1);
                            aw[index(sx, sy)] = 1;
                            ad[index(sx, sy)] = direction(sx, sy, tx, ty);
                            aw[index(tx, ty)] = a[index(sx, sy)] - 1;
                            ad[index(tx, ty)] = direction(tx, ty, sx, sy);
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cout << aw[index(i, j)] << " \n"[j == n];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cout << ad[index(i, j)] << " \n"[j == n];
            }
        }
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> te;
    while (te--) {
        solve();
    }
}