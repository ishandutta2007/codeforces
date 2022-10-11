#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<typename T>
int normalize(T value, int mod) {
    if (value < -mod || value >= 2 * mod)
        value %= mod;

    if (value < 0)
        value += mod;

    if (value >= mod)
        value -= mod;

    return value;
}

template<int mod>
struct static_modular_int {
    using mint = static_modular_int<mod>;

    int value;

    static_modular_int() : value(0) {}
    static_modular_int(const mint &x) : value(x.value) {}

    template<typename T, typename U = std::enable_if_t<std::is_integral<T>::value>>
    static_modular_int(T value) : value(normalize(value, mod)) {}

    template<typename T>
    mint power(T degree) const {
        degree = normalize(degree, mod - 1);
        mint prod = 1;
        mint a = *this;

        for (; degree > 0; degree >>= 1, a *= a)
            if (degree & 1)
                prod *= a;

        return prod;
    }

    mint inv() const {
        return power(-1);
    }

    mint& operator=(const mint &x) {
        value = x.value;
        return *this;
    }

    mint& operator+=(const mint &x) {
        value += x.value;
        if (value >= mod)
            value -= mod;

        return *this;
    }

    mint& operator-=(const mint &x) {
        value -= x.value;
        if (value < 0)
            value += mod;

        return *this;
    }

    mint& operator*=(const mint &x) {
        value = (long long) value * x.value % mod;
        return *this;
    }

    mint& operator/=(const mint &x) {
        return *this *= x.inv();
    }

    friend mint operator+(const mint &x, const mint &y) {
        return mint(x) += y;
    }

    friend mint operator-(const mint &x, const mint &y) {
        return mint(x) -= y;
    }

    friend mint operator*(const mint &x, const mint &y) {
        return mint(x) *= y;
    }

    friend mint operator/(const mint &x, const mint &y) {
        return mint(x) /= y;
    }

    mint& operator++() {
        ++value;
        if (value == mod)
            value = 0;

        return *this;
    }

    mint& operator--() {
        --value;
        if (value == -1)
            value = mod - 1;

        return *this;
    }

    mint operator++(int) {
        mint prev = *this;
        value++;
        if (value == mod)
            value = 0;

        return prev;
    }

    mint operator--(int) {
        mint prev = *this;
        value--;
        if (value == -1)
            value = mod - 1;

        return prev;
    }

    mint operator-() const {
        return mint(0) - *this;
    }

    bool operator==(const mint &x) const {
        return value == x.value;
    }

    template<typename T>
    explicit operator T() {
        return value;
    }

    friend std::istream& operator>>(std::istream &in, mint &x) {
        std::string s;
        in >> s;
        x = 0;
        for (const auto c : s)
            x = x * 10 + (c - '0');

        return in;
    }

    friend std::ostream& operator<<(std::ostream &out, const mint &x) {
        return out << x.value;
    }

    static int primitive_root() {
        if constexpr (mod == 1'000'000'007)
            return 5;

        if constexpr (mod == 998'244'353)
            return 3;

        if constexpr (mod == 786433)
            return 10;

        std::vector<int> primes;
        int value = mod - 1;
        for (int i = 2; i * i <= value; i++)
            if (value % i == 0) {
                primes.push_back(i);
                while (value % i == 0)
                    value /= i;
            }

        if (value != 1)
            primes.push_back(value);

        for (int r = 2;; r++) {
            bool ok = true;
            for (auto p : primes)
                if ((mint(r).power((mod - 1) / p)).value == 1) {
                    ok = false;
                    break;
                }

            if (ok)
                return r;
        }
    }
};

// constexpr int MOD = 1'000'000'007;
constexpr int MOD = 998'244'353;
using mint = static_modular_int<MOD>;

namespace combinatorics {
    std::vector<mint> fact_({mint(1), mint(1)});
    std::vector<mint> ifact_({mint(1), mint(1)});
    std::vector<mint> inv_({mint(0), mint(1)});

