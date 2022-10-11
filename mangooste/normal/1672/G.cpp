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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &s : a) cin >> s;

    if (n % 2 == 0 && m % 2 == 0) {
        mint ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '?') ans *= 2;
            }
        }
        cout << ans << '\n';
        return 0;
    }

    if (n % 2 && m % 2) {
        vector<vector<int>> g(n + m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '?') {
                    g[i].push_back(j + n);
                    g[j + n].push_back(i);
                }
            }
        }

        mint ans = 0;
        for (int x : {0, 1}) {
            vector<int> need(n + m, x);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == '1') {
                        need[i] ^= 1;
                        need[j + n] ^= 1;
                    }
                }
            }

            vector<bool> used(n + m);
            mint cur = 1;
            for (int v = 0; v < n + m; v++) {
                if (used[v]) continue;
                int vers = 0, edges = 0, tot_xor = 0;

                y_combinator([&](auto dfs, int v) -> void {
                    used[v] = true;
                    vers++;
                    edges += len(g[v]);
                    tot_xor ^= need[v];
                    for (auto u : g[v]) {
                        if (!used[u]) dfs(u);
                    }
                })(v);

                edges >>= 1;
                if (tot_xor) {
                    cur = 0;
                    break;
                }
                cur *= mint(2).power(edges - (vers - 1));
            }
            ans += cur;
        }

        cout << ans << '\n';
        return 0;
    }

    if (n % 2) {
        vector<string> b(m, string(n, '.'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[j][i] = a[i][j];
            }
        }
        swap(a, b);
        swap(n, m);
    }
    assert(n % 2 == 0 && m % 2 == 1);

    mint ans = 0;
    for (int x : {0, 1}) {
        array<mint, 2> dp{0, 0};
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            int need = x, tot = 0;
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '?') {
                    tot++;
                } else if (a[i][j] == '1') {
                    need ^= 1;
                    swap(dp[0], dp[1]);
                }
            }
            
            mint coeff;
            if (tot == 0) {
                coeff = need ? 0 : 1;
            } else {
                coeff = mint(2).power(tot - 1);
            }

            if (need) swap(dp[0], dp[1]);
            dp[0] *= coeff;
            dp[1] *= coeff;
        }
        ans += dp[0];
    }
    cout << ans << '\n';
}