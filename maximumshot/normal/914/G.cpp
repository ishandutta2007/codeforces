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

const int LOG = 17;

void fwht(vector<int>& a) {
    int f1, f2;
    for (int len = 1; len < (1 << LOG); len <<= 1) {
        for (int i = 0; i < (1 << LOG); i += 2 * len) {
            for (int j = 0; j < len; j++) {
                f1 = _sum(a[i + j], a[i + j + len]);
                f2 = _sub(a[i + j], a[i + j + len]);
                a[i + j] = f1;
                a[i + j + len] = f2;
            }
        }
    }
}

void and_fwht(vector<int>& a, bool inverse = false) {
    int f1, f2;
    for (int len = 1; len < (1 << LOG); len <<= 1) {
        for (int i = 0; i < (1 << LOG); i += 2 * len) {
            for (int j = 0; j < len; j++) {
                f1 = inverse ? _sub(a[i + j], a[i + j + len]) : _sum(a[i + j], a[i + j + len]);
                f2 = a[i + j + len];
                a[i + j] = f1;
                a[i + j + len] = f2;
            }
        }
    }
}

vector<int> mult(vector<int> a, vector<int> b) {
    vector<int> c(1 << LOG);
    for (int i = 0; i < (int) a.size(); i++)
        for (int j = 0; j < (int) b.size(); j++)
            _inc(c[i & j], _mul(a[i], b[j]));
    return c;
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> F(1 << LOG);
    F[1] = 1;
    for (int i = 2; i < (1 << LOG); i++)
        F[i] = _sum(F[i - 1], F[i - 2]);

    int n;
    cin >> n;
    vector<int> a(1 << LOG);
    for (int x, i = 0; i < n; i++) {
        cin >> x;
        _inc(a[x], 1);
    }

    vector<int> b(1 << LOG);
    for (int x = 0; x < (1 << LOG); x++) {
        int rem = ((1 << LOG) - 1) ^ x;
        for (int y = rem; ; y = (y - 1) & rem) {
            _inc(b[x | y], _mul(a[x], a[y]));
            if (y == 0)
                break;
        }
    }

    vector<int> c(1 << LOG);

    {
        vector<int> fa = a;
        fwht(fa);
        for (int i = 0; i < (int) fa.size(); i++)
            c[i] = _mul(fa[i], fa[i]);
        fwht(c);
        int rn = _binpow(2, mod - 2);
        rn = _binpow(rn, LOG);
        for (int i = 0; i < (int) c.size(); i++)
            c[i] = _mul(c[i], rn);
    }

//    for (int x = 0; x < (1 << LOG); x++)
//        for (int y = 0; y < (1 << LOG); y++)
//            _inc(c[x ^ y], _mul(a[x], a[y]));

    for (int x = 0; x < (1 << LOG); x++) {
        a[x] = _mul(a[x], F[x]);
        b[x] = _mul(b[x], F[x]);
        c[x] = _mul(c[x], F[x]);
    }

    int res = 0;

    and_fwht(a);
    and_fwht(b);
    and_fwht(c);
    for (int i = 0; i < (int) a.size(); i++)
        a[i] = _mul(a[i], _mul(b[i], c[i]));
    and_fwht(a, true);

//    a = mult(a, b);
//    a = mult(a, c);

    for (int i = 0; i < LOG; i++)
        _inc(res, a[1 << i]);

    cout << res << "\n";

    return 0;
}