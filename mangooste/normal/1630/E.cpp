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
        value++;
        if (value == mod)
            value = 0;

        return *this;
    }

    mint operator--(int) {
        value--;
        if (value == -1)
            value = mod - 1;

        return *this;
    }

    mint operator-() {
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    if (*min_element(all(a)) == *max_element(all(a))) {
        cout << "1\n";
        return;
    }

    vector<int> freq(n);
    for (auto &x : a)
        freq[x - 1]++;

    vector<int> cnt;
    for (auto &x : freq)
        if (x)
            cnt.push_back(x);

    int tot_gcd = 0;
    for (auto &x : cnt)
        tot_gcd = gcd(tot_gcd, x);

    vector<mint> coeff(n + 1);
    for (int i = 2; i <= n; i++)
        coeff[gcd(n, i)]++;

    mint answer = 0, tot = 0;
    for (int len = 2; len <= n; len++) {
        if (n % len || tot_gcd % (n / len))
            continue;

        mint ways = fact[len], sum_pairs = 0, pref = 0;
        for (auto c : cnt) {
            int value = c / (n / len);
            sum_pairs += pref * value;
            pref += value;
            ways *= ifact[value];
        }
        sum_pairs *= 2;

        tot += ways * coeff[len];
        answer += ways * n / len / (len - 1) * sum_pairs * coeff[len];
    }
    cout << answer / tot << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    factorials::init(1e6);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}