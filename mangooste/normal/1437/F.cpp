#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

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

    template<typename T>
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

    template<typename T>
    explicit operator T() {
        return value;
    }

    friend istream& operator>>(istream &in, mint &x) {
        std::string s;
        in >> s;

        x = 0;
        for (const auto c : s)
            x = x * 10 + (c - '0');

        return in;
    }

    friend ostream& operator<<(ostream &out, const mint &x) {
        return out << x.value;
    }
};

// constexpr int MOD = 1'000'000'007;
constexpr int MOD = 998'244'353;
using mint = static_modular_int<MOD>;

namespace factorials {
    std::vector<mint> fact, ifact, inv, p2;

    void init(int n) {
        fact.assign(n + 1, mint(1));
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i;

        ifact.resize(n + 1);
        ifact.back() = fact.back().inv();
        for (int i = n; i > 0; i--)
            ifact[i - 1] = ifact[i] * i;

        inv.resize(n + 1);
        for (int i = 1; i <= n; i++)
            inv[i] = ifact[i] * fact[i - 1];

        p2.assign(n + 1, mint(1));
        for (int i = 1; i <= n; i++)
            p2[i] = p2[i - 1] + p2[i - 1];
    }

    mint choose(int n, int k) {
        if (n < k || k < 0 || n < 0)
            return 0;

        return fact[n] * ifact[k] * ifact[n - k];
    }
} // namespace factorials

using factorials::fact;
using factorials::ifact;
using factorials::inv;
using factorials::p2;
using factorials::choose;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(all(a));

    vector dp(n, vector<mint>(n + 1));
    dp[0][0] = 1;
    dp[0][1] = 1;
    factorials::init(n);

    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1];
        int pos = upper_bound(all(a), a[i] / 2) - a.begin();
        if (pos == 0) {
            dp[i][1]++;
            continue;
        }

        auto pref = dp[pos - 1];
        for (int i = 0; i <= pos; i++) {
            pref[i] *= fact[pos - i];
        }
        for (int i = 1; i <= pos; i++) {
            pref[i] += pref[i - 1];
        }
        for (int cur = 1; cur <= pos + 1; cur++) {
            dp[i][cur] += pref[cur - 1] * ifact[pos - cur + 1];
        }
    }
    cout << dp[n - 1][n] << '\n';
}