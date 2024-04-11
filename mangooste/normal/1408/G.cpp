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

template<typename T>
int normalize(T val, int mod) {
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

    mval power(long long deg) const {
        deg = normalize(deg, mod - 1);
        mval prod = 1;
        mval a = *this;
        for (; deg; deg >>= 1, a *= a)
            if (deg & 1)
                prod *= a;
        return prod;
    }
    mval rev() const { return power(-1); }

    mval& operator+=(const mval m) { val += m.val; if (val >= mod) val -= mod; return *this; }
    mval& operator-=(const mval m) { val -= m.val; if (val < 0) val += mod; return *this; }
    mval& operator*=(const mval m) { val = 1ll * val * m.val % mod; return *this; }
    mval& operator/=(const mval m) { val = 1ll * val * m.rev().val % mod; return *this; }
    template<typename T> mval& operator=(const T x) { *this = mval(x); return *this; }

    friend mval operator+(const mval a, const mval b) { return mval(a) += b; }
    friend mval operator-(const mval a, const mval b) { return mval(a) -= b; }
    friend mval operator*(const mval a, const mval b) { return mval(a) *= b; }
    friend mval operator/(const mval a, const mval b) { return mval(a) /= b; }

    mval& operator++() { ++val; if (val == mod) val = 0; return *this; }
    mval operator++(int) { val++; if (val == mod) val = 0; return *this; }
    mval& operator--() { --val; if (val == -1) val = mod - 1; return *this; }
    mval operator--(int) { val--; if (val == -1) val = mod - 1; return *this; }

    bool operator==(const mval m) const { return val == m.val; }
    bool operator!=(const mval m) const { return val != m.val; }
    bool operator<(const mval m) const { return val < m.val; }
    bool operator>(const mval m) const { return val > m.val; }

    friend istream& operator>>(istream &in, mval &m) { long long x; in >> x; m = mval(x); return in; }
    friend ostream& operator<<(ostream &out, const mval m) { return out << m.val; }
};

// constexpr int MOD = 1'000'000'007;
constexpr int MOD = 998'244'353;
using mint = mval<MOD>;

template<typename Fun>
class y_combinator {
    const Fun fun_;
public:
    explicit y_combinator(const Fun&& fun) : fun_(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    decltype(auto) operator()(Args&&... args) const {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> pairs;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (i < j)
                pairs.emplace_back(i, j);
        }

    sort(all(pairs), [&](const pair<int, int> &x, const pair<int, int> &y) {
        return a[x.first][x.second] < a[y.first][y.second];
    });

    vector<int> parent(n);
    iota(all(parent), 0);
    vector<vector<mint>> dp(n, {0, 1});
    vector<int> count_edges(n);
    vector<int> size(n, 1);

    auto root = y_combinator([&](auto root, int v) -> int {
        return parent[v] == v ? v : parent[v] = root(parent[v]);
    });

    auto unite = [&](int v, int u) {
        v = root(v);
        u = root(u);

        if (v == u) {
            count_edges[v]++;
            if (count_edges[v] == size[v] * (size[v] - 1) / 2)
                dp[v][1]++;

            return;
        }

        if (size[v] < size[u])
            swap(v, u);

        parent[u] = v;
        size[v] += size[u];
        count_edges[v] += count_edges[u] + 1;

        vector<mint> new_dp(len(dp[v]) + len(dp[u]) - 1);
        if (count_edges[v] == size[v] * (size[v] - 1) / 2)
            new_dp[1]++;

        for (int left = 0; left < len(dp[v]); left++)
            for (int right = 0; right < len(dp[u]); right++)
                new_dp[left + right] += dp[v][left] * dp[u][right];

        dp[v] = new_dp;
    };

    for (const auto &[i, j] : pairs)
        unite(i, j);

    int last = root(0);
    for (int i = 1; i <= n; i++)
        cout << dp[last][i] << " \n"[i == n];
}