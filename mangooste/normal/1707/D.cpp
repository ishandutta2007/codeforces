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

template<typename T>
struct nonstatic_modular_int {
    using mint = nonstatic_modular_int<T>;

    int value;

    nonstatic_modular_int() : value(0) {}
    nonstatic_modular_int(const mint &x) : value(x.value) {}

    template<typename U, typename V = std::enable_if_t<std::is_integral<U>::value>>
    nonstatic_modular_int(U value) : value(normalize(value, T::mod)) {}

    template<typename U>
    mint power(U degree) const {
        degree = normalize(degree, T::mod - 1);
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
        if (value >= T::mod)
            value -= T::mod;

        return *this;
    }

    mint& operator-=(const mint &x) {
        value -= x.value;
        if (value < 0)
            value += T::mod;

        return *this;
    }

    mint& operator*=(const mint &x) {
        value = (long long) value * x.value % T::mod;
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
        if (value == T::mod)
            value = 0;

        return *this;
    }

    mint& operator--() {
        --value;
        if (value == -1)
            value = T::mod - 1;

        return *this;
    }

    mint operator++(int) {
        mint prev = *this;
        value++;
        if (value == T::mod)
            value = 0;

        return prev;
    }

    mint operator--(int) {
        mint prev = *this;
        value--;
        if (value == -1)
            value = T::mod - 1;

        return prev;
    }

    mint operator-() const {
        return mint(0) - *this;
    }

    bool operator==(const mint &x) const {
        return value == x.value;
    }

    template<typename U>
    explicit operator U() {
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
        if constexpr (T::mod == 1'000'000'007)
            return 5;

        if constexpr (T::mod == 998'244'353)
            return 3;

        if constexpr (T::mod == 786433)
            return 10;

        static int root = -1;
        if (root != -1)
            return root;

        std::vector<int> primes;
        int value = T::mod - 1;
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
                if ((mint(r).power((T::mod - 1) / p)).value == 1) {
                    ok = false;
                    break;
                }

            if (ok)
                return root = r;
        }
    }
};

struct nonstatic_modular_int_mod {
    static int mod;
};

int nonstatic_modular_int_mod::mod = 0;
int &mod = nonstatic_modular_int_mod::mod;

using mint = nonstatic_modular_int<nonstatic_modular_int_mod>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n >> mod;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    vector choose(n, vector<mint>(n));
    for (int i = 0; i < n; i++) {
        choose[i][0] = choose[i][i] = 1;
        for (int j = 1; j < i; j++) {
            choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
        }
    }

    vector dp(n, vector<mint>(n));

    y_combinator([&](auto dfs, int v) -> void {
        if (g[v].empty()) {
            for (int i = 1; i < n; i++) dp[v][i] = 1;
            return;
        }

        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            dfs(u);
        }

        const int m = len(g[v]);
        vector<mint> pref(m), to_mult(m), pref_prod(m + 1, 1), suf_prod(m + 1, 1);
        for (int when = 1; when < n; when++) {
            for (int i = 0; i < m; i++) {
                pref[i] += dp[g[v][i]][when];
            }

            for (int i = 0; i < m; i++) {
                pref_prod[i + 1] = pref_prod[i] * pref[i];
            }
            for (int i = m - 1; i >= 0; i--) {
                suf_prod[i] = suf_prod[i + 1] * pref[i];
            }

            dp[v][when] += pref_prod.back();
            if (!v) continue;

            for (int i = 0; i < m; i++) {
                dp[v][when] += dp[g[v][i]][when] * to_mult[i];
                to_mult[i] += pref_prod[i] * suf_prod[i + 1];
            }
        }
        
        if (!v) {
            vector<mint> ans(n);
            for (int when = 1; when < n; when++) {
                ans[when] = dp[v][when];
                for (int i = 1; i < when; i++) ans[when] -= ans[i] * choose[when][i];
            }
            for (int i = 1; i < n; i++) {
                cout << ans[i] << " \n"[i == n - 1];
            }
        }
    })(0);
}