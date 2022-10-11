#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
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

    explicit operator int() {
        return value;
    }

    explicit operator long long() {
        return value;
    }

    friend istream& operator>>(istream &in, mint &x) {
        std::string s;
        cin >> s;

        x = 0;
        for (const auto c : s)
            x = x * 10 + (c - '0');

        return in;
    }

    friend ostream& operator<<(ostream &out, const mint &x) {
        return out << x.value;
    }
};

constexpr int MOD = 1'000'000'007;
// constexpr int MOD = 998'244'353;
using mint = static_modular_int<MOD>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    const int MASK = 1 << n;
    vector<mint> dp(MASK);

    for (int i = 0; i < n; i++) {
        int mask = 1 << i;
        dp[mask] = 1;

        for (int j = 0; j < n; j++)
            if (i != j)
                dp[mask] *= mint(a[i]) / (a[i] + a[j]);
    }

    for (int mask = 1; mask < MASK; mask++) {
        if (__builtin_popcount(mask) == 1)
            continue;

        vector<mint> prob(n, 1);
        for (int i = 0; i < n; i++)
            if (mask >> i & 1)
                for (int j = 0; j < n; j++)
                    if (!(mask >> j & 1))
                        prob[i] *= mint(a[i]) / (a[i] + a[j]);

        dp[mask] = 1;
        for (int i = 0; i < n; i++)
            if (mask >> i & 1)
                dp[mask] *= prob[i];

        for (int submask = mask & (mask - 1); submask > 0; submask = (submask - 1) & mask) {
            mint coeff = 1;
            for (int i = 0; i < n; i++)
                if ((mask >> i & 1) && !(submask >> i & 1))
                    coeff *= prob[i];

            dp[mask] -= dp[submask] * coeff;
        }
    }

    mint answer = 0;
    for (int mask = 1; mask < MASK; mask++)
        answer += __builtin_popcount(mask) * dp[mask];

    cout << answer << '\n';
}