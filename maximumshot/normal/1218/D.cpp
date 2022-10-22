#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = inf + 7;

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

int r2;

const int N = 1e5 + 100;

int n, m;
vector<pii> g[N];
set<pii> br;

void add_bridge(int u, int v) {
    if (u > v) swap(u, v);
    br.insert({u, v});
}

bool is_bridge(int u, int v) {
    if (u > v) swap(u, v);
    return br.count({u, v});
}

int fup[N];
int tin[N], timer;
int used[N];
int xr[N];
vector<int> comp[N];

void dfs(int v, int from = -1) {
    used[v] = 1;
    tin[v] = fup[v] = timer++;
    for (pii ed : g[v]) {
        int to = ed.first;
        if (to == from) continue;
        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                add_bridge(v, to);
            }
        }
    }
}

int color[N];

void go(int v, int cl) {
    color[v] = cl;
    for (pii ed : g[v]) {
        int to = ed.first;
        if (is_bridge(v, to)) continue;
        if (!color[to]) {
            go(to, cl);
        }
    }
}

const int LOG = 17;

int _rev[1 << LOG];

void fwht(vector<int>& a) {
    for (int len = 1; len < (1 << LOG); len <<= 1) {
        for (int i = 0; i < (1 << LOG); i += 2 * len) {
            for (int j = 0; j < len; j++) {
                int f1 = _sum(a[i + j], a[i + j + len]);
                int f2 = _sub(a[i + j], a[i + j + len]);
                a[i + j] = f1;
                a[i + j + len] = f2;
            }
        }
    }
}

int main() {

    for (int i = 0; i < (1 << LOG); i++) {
        int j = 0;
        for (int q = 0; q < LOG; q++) {
            if ((1 << q) & i) {
                j |= (1 << (LOG - 1 - q));
            }
        }
        _rev[i] = j;
    }

    r2 = _binpow(1 << LOG, mod - 2);

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int w, u, v, i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dfs(1);

    int cl = 0;
    for (int v = 1; v <= n; v++) {
        if (color[v]) continue;
        cl++;
        go(v, cl);
    }

    vector<vector<int>> vals;

    int tot = 0;

    for (int v = 1; v <= n; v++) {
        for (pii ed : g[v]) {
            int to = ed.first;
            if (v > to) continue;
            int we = ed.second;
            if (is_bridge(v, to)) {
                tot ^= we;
                continue;
            }
            xr[color[v]] ^= we;
            comp[color[v]].push_back(we);
        }
    }

    for (int c = 1; c <= cl; c++) {
        vector<int> add;
        for (int we : comp[c]) {
            add.push_back(xr[c] ^ we);
        }
        if (!add.empty())
            vals.push_back(add);
    }

    vector<int> cur_dp(1 << LOG), cur_can(1 << LOG);
    cur_dp[tot] = 1;
    cur_can[tot] = 1;

    for (const auto& ar : vals) {
        vector<int> tmp_dp(1 << LOG), tmp_can(1 << LOG);
        for (int x : ar) {
            _inc(tmp_dp[x], 1);
            tmp_can[x] = 1;
        }
        fwht(cur_dp);
        fwht(cur_can);
        fwht(tmp_dp);
        fwht(tmp_can);
        vector<int> nxt_dp(1 << LOG), nxt_can(1 << LOG);
        for (int i = 0; i < (1 << LOG); i++) {
            nxt_dp[i] = _mul(cur_dp[i], tmp_dp[i]);
            nxt_can[i] = _mul(cur_can[i], tmp_can[i]);
        }
        fwht(nxt_dp);
        fwht(nxt_can);
        for (int i = 0; i < (1 << LOG); i++) {
            nxt_dp[i] = _mul(nxt_dp[i], r2);
            nxt_can[i] = _mul(nxt_can[i], r2);
        }
        for (int i = 0; i < (int) nxt_can.size(); i++) {
            if (nxt_can[i]) nxt_can[i] = 1;
        }
        cur_dp = nxt_dp;
        cur_can = nxt_can;
    }

    for (int i = 0; i < (int) cur_dp.size(); i++) {
        if (cur_can[i]) {
            cout << i << " " << cur_dp[i] << "\n";
            break;
        }
    }

    return 0;
}