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

const int mod = 31607;

inline int _sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int _mul(int a, int b) {
    return (a * b) % mod;
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

const int rev_10k = _binpow(10000, mod - 2);

int slow(int n, vector<vector<int>> p) {
    int S = 0;
    int N = n * n;
    for (int mask = 0; mask < (1 << N); mask++) {
        int ml = 1;
        vector<int> crow(n), ccol(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = (mask >> (i * n + j)) & 1;
                if (x)
                    ml = _mul(ml, p[i][j]), crow[i]++, ccol[j]++;
                else
                    ml = _mul(ml, _sub(1, p[i][j]));
            }
        }
        int ok1 = 1, ok2 = 1;
        for (int i = 0; i < n; i++) {
            int x = (mask >> (i * n + i)) & 1;
            int y = (mask >> (i * n + (n - 1 - i))) & 1;
            ok1 &= x;
            ok2 &= y;
        }
        if (*max_element(crow.begin(), crow.end()) == n || *max_element(ccol.begin(), ccol.end()) == n || ok1 || ok2) {
            _inc(S, ml);
        }
    }
    return S;
}

int slow_cross(int n, vector<vector<int>> p) {
    int S = 0;
    int N = n * n;
    for (int mask = 0; mask < (1 << N); mask++) {
        int ml = 1;
        vector<int> crow(n), ccol(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = (mask >> (i * n + j)) & 1;
                if (x)
                    ml = _mul(ml, p[i][j]), crow[i]++, ccol[j]++;
                else
                    ml = _mul(ml, _sub(1, p[i][j]));
            }
        }
        if (*max_element(crow.begin(), crow.end()) == n || *max_element(ccol.begin(), ccol.end()) == n) {
            _inc(S, ml);
        }
    }
    return S;
}

int fast_cross(int n, vector<vector<int>> p) {
    int res = 0;
//    for (int mask = 1; mask < (1 << n); mask++) {
//        int cnt = __builtin_popcount(mask);
//        int ml_row = 1, ml_col = 1;
//        for (int i = 0; i < n; i++) {
//            if ((1 << i) & mask) {
//                for (int j = 0; j < n; j++) {
//                    ml_row = _mul(ml_row, p[i][j]);
//                    ml_col = _mul(ml_col, p[j][i]);
//                }
//            }
//        }
//        if (cnt % 2) _inc(res, ml_row), _inc(res, ml_col);
//        else _dec(res, ml_row), _dec(res, ml_col);
//    }
    {
        int coef = 1;
        for (int i = 0; i < n; i++) {
            int ml = 1;
            for (int j = 0; j < n; j++)
                ml = _mul(ml, p[i][j]);
            ml = _sub(1, ml);
            coef = _mul(coef, ml);
        }
        coef = _sub(1, coef);
        _inc(res, coef);
    }
    {
        int coef = 1;
        for (int j = 0; j < n; j++) {
            int ml = 1;
            for (int i = 0; i < n; i++)
                ml = _mul(ml, p[i][j]);
            ml = _sub(1, ml);
            coef = _mul(coef, ml);
        }
        coef = _sub(1, coef);
        _inc(res, coef);
    }
//    {
//        int S = 0;
//        int N = n * n;
//        for (int mask = 0; mask < (1 << N); mask++) {
//            int ml = 1;
//            vector<int> crow(n), ccol(n);
//            for (int i = 0; i < n; i++) {
//                for (int j = 0; j < n; j++) {
//                    int x = (mask >> (i * n + j)) & 1;
//                    if (x)
//                        ml = _mul(ml, p[i][j]), crow[i]++, ccol[j]++;
//                    else
//                        ml = _mul(ml, _sub(1, p[i][j]));
//                }
//            }
//            if (*max_element(crow.begin(), crow.end()) == n && *max_element(ccol.begin(), ccol.end()) == n) {
//                _inc(S, ml);
//            }
//        }
//        _dec(res, S);
//    }
    {
        vector<int> p_row(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                p_row[i] = _mul(p_row[i], p[i][j]);
        }
        vector<vector<int>> p_col(n, vector<int>(1 << n));
        vector<int> bit(1 << n);
        for (int i = 0; i < n; i++)
            bit[1 << i] = i;
        for (int j = 0; j < n; j++) {
            p_col[j][0] = 1;
            for (int mask = 1; mask < (1 << n); mask++) {
                int i = bit[mask & -mask];
                p_col[j][mask] = _mul(p_col[j][mask ^ (1 << i)], p[i][j]);
            }
        }
        for (int mask = 1; mask < (1 << n); mask++) {
            int cnt = __builtin_popcount(mask);
            int ml = 1, coef = 1;
            for (int i = 0; i < n; i++) {
                if ((1 << i) & mask) {
                    ml = _mul(ml, p_row[i]);
                }
            }
            for (int j = 0; j < n; j++) {
                int prob = p_col[j][mask ^ ((1 << n) - 1)];
//                for (int i = 0; i < n; i++) {
//                    if (!((1 << i) & mask)) {
//                        prob = _mul(prob, p[i][j]);
//                    }
//                }
                prob = _sub(1, prob);
                coef = _mul(coef, prob);
            }
            coef = _sub(1, coef);
            coef = _mul(coef, ml);
            if (cnt % 2) _dec(res, coef);
            else _inc(res, coef);
        }
    }
    return res;
}

