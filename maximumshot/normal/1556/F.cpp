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

int slow(int n, vector<int> a) {
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = _div(a[i], a[i] + a[j]);
        }
    }
    vector<pii> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            edges.emplace_back(i, j);
    }
    int m = (int) edges.size();
    int res = 0;
    for (int mask = 0; mask < (1 << m); mask++) {
        int prob = 1;
        vector<vector<int>> f(n, vector<int>(n));
        for (int i = 0; i < m; i++) {
            auto [u, v] = edges[i];
            int eprob = 0;
            if ((1 << i) & mask) {
                f[u][v] = 1;
                eprob = g[u][v];
            } else {
                f[v][u] = 1;
                eprob = g[v][u];
            }
            prob = _mul(prob, eprob);
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    f[i][j] |= f[i][k] & f[k][j];
                }
            }
        }
        for (int v = 0; v < n; v++)
            f[v][v] = 1;
        int sz = 0;
        for (int v = 0; v < n; v++) {
            int ok = 1;
            for (int u = 0; u < n; u++)
                ok &= f[v][u];
            sz += ok;
        }
        _inc(res, _mul(sz, prob));
    }
    return res;
}

int fast(int n, vector<int> a) {
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = _div(a[i], a[i] + a[j]);
        }
    }
    vector<int> comp2(1 << n);
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> in;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & mask)
                in.push_back(i);
        }
        for (int A = mask; A > 0; A = (A - 1) & mask) {
            int B = mask ^ A;
            if (!A || !B) continue;
            int prob = 1;
            for (int u : in) {
                if ((1 << u) & B)
                    continue;
                for (int v : in) {
                    if ((1 << v) & A)
                        continue;
                    prob = _mul(prob, g[u][v]);
                }
            }
            _inc(comp2[mask], _mul(prob, comp2[A]));
        }
        comp2[mask] = _sub(1, comp2[mask]);
    }
    int res = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> in, out;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & mask) {
                in.push_back(i);
            } else {
                out.push_back(i);
            }
        }
        int coef = 1;
        for (int u : in) {
            for (int v : out) {
                coef = _mul(coef, g[u][v]);
            }
        }
        int prob = _mul(coef, comp2[mask]);
//        cout << "in = { "; for (auto v : in) cout << v << " "; cout << "}, prob = " << coef << " * " << comp2[mask] << "\n";
        _inc(res, _mul(prob, (int) in.size()));
    }
//    cout << _div(3, 2) << " 3/2 \n";
//    cout << _div(1, 2) << " 1/2 \n";
//    cout << _div(1, 4) << " 1/4 \n";
//    cout << _div(1, 8) << " 1/8 \n";
//    cout << _div(1, 16) << " 1/16 \n";
    return res;
}

void work() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = fast(n, a);
    cout << res << "\n";
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 5;
    const int MAXX = 10;
    while (1) {
        int n = rnd() % MAXN + 1;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = rnd() % MAXX + 1;
        int fs = fast(n, a);
        int sl = slow(n, a);
        if (fs == sl) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            cout << n << "\n";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << "\n";
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