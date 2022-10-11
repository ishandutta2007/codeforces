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
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &[x, y] : a) cin >> x >> y;

    auto dist = [](const pair<int, int> &a, const pair<int, int> &b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    };

    vector<int> mn(n, 1e9);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            mn[i] = min(mn[i], dist(a[i], a[j]));
        }
    }

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](const int i, const int j) {
        return mn[i] < mn[j];
    });

    array<int, 5> cnt{};
    vector<bool> used(n);
    for (auto i : ord) {
        if (used[i]) continue;
        vector<int> vers;

        y_combinator([&](auto dfs, int v) -> void {
            used[v] = true;
            vers.push_back(v);
            for (int u = 0; u < n; u++) {
                if (used[u]) continue;
                if (dist(a[v], a[u]) == mn[v]) {
                    dfs(u);
                }
            }
        })(i);

        if (len(vers) == 1) continue;
        int dist_need = mn[i];
        bool ok = true;
        for (int i = 0; i < len(vers); i++) {
            for (int j = 0; j < n; j++) {
                if (j == vers[i]) continue;
                if (count(all(vers), j)) continue;
                ok &= dist(a[vers[i]], a[j]) > dist_need;
            }
            for (int j = i + 1; j < len(vers); j++) {
                ok &= dist_need == dist(a[vers[i]], a[vers[j]]);
            }
        }
        if (!ok) continue;

        assert(len(vers) <= 4);
        cnt[len(vers)]++;
    }

    mint ans = 0;
    for (int take2 = 0; take2 <= cnt[2]; take2++) {
        for (int take3 = 0; take3 <= cnt[3]; take3++) {
            for (int take4 = 0; take4 <= cnt[4]; take4++) {
                int tot = take2 + take3 + take4 + (n - 2 * take2 - 3 * take3 - 4 * take4);
                ans += choose(cnt[2], take2) * choose(cnt[3], take3) * choose(cnt[4], take4) * choose(n, tot) * fact[tot];
            }
        }
    }
    cout << ans << '\n';
}