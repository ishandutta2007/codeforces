#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

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

    explicit mval() : val(0) {}
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

    inline friend mval operator+(const mval a, const mval b) { return mval(a) += b; }
    inline friend mval operator-(const mval a, const mval b) { return mval(a) -= b; }
    inline friend mval operator*(const mval a, const mval b) { return mval(a) *= b; }
    inline friend mval operator/(const mval a, const mval b) { return mval(a) /= b; }

    inline mval& operator++() { ++val; if (val == mod) val = 0; return *this; }
    inline mval& operator++(int) { val++; if (val == mod) val = 0; return *this; }
    inline mval& operator--() { --val; if (val == -1) val = mod - 1; return *this; }
    inline mval& operator--(int) { val--; if (val == -1) val = mod - 1; return *this; }

    inline bool operator==(const mval m) const { return val == m.val; }
    inline bool operator!=(const mval m) const { return val != m.val; }
    inline bool operator<(const mval m) const { return val < m.val; }
    inline bool operator>(const mval m) const { return val > m.val; }

    friend istream& operator>>(istream &in, mval &m) { long long x; in >> x; m = mval(x); return in; }
    friend ostream& operator<<(ostream &out, mval m) { return out << m.val; }
};

// constexpr int MOD = 1'000'000'007;
constexpr int MOD = 998'244'353;
using mint = mval<MOD>;

inline int min(int a, int b) {
    return a < b ? a : b;
}

int n, k;
vec<vec<int>> g;
vec<vec<mint>> dp;

int solve(int v, int par) {
    if (v)
        g[v].erase(find(all(g[v]), par));
    int sz = 1;
    for (auto u : g[v])
        sz += solve(u, v);

    int size = min(k + 1, sz);
    dp[v].resize(size);
    vec<vec<mint>> pref_sums(len(g[v]));
    for (int i = 0; i < len(g[v]); i++) {
        int u = g[v][i];
        pref_sums[i].resize(len(dp[u]) + 1);
        pref_sums[i][0] = 0;
        for (int j = 0; j < len(dp[u]); j++)
            pref_sums[i][j + 1] = pref_sums[i][j] + dp[u][j];
        for (auto &x : pref_sums[i])
            x += pref_sums[i].back();
    }

    vec<mint> prod(size, mint(1));
    for (int i = 0; i < len(g[v]); i++) {
        int u = g[v][i];
        for (int j = 0; j < len(dp[u]) && j + 1 < size; j++) {
            int mx = k - (j + 1);
            dp[u][j] *= prod[min(min(j, mx), size - 1)];
        }
        for (int j = 0; j < size; j++)
            prod[j] *= pref_sums[i][min(j, len(dp[u]))];
    }
    fill(all(prod), mint(1));
    for (int i = len(g[v]) - 1; i >= 0; i--) {
        int u = g[v][i];
        for (int j = 0; j < len(dp[u]) && j + 1 < size; j++) {
            int mx = k - (j + 1);
            dp[v][j + 1] += dp[u][j] * prod[min(min(mx, j + 1), size - 1)];
        }
        for (int j = 0; j < size; j++)
            prod[j] *= pref_sums[i][min(j, len(dp[u]))];
    }

    dp[v][0] = 1;
    for (int i = 0; i < len(g[v]); i++)
        dp[v][0] *= pref_sums[i][0];
    dp[v][0]++;
    ++dp[v][0];
    dp[v][0]--;
    --dp[v][0];
    return sz;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> k;
    g.resize(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dp.resize(n);
    solve(0, 0);
    cout << accumulate(all(dp[0]), mint(0)) << '\n';
}