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

int slow(int n, vector<pii> edges) {
    vector<vector<int>> g(n + 1);
    for (auto[u, v] : edges) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int R = 0; R <= n; R++) {
        int cnt = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> used(n + 1);
            function<void(int, int, int)> dfs = [&](int v, int par, int d) {
                if (d > R)
                    return;
                used[v] = 1;
                for (int to : g[v]) {
                    if (to == par)
                        continue;
                    dfs(to, v, d + 1);
                }
            };
            for (int s = 1; s <= n; s++) {
                if ((1 << (s - 1)) & mask)
                    continue;
                dfs(s, -1, 0);
            }
            int ok = 1;
            for (int v = 1; v <= n; v++) {
                if (!used[v]) {
                    ok = 0;
                    break;
                }
            }
            if (ok)
                cnt++;
        }
        cout << R << " : " << ld(cnt) / ld(1 << n) << "\n";
    }
}

int fast(int n, vector<pii> edges) {
    vector<vector<int>> g(n + 1);
    for (auto [u, v] : edges) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int r2 = _binpow(2, mod - 2);

    vector<int> h(n + 1);
    function<void(int, int)> go = [&](int v, int par) {
        h[v] = 0;
        for (int to : g[v]) {
            if (to == par)
                continue;
            go(to, v);
            h[v] = max(h[v], h[to] + 1);
        }
    };

    go(1, -1);

    vector<vector<int>> dp;
    vector<vector<ld>> DP;
    function<void(int, int, int)> dfs = [&](int v, int par, int R) {
        dp[v][0] = r2;
        dp[v][R + 1] = r2;

        DP[v][0] = 1.0 / 2.0;
        DP[v][R + 1] = 1.0 / 2.0;

        for (int to : g[v]) {
            if (to == par)
                continue;
            dfs(to, v, R);
            vector<int> f(2 * R + 2);
            vector<ld> F(2 * R + 2);
            vector<int> v_can, to_can;
            for (int hv = 0; hv <= 2 * R + 1; hv++) {
                if (dp[v][hv] > 0)
                    v_can.push_back(hv);
            }
            for (int hto = 0; hto <= 2 * R + 1; hto++) {
                if (dp[to][hto] > 0)
                    to_can.push_back(hto);
            }
            for (int hv : v_can) {
                for (int hto : to_can) {
                    if (hv == 0 && hto <= 2 * R) {
                        _inc(f[0], _mul(dp[v][0], dp[to][hto]));
                        F[0] += DP[v][0] * DP[to][hto];
                    }
                    if (hv > 0 && hto < 2 * R) {
                        int hh = min(hv, hto + 1);
                        if (hv + 1 + hto + 1 > 2 * (R + 1)) {
                            hh = max(hv, hto + 1);
                        }
                        _inc(f[hh], _mul(dp[v][hv], dp[to][hto]));
                        F[hh] += DP[v][hv] * DP[to][hto];
                    }
                }
            }
            dp[v] = f;
            DP[v] = F;
        }
    };

    vector<int> prob(n + 1);
    for (int R = 0; R <= n; R++) {
        dp.assign(n + 1, vector<int>(2 * R + 2, 0));
        DP.assign(n + 1, vector<ld>(2 * R + 2, 0));
        dfs(1, -1, R);
        ld hlp = 0;
        for (int hh = 0; hh <= R; hh++) {
            _inc(prob[R], dp[1][hh]);
            hlp += DP[1][hh];
        }

//        cout << R << " : " << hlp << "\n";
    }

    int E = 0;
    for (int R = 0; R <= n + 1; R++) {
        int p = R <= n ? prob[R] : 1;
        p = _sub(p, R > 0 ? prob[R - 1] : 0);
        int x = _sub(R, 1);
        _inc(E, _mul(p, x));
    }

    return E;
}

void work() {
    int n;
    cin >> n;
    vector<pii> edges(n - 1);
    for (int u, v, i = 0; i < n - 1; i++) {
        cin >> u >> v;
        edges[i] = {u, v};
    }
    int fs = fast(n, edges);
    cout << fs << "\n";
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