#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
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

template<typename Fun>
class y_combinator {
    const Fun _fun;
public:
    explicit y_combinator(const Fun&& fun) : _fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    inline decltype(auto) operator()(Args&&... args) const {
        return _fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    vector<vector<mint>> dp(n, vector<mint>(n));
    for (int i = 1; i < n; i++)
        dp[0][i] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) * mint(2).rev();

    mint answer = 0;
    for (int root = 0; root < n; root++) {
        vector<int> tin(n);
        vector<int> tout(n);
        int timer = 0;
        vector<int> parent(n, -1);
        vector<int> dep(n);

        y_combinator([&](auto dfs, int v) -> void {
            tin[v] = timer++;
            for (auto u : g[v])
                if (u != parent[v]) {
                    parent[u] = v;
                    dep[u] = dep[v] + 1;
                    dfs(u);
                }

            tout[v] = timer;
        })(root);

        vector<vector<int>> lca(n, vector<int>(n, -1));

        auto is_parent = [&](int v, int u) {
            return tin[v] <= tin[u] && tout[u] <= tout[v];
        };

        auto get_lca = y_combinator([&](auto get_lca, int v, int u) -> int {
            int& l = lca[v][u];
            if (l != -1)
                return l;

            if (is_parent(v, u))
                return l = v;

            if (is_parent(u, v))
                return l = u;

            return l = get_lca(parent[v], u);
        });
 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++) {
                int l = get_lca(i, j);
                answer += dp[dep[i] - dep[l]][dep[j] - dep[l]];
            }
    }

    cout << answer / n << '\n';
}