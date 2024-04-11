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

int slow(int n, vector<pii> edges) {
    vector<vector<int>> g(n, vector<int>(n));
    for (auto [x, y] : edges)
        g[x - 1][y - 1] = g[y - 1][x - 1] = 1;
    int rn = _binpow(n, mod - 2);
    int res = 0;
    function<void(int, vector<int>, int)> rec = [&](int mask, vector<int> seq, int prob) {
        if ((1 << n) - 1 == mask) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (seq[j] > seq[i])
                        _inc(res, prob);
                }
            }
            return;
        }
        if (mask == 0) {
            for (int i = 0; i < n; i++) {
                rec(1 << i, {i}, _binpow(n, mod - 2));
            }
            return;
        }
        vector<int> can(n);
        for (int v = 0; v < n; v++) {
            if ((1 << v) & mask) {
                for (int to = 0; to < n; to++)
                    if (g[v][to])
                        can[to] = 1;
            }
        }
        int total = 0;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & mask)
                continue;
            total += can[i];
        }
        total = _binpow(total, mod - 2);
        for (int v = 0; v < n; v++) {
            if ((1 << v) & mask)
                continue;
            if (!can[v])
                continue;
            vector<int> next_seq = seq;
            next_seq.push_back(v);
            rec(mask | (1 << v), next_seq, _mul(prob, total));
        }
    };
//    for (int root = 0; root < n; root++) {
//        res = 0;
//        rec(1 << root, {root}, 1);
//        cout << "root = " << root + 1 << " : " << res << "\n";
//    }
    rec(0, {}, 1);
    return res;
}

int fast(int n, vector<pii> edges) {
    vector<vector<int>> p(n + 1, vector<int>(n + 1));
    int r2 = _binpow(2, mod - 2);
    for (int y = 1; y <= n; y++)
        p[0][y] = 1;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            p[x][y] = _mul(r2, _sum(p[x - 1][y], p[x][y - 1]));
        }
    }
//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j <= n; j++)
//            cout << p[i][j] << " ";
//        cout << "\n";
//    }
    vector<vector<int>> g(n + 1);
    for (auto [x, y] : edges) {
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int rn = _binpow(n, mod - 2);
    int E = 0;
    for (int root = 1; root <= n; root++) {
        int EE = E;
        _inc(E, root - 1);
        vector<int> pr(n + 1), de(n + 1);
        function<void(int, int)> dfs = [&](int v, int par) {
            pr[v] = par;
            de[v] = par == -1 ? 0 : de[par] + 1;
            for (int to : g[v]) {
                if (to == par)
                    continue;
                dfs(to, v);
            }
        };
        dfs(root, -1);
        vector<int> vs(n);
        for (int i = 0; i < n; i++)
            vs[i] = i + 1;
        sort(vs.begin(), vs.end(), [&](int v1, int v2) {
            return de[v1] < de[v2];
        });
        vector<vector<int>> lca(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = vs[i];
                int y = vs[j];
                if (x == y) {
                    lca[x][y] = x;
                } else {
                    if (de[x] > de[y]) lca[x][y] = lca[pr[x]][y];
                    else lca[x][y] = lca[x][pr[y]];
                }
            }
        }
        for (int x = 1; x <= n; x++) {
            if (x == root)
                continue;
            for (int y = 1; y < x; y++) {
                if (y == root)
                    continue;
                int w = lca[x][y];
                int lx = de[x] - de[w];
                int ly = de[y] - de[w];
                _inc(E, p[lx][ly]);
            }
        }
//        cout << "root = " << root << " | delta = " << _sub(E, EE) << "\n";
    }
    E = _mul(E, rn);
    return E;
}

void work() {
    int n;
    cin >> n;
    vector<pii> edges(n - 1);
    for (auto& [x, y] : edges)
        cin >> x >> y;
    int res = fast(n, edges);
    cout << res << "\n";
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 4;
    while (1) {
        int n = rnd() % (MAXN - 1) + 2;
        vector<pii> edges;
        for (int i = 2; i <= n; i++)
            edges.emplace_back(rnd() % (i - 1) + 1, i);
        shuffle(edges.begin(), edges.end(), rnd);
        int fs = fast(n, edges);
        int sl = slow(n, edges);
        if (fs == sl) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            cout << n << "\n";
            for (auto [x, y] : edges)
                cout << x << " " << y << "\n";
            break;
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}