int fast(int n, vector<vector<int>> p) {
    vector<vector<int>> q = p;
    for (auto& row : q) for (auto& x : row) x = _sub(1, x);

    int res = 0;

    _inc(res, fast_cross(n, p));

    { // diag cross
        int S = 0;
        {
            int ml = 1;
            for (int i = 0; i < n; i++) ml = _mul(ml, p[i][i]);
            _inc(S, ml);
        }
        {
            int ml = 1;
            for (int i = 0; i < n; i++) ml = _mul(ml, p[i][n - 1 - i]);
            _inc(S, ml);
        }
        {
            int ml = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j || j == n - 1 - i)
                        ml = _mul(ml, p[i][j]);
                }
            }
            _dec(S, ml);
        }
        _inc(res, S);
    }

    {
        int S = 0;
        {
            int ml = 1;
            vector<vector<int>> hlp = p;
            for (int i = 0; i < n; i++) ml = _mul(ml, p[i][i]), hlp[i][i] = 1;
            _inc(S, _mul(ml, fast_cross(n, hlp)));
        }
        {
            int ml = 1;
            vector<vector<int>> hlp = p;
            for (int i = 0; i < n; i++) ml = _mul(ml, p[i][n - 1 - i]), hlp[i][n - 1 - i] = 1;
            _inc(S, _mul(ml, fast_cross(n, hlp)));
        }
        {
            int ml = 1;
            vector<vector<int>> hlp = p;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j || j == n - 1 - i)
                        ml = _mul(ml, p[i][j]), hlp[i][j] = 1;
                }
            }
            _dec(S, _mul(ml, fast_cross(n, hlp)));
        }
        _dec(res, S);
    }

    return res;
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 4;
    while (1) {
        int n = rnd() % MAXN + 1;
        vector<vector<int>> p(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                p[i][j] = rnd() % (10000 - 1) + 1;
                p[i][j] = _mul(p[i][j], rev_10k);
            }
        }
        int fs = fast(n, p);
        int sl = slow(n, p);
        if (fs == sl) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            cout << n << "\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << _mul(p[i][j], 10000) << " ";
                }
                cout << "\n";
            }
            break;
        }
    }
}

void work() {
    int n;
    cin >> n;
    vector<vector<int>> p(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
            p[i][j] = _mul(p[i][j], rev_10k);
        }
    }
    int res = fast(n, p);
    cout << res << "\n";
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