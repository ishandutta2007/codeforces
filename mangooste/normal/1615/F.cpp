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

constexpr int MOD = 1'000'000'007;
// constexpr int MOD = 998'244'353;
using mint = static_modular_int<MOD>;

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i += 2) {
        if (s[i] != '?') s[i] ^= '0' ^ '1';
        if (t[i] != '?') t[i] ^= '0' ^ '1';
    }

    vector<mint> dp(n + 1), cnt(n + 1);
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        if (t[i] == '1') break;
        cnt[i + 1] = 1;
    }

    vector<int> nxt(n, n);
    for (int i = n - 2; i >= 0; i--) {
        if (t[i + 1] == '1') nxt[i] = i + 1;
        else nxt[i] = nxt[i + 1];
    }

    for (int i = 0; i < n; i++) {
        vector<mint> new_dp(n + 1), new_cnt(n + 1);
        if (s[i] != '0') {
            vector<mint> pref_dp(n + 2), pref_cnt(n + 2);
            for (int pos = 0; pos < n; pos++) {
                if (t[pos] == '0') continue;
                mint delta_dp = dp[pos] + cnt[pos] * abs(i - pos);
                pref_dp[pos + 1] += delta_dp;
                pref_dp[nxt[pos] + 1] -= delta_dp;
                pref_cnt[pos + 1] += cnt[pos];
                pref_cnt[nxt[pos] + 1] -= cnt[pos];
            }

            for (int i = 0; i <= n; i++) {
                pref_dp[i + 1] += pref_dp[i];
                pref_cnt[i + 1] += pref_cnt[i];
                new_dp[i] += pref_dp[i];
                new_cnt[i] += pref_cnt[i];
            }
        }

        if (s[i] != '1') {
            for (int i = 0; i <= n; i++) {
                new_dp[i] += dp[i];
                new_cnt[i] += cnt[i];
            }
        }

        dp = new_dp;
        cnt = new_cnt;
    }
    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}