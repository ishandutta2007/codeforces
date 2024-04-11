#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = 998244353;

inline int _sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int _sub(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline void _inc(int &x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}

inline void _dec(int &x, int y) {
    if ((x -= y) < 0) {
        x += mod;
    }
}

inline int _binpow(int x, int pw) {
    int res = 1;
    int tmp = x;
    while (pw > 0) {
        if (pw & 1) {
            res = _mul(res, tmp);
        }
        tmp = _mul(tmp, tmp);
        pw >>= 1;
    }
    return res;
}

inline int _div(int a, int b) {
    return _mul(a, _binpow(b, mod - 2));
}

vector<vector<int>> fast(int n, int m, vector<pii> edges) {
    vector<vector<int>> g(n);
    for (auto& [u, v] : edges) {
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> d(n, vector<int>(n, inf));
    for (int s = 0; s < n; s++) {
        queue<int> q;
        q.push(s);
        d[s][s] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to : g[v]) {
                if (d[s][to] > d[s][v] + 1) {
                    d[s][to] = d[s][v] + 1;
                    q.push(to);
                }
            }
        }
    }
    vector<vector<int>> res(n, vector<int>(n));
    for (int s = 0; s < n; s++) {
        vector<vector<int>> group(n);
        for (int v = 0; v < n; v++)
            group[d[s][v]].push_back(v);
        for (int t = 0; t < n; t++) {
            if (s == t) {
                res[s][t] = 1;
                for (int v = 0; v < n; v++) {
                    if (s == v)
                        continue;
                    int cnt = 0;
                    for (int to : g[v]) {
                        if (d[s][to] < d[s][v])
                            cnt++;
                    }
                    res[s][t] = _mul(res[s][t], cnt);
                }
                continue;
            }
            int coef = 1;
            vector<int> D_LCA(n);
            for (int v = 0; v < n; v++) {
                // d[s][v] + d[s][t] - 2 * d[s][lca] == d[t][v]
                int d_lca = d[s][v] + d[s][t] - d[t][v];
                if (d_lca % 2) {
                    coef = 0;
                    break;
                }
                d_lca /= 2;
                if (d_lca < 0) {
                    coef = 0;
                    break;
                }
                if (d_lca > d[s][v] || d_lca > d[s][t]) {
                    coef = 0;
                    break;
                }
                D_LCA[v] = d_lca;
            }
            if (coef == 0) {
                res[s][t] = 0;
                continue;
            }
            res[s][t] = 1;
            for (int i = 0; i <= d[s][t]; i++) {
                if (group[i].empty())
                    break;
                int c0 = 0;
                for (auto v : group[i]) {
                    if (D_LCA[v] == d[s][v]) {
                        c0++;
                    }
                }
                if (c0 != 1) {
                    res[s][t] = 0;
                    break;
                }
            }
            if (res[s][t] == 0) {
                continue;
            }
            for (int i = 1; i < n; i++) {
                int ml = 1;
                for (auto v : group[i]) {
                    if (D_LCA[v] == d[s][v])
                        continue;
                    int cnt = 0;
                    for (int to : g[v]) {
                        if (d[s][to] < d[s][v] && D_LCA[to] == D_LCA[v])
                            cnt++;
                    }
                    ml = _mul(ml, cnt);
                }
                res[s][t] = _mul(res[s][t], ml);
            }
        }
    }
    return res;
}

void work() {
    int n, m;
    cin >> n >> m;
    vector<pii> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    vector<vector<int>> fs = fast(n, m, edges);
    for (auto x : fs) {
        for (auto y : x)
            cout << y << " ";
        cout << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}