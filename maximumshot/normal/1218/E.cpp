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

const int mod = 998244353;
const int root = 31 * 31 * 31 * 31;
const int LOG = 21;
const int N = 1e5 + 5;

vector< int > G[LOG + 1];
vector< int > rev[LOG + 1];

inline void _add(int &x, int y) {
    if((x += y) >= mod) {
        x -= mod;
    }
}

inline int _sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int _sub(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int _binpow(int x, int p) {
    int res = 1;
    int tmp = x;
    while(p > 0) {
        if(p & 1) {
            res = _mul(res, tmp);
        }
        tmp = _mul(tmp, tmp);
        p >>= 1;
    }
    return res;
}

inline int _rev(int x) {
    return _binpow(x, mod - 2);
}

void precalc() {
    for(int start = root, lvl = LOG;lvl >= 0;lvl--, start = _mul(start, start)) {
        int tot = 1 << lvl;
        G[lvl].resize(tot);
        for(int cur = 1, i = 0;i < tot;i++, cur = _mul(cur, start)) {
            G[lvl][i] = cur;
        }
    }
    for(int lvl = 1;lvl <= LOG;lvl++) {
        int tot = 1 << lvl;
        rev[lvl].resize(tot);
        for(int i = 1;i < tot;i++) {
            rev[lvl][i] = ((i & 1) << (lvl - 1)) | (rev[lvl][i >> 1] >> 1);
        }
    }
}

void fft(vector< int > &a, int sz, bool invert) {
    int n = 1 << sz;

    for(int j, i = 0;i < n;i++) {
        if((j = rev[sz][i]) < i) {
            swap(a[i], a[j]);
        }
    }

    for(int f1, f2, lvl = 0, len = 1;len < n;len <<= 1, lvl++) {
        for(int i = 0;i < n;i += (len << 1)) {
            for(int j = 0;j < len;j++) {
                f1 = a[i + j];
                f2 = _mul(a[i + j + len], G[lvl + 1][j]);
                a[i + j] = _sum(f1, f2);
                a[i + j + len] = _sub(f1, f2);
            }
        }
    }

    if(invert) {
        reverse(a.begin() + 1, a.end());
        int rn = _rev(n);
        for(int i = 0;i < n;i++) {
            a[i] = _mul(a[i], rn);
        }
    }
}

vector< int > multiply(const vector< int > &a, const vector< int > &b) {
    vector< int > fa(a.begin(), a.end());
    vector< int > fb(b.begin(), b.end());

    int n = (int)a.size();
    int m = (int)b.size();
    int maxnm = max(n, m), sz = 0;

    while((1 << sz) < maxnm) sz++;
    sz++;

    fa.resize(1 << sz);
    fb.resize(1 << sz);

    fft(fa, sz, false);
    fft(fb, sz, false);

    int SZ = 1 << sz;

    for(int i = 0;i < SZ;i++) {
        fa[i] = _mul(fa[i], fb[i]);
    }

    fft(fa, sz, true);

    while((int)fa.size() > 1 && !fa.back()) fa.pop_back();

    return fa;
}

vector<int> solve(const vector<int>& b, int l, int r) {
    if (l == r) {
        return {1, b[l]};
    }
    int m = (l + r) / 2;
    vector<int> le = solve(b, l, m);
    vector<int> ri = solve(b, m + 1, r);
    return multiply(le, ri);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precalc();

    int n, k;
    cin >> n >> k;

    vector<int> a(n), b;

    int lg = 0;
    while ((1 << lg) <= n) lg++;
    lg++;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int Q;
    cin >> Q;

    for (int iter = 0; iter < Q; iter++) {
        int type, q;
        cin >> type;
        b = a;
        if (type == 1) {
            int i, d;
            cin >> q >> i >> d;
            i--;
            b[i] = d;
        } else {
            int l, r, d;
            cin >> q >> l >> r >> d;
            l--, r--;
            for (int i = l; i <= r; i++) {
                _add(b[i], d);
            }
        }
        for (int i = 0; i < n; i++) {
            b[i] = _sub(q, b[i]);
        }
        vector<int> f = solve(b, 0, n - 1);
        cout << f[k] << "\n";
    }

    return 0;
}