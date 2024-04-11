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
const int TEN4 = 1e4;

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

int slow_calc(int n, const vector<vector<int>>& p) {
    int N = n * n;
    int res = 0;
    for (int mask = 0; mask < (1 << N); mask++) {
        int prob = 1;
        for (int it = 0; it < N; it++) {
            int x = p[it / n][it % n];
            if (!((1 << it) & mask))
                x = _sub(1, x);
            prob = _mul(prob, x);
        }
        int any = 0;
        for (int i = 0; i < n; i++) {
            int all = 1;
            for (int j = 0; j < n; j++) {
                int it = i * n + j;
                if (!((1 << it) & mask))
                    all = 0;
            }
            if (all)
                any = 1;
        }
        for (int j = 0; j < n; j++) {
            int all = 1;
            for (int i = 0; i < n; i++) {
                int it = i * n + j;
                if (!((1 << it) & mask))
                    all = 0;
            }
            if (all)
                any = 1;
        }
        if (any)
            _inc(res, prob);
    }
    return res;
}

int calc_all(int n, const vector<vector<int>> &p) {
    vector<int> prow(n);
    for (int i = 0; i < n; i++) {
        prow[i] = 1;
        for (int j = 0; j < n; j++)
            prow[i] = _mul(prow[i], p[i][j]);
    }
    vector<vector<int>> pcol(n, vector<int>(1 << n));
    vector<int> bit(1 << n); for (int i = 0; i < n; i++) bit[1 << i] = i;
    for (int j = 0; j < n; j++) {
        pcol[j][0] = 1;
        for (int rows = 1; rows < (1 << n); rows++) {
            int i = bit[rows & -rows];
            pcol[j][rows] = _mul(pcol[j][rows ^ (1 << i)], p[i][j]);
        }
    }
    int all_rows = (1 << n) - 1;
    int res = 0;
    for (int rows = 1; rows < (1 << n); rows++) {
        int ml = 1;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & rows)
                ml = _mul(ml, prow[i]);
        }
        int prob = 1;
        for (int j = 0; j < n; j++)
            prob = _mul(prob, _sub(1, pcol[j][rows ^ all_rows]));
        prob = _sub(1, prob);
        ml = _mul(ml, prob);
        if (__builtin_popcount(rows) & 1)
            _inc(res, ml);
        else
            _dec(res, ml);
    }
    return res;
}

int calc_any(int n, const vector<vector<int>> &p) {
    int res = 0;
    { // rows
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
    { // cols
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
    _dec(res, calc_all(n, p));
    return res;
}

int fast(int n, vector<vector<int>> a) {
    vector<vector<int>> p = a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p[i][j] = _div(a[i][j], TEN4);
        }
    }
    int res = 0;
    _inc(res, calc_any(n, p));
    {
        int coef = 1;
        vector<vector<int>> pp = p;
        for (int i = 0; i < n; i++) {
            coef = _mul(coef, p[i][i]);
            pp[i][i] = 1;
        }
        _inc(res, coef);
        _dec(res, _mul(coef, calc_any(n, pp)));
    }
    {
        int coef = 1;
        vector<vector<int>> pp = p;
        for (int i = 0; i < n; i++) {
            coef = _mul(coef, p[i][n - 1 - i]);
            pp[i][n - 1 - i] = 1;
        }
        _inc(res, coef);
        _dec(res, _mul(coef, calc_any(n, pp)));
    }
    {
        int coef = 1;
        vector<vector<int>> pp = p;
        for (int i = 0; i < n; i++) {
            coef = _mul(coef, pp[i][i]);
            pp[i][i] = 1;
        }
        for (int i = 0; i < n; i++) {
            coef = _mul(coef, pp[i][n - 1 - i]);
            pp[i][n - 1 - i] = 1;
        }
        _dec(res, coef);
        _inc(res, _mul(coef, calc_any(n, pp)));
    }
    return res;
}

void work() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int res = fast(n, a);
    cout << res << "\n";
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