    void reserve(int size) {
        fact_.reserve(size + 1);
        ifact_.reserve(size + 1);
        inv_.reserve(size + 1);
    }

    void resize(int size) {
        for (int pos = fact_.size(); pos <= size; pos++) {
            fact_.push_back(fact_.back() * mint(pos));
            inv_.push_back(-inv_[MOD % pos] * mint(MOD / pos));
            ifact_.push_back(ifact_.back() * inv_[pos]);
        }
    }

    struct combinatorics_info {
        std::vector<mint> &data;

        combinatorics_info(std::vector<mint> &data) : data(data) {}

        mint operator[](int pos) {
            if (pos >= int(data.size()))
                resize(pos);

            return data[pos];
        }
    } fact(fact_), ifact(ifact_), inv(inv_);

    mint choose(int n, int k) {
        if (n < k || k < 0 || n < 0)
            return mint(0);
 
        return fact[n] * ifact[k] * ifact[n - k];
    }
}

using combinatorics::fact;
using combinatorics::ifact;
using combinatorics::inv;
using combinatorics::choose;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n1, n2, k;
    cin >> n1 >> n2 >> k;
    vector<vector<int>> g1(n1);
    for (int i = 1; i < n1; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g1[v].push_back(u);
        g1[u].push_back(v);
    }

    vector<vector<int>> g2(n2);
    for (int i = 1; i < n2; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g2[v].push_back(u);
        g2[u].push_back(v);
    }

    auto solve = [&](int n, const vector<vector<int>> &g) {
        vector<int> sz(n);
        vector<bool> used(n);
        vector dp1(n, vector<mint>(k + 1)), dp2(n, vector<mint>(k + 1));
        vector<mint> tot(k + 1);

        y_combinator([&](auto dfs, int v) -> void {
            vector<int> vertexes;
            vector<pair<int, int>> edges;

            y_combinator([&](auto dfs, int v, int p) -> void {
                vertexes.push_back(v);
                sz[v] = 1;
                for (auto u : g[v]) {
                    if (u != p && !used[u]) {
                        edges.emplace_back(v, u);
                        dfs(u, v);
                        sz[v] += sz[u];
                    }
                }
            })(v, v);

            const int tot_size = sz[v];

            v = y_combinator([&](auto dfs, int v, int p) -> int {
                for (auto u : g[v]) {
                    if (u != p && !used[u] && (sz[u] << 1) >= tot_size) {
                        return dfs(u, v);
                    }
                }
                return v;
            })(v, v);

            auto solve_dp = [&](vector<vector<mint>> &dp, int banned) {
                for (auto v : vertexes) {
                    fill(all(dp[v]), 0);
                }
                dp[v][0] = 1;
                for (int layer = 1; layer <= k; layer++) {
                    for (auto &[v, u] : edges) {
                        if (v != banned) dp[v][layer] += dp[u][layer - 1];
                        if (u != banned) dp[u][layer] += dp[v][layer - 1];
                    }
                }
            };

            solve_dp(dp1, v);
            solve_dp(dp2, -1);

            y_combinator([&](auto dfs, int v, int p) -> void {
                for (int first = 0; first <= k; first++) {
                    for (int second = 0; second + first <= k; second++) {
                        tot[first + second] += dp1[v][first] * dp2[v][second];
                    }
                }
                for (auto u : g[v]) {
                    if (u != p && !used[u]) {
                        dfs(u, v);
                    }
                }
            })(v, v);

            used[v] = true;
            for (auto u : g[v]) {
                if (!used[u]) dfs(u);
            }
        })(0);

        return tot;
    };

    auto tot1 = solve(n1, g1);
    auto tot2 = solve(n2, g2);

    mint ans = 0;
    for (int first = 0; first <= k; first++) {
        int second = k - first;
        ans += tot1[first] * tot2[second] * choose(k, first);
    }
    cout << ans << '\n';
}