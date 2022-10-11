#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) begin(a), end(a)
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

struct segtree {
    int n;
    vec<vec<pair<int, mint>>> vals;
    vec<vec<mint>> suf_prod;

    segtree(int n) : n(n), vals(2 * n), suf_prod(2 * n) {}

    inline void set(int pos, pair<int, mint> val) {
        pos += n;
        vals[pos] = {val};
    }

    inline void build() {
        for (int v = n - 1; v; v--) {
            vals[v].resize(len(vals[v << 1]) + len(vals[v << 1 | 1]));
            merge(all(vals[v << 1]), all(vals[v << 1 | 1]), vals[v].begin());
        }
        for (int i = 2 * n - 1; i; i--) {
            suf_prod[i].resize(len(vals[i]) + 1, 1);
            for (int j = len(vals[i]) - 1; j >= 0; j--) {
                suf_prod[i][j] = suf_prod[i][j + 1] * vals[i][j].second;
            }
        }
    }

    inline mint get_prod(int l, int r, int x) const {
        mint ans = 1;
        auto relax = [&](int v) {
            ans *= suf_prod[v][lower_bound(all(vals[v]), pair<int, mint>{x, 0}) - vals[v].begin()];
        };
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) relax(l++);
            if (r & 1) relax(--r);
        }
        return ans;
    }
};

struct item {
    int bal1, bal2;
    mint prod;

    inline bool operator<(const item &i) const {
        if (bal1 != i.bal1) return bal1 < i.bal1;
        if (bal2 != i.bal2) return bal2 < i.bal2;
        return prod < i.prod;
    }
};

const int N = 1e5 + 5;
vec<ar<int, 3>> g[N];
int n, cur, sz[N];
bool used[N];
mint ans = 1;

void dfs_sz(int v, int par) {
    sz[v] = 1;
    for (auto &[u, x, type] : g[v]) {
        if (u == par || used[u]) continue;
        dfs_sz(u, v);
        sz[v] += sz[u];
    }
}

int dfs_cen(int v, int par, int n) {
    for (auto &[u, x, type] : g[v]) {
        if (u == par || used[u]) continue;
        if (sz[u] * 2 < n) continue;
        return dfs_cen(u, v, n);
    }
    return v;
}

void dfs_add(int v, int par, vec<item> &vals, int bal1, int bal2, mint prod) {
    vals.push_back({bal1, bal2, prod});
    for (auto &[u, x, type] : g[v]) {
        if (u == par || used[u]) continue;
        int nbal1 = bal1 + (type ? 1 : -1);
        int nbal2 = bal2 + (type ? -1 : 2);
        dfs_add(u, v, vals, nbal1, nbal2, prod * x);
    }
}

inline segtree get_tree(vec<item> &vals) {
    sort(all(vals));
    segtree tree(len(vals));
    for (int i = 0; i < len(vals); i++) {
        tree.set(i, {vals[i].bal2, vals[i].prod});
    }
    tree.build();
    return tree;
}

inline int get_pos(const vec<item> &vals, int bal1) {
    return lower_bound(all(vals), item{-bal1 + cur, INT_MIN, 0}) - vals.begin();
}

void dfs_solve(int v, int par, const vec<item> &vals, const segtree &tree, int bal1, int bal2, mint prod, bool add) {
    int pos = get_pos(vals, bal1);
    auto res = tree.get_prod(pos, tree.n, -bal2);
    if (add) {
        ans *= res;
    } else {
        ans /= res;
    }
    for (auto &[u, x, type] : g[v]) {
        if (u == par || used[u]) continue;
        int nbal1 = bal1 + (type ? 1 : -1);
        int nbal2 = bal2 + (type ? -1 : 2);
        dfs_solve(u, v, vals, tree, nbal1, nbal2, prod * x, add);
    }
}

void main_dfs(int v) {
    dfs_sz(v, v);
    v = dfs_cen(v, v, sz[v]);
    used[v] = 1;
    dfs_sz(v, v);
    {
        vec<item> vals;
        vals.reserve(sz[v]);
        dfs_add(v, v, vals, 0, 0, 1);
        auto tree = get_tree(vals);
        dfs_solve(v, v, vals, tree, 0, 0, 1, 1);
    }
    for (auto &[u, x, type] : g[v]) {
        if (used[u]) continue;
        vec<item> vals;
        vals.reserve(sz[u]);
        dfs_add(u, v, vals, (type ? 1 : -1), (type ? -1 : 2), x);
        auto tree = get_tree(vals);
        dfs_solve(u, v, vals, tree, (type ? 1 : -1), (type ? -1 : 2), x, 0);
    }
    for (auto &[u, x, type] : g[v]) {
        if (!used[u]) main_dfs(u);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int v, u, x, type;
        cin >> v >> u >> x >> type, v--, u--;
        g[v].push_back({u, x, type});
        g[u].push_back({v, x, type});
    }
    for (cur = 0; cur < 2; cur++) {
        fill(all(used), 0);
        main_dfs(0);
        for (int i = 0; i < n; i++) {
            for (auto &a : g[i]) {
                a[2] ^= 1;
            }
        }
    }
    cout << ans << '\n';
}