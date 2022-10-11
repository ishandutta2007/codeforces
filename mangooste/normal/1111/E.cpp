#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) (a).begin(), (a).end()
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

template<typename T>
inline int normalize(T val, int mod) {
    if (val < -mod || val >= 2 * mod)
        val %= mod;
    if (val < 0)
        val += mod;
    if (val >= mod)
        val -= mod;
    return int(val);
}

template<int mod>
struct mval {
    int val;

    mval() : val(0) {}
    template<typename T> mval(T val) : val(normalize(val, mod)) {}

    explicit operator int() const { return val; }
    explicit operator long long() const { return val; }

    inline mval power(long long deg) const {
        deg = normalize(deg, mod - 1);
        mval prod = 1;
        mval a = *this;
        for (; deg; deg >>= 1, a *= a)
            if (deg & 1)
                prod *= a;
        return prod;
    }
    inline mval rev() const { return power(-1); }

    inline mval& operator+=(const mval m) { val += m.val; if (val >= mod) val -= mod; return *this; }
    inline mval& operator-=(const mval m) { val -= m.val; if (val < 0) val += mod; return *this; }
    inline mval& operator*=(const mval m) { val = 1ll * val * m.val % mod; return *this; }
    inline mval& operator/=(const mval m) { val = 1ll * val * m.rev().val % mod; return *this; }
    template<typename T> inline mval& operator=(const T x) { *this = mval(x); return *this; }

    inline friend mval operator+(const mval a, const mval b) { return mval(a) += b; }
    inline friend mval operator-(const mval a, const mval b) { return mval(a) -= b; }
    inline friend mval operator*(const mval a, const mval b) { return mval(a) *= b; }
    inline friend mval operator/(const mval a, const mval b) { return mval(a) /= b; }

    inline mval& operator++() { ++val; if (val == mod) val = 0; return *this; }
    inline mval operator++(int) { val++; if (val == mod) val = 0; return *this; }
    inline mval& operator--() { --val; if (val == -1) val = mod - 1; return *this; }
    inline mval operator--(int) { val--; if (val == -1) val = mod - 1; return *this; }

    inline bool operator==(const mval m) const { return val == m.val; }
    inline bool operator!=(const mval m) const { return val != m.val; }
    inline bool operator<(const mval m) const { return val < m.val; }
    inline bool operator>(const mval m) const { return val > m.val; }

    friend istream& operator>>(istream &in, mval &m) { long long x; in >> x; m = mval(x); return in; }
    friend ostream& operator<<(ostream &out, const mval m) { return out << m.val; }
};

constexpr int MOD = 1'000'000'007;
// constexpr int MOD = 998'244'353;
using mint = mval<MOD>;


struct linkcut {
    struct node {
        bool inv;
        int x, s, sz, p, l, r;

        node() : inv(0), x(0), s(0), sz(1), p(-1), l(-1), r(-1) {}
    };

    vec<node> t;

    linkcut() {}
    linkcut(int n) : t(n) {}

    inline bool is_root(int v) const {
        return t[v].p == -1 || (t[t[v].p].l != v && t[t[v].p].r != v);
    }

    inline void push(int x) {
        if (t[x].inv) {
            if (t[x].l != -1) t[t[x].l].inv ^= 1;
            if (t[x].r != -1) t[t[x].r].inv ^= 1;
            swap(t[x].l, t[x].r);
            t[x].inv = 0;
        }
    }

    inline int size(int x) const {
        return (x == -1 ? 0 : t[x].sz);
    }

    inline int sum(int x) const {
        return (x == -1 ? 0 : t[x].s);
    }

    inline void relax(int x) {
        t[x].sz = 1 + size(t[x].l) + size(t[x].r);
        t[x].s = t[x].x + sum(t[x].l) + sum(t[x].r);
    }

    inline void rot(int x) {
        int y = t[x].p, z = t[y].p;
        push(y);
        push(x);
        t[x].p = z;
        if (z != -1) {
            if (t[z].l == y) {
                t[z].l = x;
            } else if (t[z].r == y) {
                t[z].r = x;
            }
        }
        if (x == t[y].l) {
            t[y].l = t[x].r;
            if (t[y].l != -1) t[t[y].l].p = y;
            t[x].r = y;
        } else {
            t[y].r = t[x].l;
            if (t[y].r != -1) t[t[y].r].p = y;
            t[x].l = y;
        }
        t[y].p = x;
        relax(y);
        relax(x);
    }

    inline void splay(int x) {
        while (!is_root(x)) {
            int y = t[x].p;
            if (!is_root(y)) {
                int z = t[y].p;
                rot(((y == t[z].l) == (x == t[y].l)) ? y : x);
            }
            rot(x);
        }
        push(x);
    }

    inline int expose(int v) {
        int y = -1;
        for (int x = v; x != -1; x = t[x].p) {
            splay(x);
            t[x].r = y;
            relax(x);
            y = x;
        }
        splay(v);
        return y;
    }

    inline void set_root(int u) {
        expose(u);
        t[u].inv ^= 1;
    }

    inline void link(int v, int u) {
        set_root(u);
        t[u].p = v;
    }

    inline int lca(int v, int u) {
        if (v == u) {
            return v;
        }
        expose(v);
        return expose(u);
    }

    inline int dep(int v) {
        expose(v);
        return size(t[v].l);
    }

    inline int dist(int v, int u) {
        int l = lca(v, u);
        return dep(v) + dep(u) - 2 * dep(l);
    }

    inline void add(int v, int d) {
        expose(v);
        t[v].s += d;
        t[v].x += d;
    }

    inline int get(int v, int u) {
        set_root(u);
        expose(v);
        return sum(t[v].l) + t[v].x;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    linkcut t(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        t.link(v - 1, u - 1);
    }
    while (q--) {
        int k, m, r;
        cin >> k >> m >> r;
        r--;
        t.set_root(r);
        vec<int> v(k);
        for (auto &x : v) {
            cin >> x;
            x--;
            t.add(x, 1);
        }
        sort(all(v), [&](int a, int b) { return t.dist(a, r) < t.dist(b, r); });
        vec<mint> dp(m + 1);
        dp[0] = 1;
        vec<mint> ndp(m + 1);
        for (auto x : v) {
            ndp[0] = 0;
            int h = t.get(x, r) - 1;
            for (int i = 1; i <= m; i++) {
                ndp[i] = dp[i - 1];
                ndp[i] += dp[i] * (i - h);
            }
            swap(dp, ndp);
        }
        cout << accumulate(all(dp), mint(0)) << '\n';
        for (auto x : v) {
            t.add(x, -1);
        }
    }
}