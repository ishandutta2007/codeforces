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

        static int root = -1;
        if (root != -1)
            return root;

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
                return root = r;
        }
    }
};

// constexpr int MOD = 1'000'000'007;
constexpr int MOD = 998'244'353;
using mint = static_modular_int<MOD>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    cin >> s;
    int n = len(s);

    int good[2][2][2];
    for (int a : {0, 1}) {
        for (int b : {0, 1}) {
            for (int c : {0, 1}) {
                good[a][b][c] = 0;
                if ((a ^ b) & (a ^ c)) good[a][b][c] |= 1 << 0;
                if ((b ^ a) & (b ^ c)) good[a][b][c] |= 1 << 1;
                if ((c ^ a) & (c ^ b)) good[a][b][c] |= 1 << 2;
            }
        }
    }

    array<array<mint, 1 << 3>, 1 << 3> zeroes, dp, new_dp;
    zeroes.fill(array<mint, 1 << 3>{});
    dp = new_dp = zeroes;
    dp[0][(1 << 3) - 1] = 1;

    for (int i = 0; i < n; i++) {
        new_dp = zeroes;
        for (int prev_mask = 0; prev_mask < (1 << 3); prev_mask++) {
            for (int pref = 0; pref < (1 << 3); pref++) {
                auto bit = [&](int mask, int pos) {
                    return mask >> pos & 1;
                };
                auto reset_bit = [&](int &mask, int pos) {
                    if (bit(mask, pos)) mask ^= 1 << pos;
                };

                for (int a : {0, 1}) {
                    if (a > s[i] - '0' && bit(pref, 0)) break;
                    for (int b : {0, 1}) {
                        if (b > s[i] - '0' && bit(pref, 1)) break;
                        for (int c : {0, 1}) {
                            if (c > s[i] - '0' && bit(pref, 2)) break;
                            int new_pref = pref;
                            if (s[i] == '1') {
                                if (!a) reset_bit(new_pref, 0);
                                if (!b) reset_bit(new_pref, 1);
                                if (!c) reset_bit(new_pref, 2);
                            }
                            new_dp[prev_mask | good[a][b][c]][new_pref] += dp[prev_mask][pref];
                        }
                    }
                }
            }
        }
        dp.swap(new_dp);
    }
    cout << accumulate(all(dp[(1 << 3) - 1]), mint(0)) << '\n';
}