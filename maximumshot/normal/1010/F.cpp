#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = 998244353;
const int root = 31;
const int LOG = 23;
const int N = 1e5 + 5;

vec< int > G[LOG + 1];
vec< int > rev[LOG + 1];

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

void fft(vec< int > &a, int sz, bool invert) {
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

vec< int > multiply(const vec< int > &a, const vec< int > &b) {
    vec< int > fa(ALL(a));
    vec< int > fb(ALL(b));

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

struct Polynom {
    vec< int > a;

    Polynom() {
        a.resize(1);
    }

    Polynom(const vec< int > _a): a(_a)
    { }

    int get_size() const {
        return (int)a.size();
    }

    Polynom operator * (const Polynom &o) const {
        return Polynom(multiply(a, o.a));
    }

    Polynom operator + (const Polynom &o) const {
        Polynom res;
        int n = this->get_size();
        int m = o.get_size();
        res.a.resize(max(n, m));
        for(int i = 0;i < n;i++) {
            _add(res.a[i], this->a[i]);
        }
        for(int i = 0;i < m;i++) {
            _add(res.a[i], o.a[i]);
        }
        while((int)res.a.size() > 1 && !res.a.back()) res.a.pop_back();
        return res;
    }
};

struct Func {
    vec< Polynom > a;
    int len = 0;

    int get_len() const {
        return len;
    }

    void add_polynom(const Polynom &add_poly) {
        a.push_back(add_poly);
        len += add_poly.get_size();
        assert(add_poly.get_size());
    }

    // sum, max
    pair< Polynom, Polynom > gen_polynom(int l, int r) {
        if(l == r) {
            assert(a[l].get_size());
            return make_pair(a[l], a[l]);
        }
        int m = (l + r) >> 1;
        pair< Polynom, Polynom > L = gen_polynom(l, m);
        pair< Polynom, Polynom > R = gen_polynom(m + 1, r);
        return make_pair((L.first * R.second) + R.first, L.second * R.second);
    }

    Polynom gen_polynom() {
        assert(!a.empty());
        Polynom p = gen_polynom(0, (int)a.size() - 1).first;
        if((++p.a[0]) == mod) p.a[0] = 0;
        p.a.insert(p.a.begin(), 0);
        return p;
    }

    bool empty() const {
        return a.empty();
    }
};

int n;
ll X;
vec< int > g[N];
int C[N];
Func f[N];

void dfs(int v, int par = -1) {

    int child = 0;

    for(int to : g[v]) {
        if(to == par) continue;
        dfs(to, v);

        child++;

        if(f[to].get_len() > f[v].get_len()) {
            swap(f[v], f[to]);
        }

        if(f[to].empty()) {
            continue;
        }

        f[v].add_polynom(f[to].gen_polynom());
    }

    if(child < 2) {
        f[v].add_polynom(Polynom({0, 1}));
    }
}

int main() {

    precalc();

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %lld", &n, &X);

    for(int i = 1;i < n;++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    {
        fill(C, C + N, 1);
        X %= mod;
        for(int cur = 1, i = 1;i < N;i++) {
            C[i] = _mul(C[i], cur);
            cur = _mul(cur, _sum(X, i));
        }
        int fact = 1;
        for(int i = 2;i < n;i++) {
            fact = _mul(fact, i);
        }
        fact = _rev(fact);
        for(int i = n;i >= 1;i--) {
            C[i] = _mul(C[i], fact);
            fact = _mul(fact, i - 1);
        }
    }

    dfs(1);

    vec< int > p = f[1].gen_polynom().a;
    p.erase(p.begin());

    p.resize(n + 1);

    int res = 0;

    for(int i = 1;i <= n;i++) {
        if((res += _mul(C[i], p[i])) >= mod) {
            res -= mod;
        }
    }

    printf("%d\n", res);

    return 0;
}