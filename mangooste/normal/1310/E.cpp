#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    if (k == 1) {
        vector<mint> dp(n + 1);
        dp[0] = 1;
        for (int x = 1; x <= n; x++) {
            for (int y = x; y <= n; y++) {
                dp[y] += dp[y - x];
            }
        }
        cout << accumulate(all(dp), mint(0)) - 1 << '\n';
        return 0;
    }

    if (k == 2) {
        vector dp(n + 1, vector<mint>(n + 1));
        dp[0][0] = 1;
        for (int value = n; value >= 1; value--) {
            for (int new_sum = 0; new_sum <= n; new_sum++) {
                for (int new_cnt = 1; value * new_cnt <= new_sum; new_cnt++) {
                    int prev_sum = new_sum - value * new_cnt;
                    dp[new_sum][new_cnt] += dp[prev_sum][new_cnt - 1];
                }
            }
        }

        mint ans = 0;
        for (auto &v : dp) {
            ans += accumulate(all(v), mint(0));
        }
        cout << ans - 1 << '\n';
        return 0;
    }

    mint ans = 0;
    vector<int> st;

    y_combinator([&](auto rec, int x, int y, int already, int pref_sum) -> void {
        if (x == 0) {
            auto a = st;
            reverse(all(a));
            for (int cnt = 0; cnt < k - 2; cnt++) {
                vector<int> b;
                for (int i = len(a) - 1; i >= 0; i--) {
                    for (int j = 0; j < a[i]; j++) {
                        b.push_back(len(a) - i);
                    }
                }

                a = b;
                int tot = 0;
                for (int i = len(a) - 1; i >= 0; i--) {
                    tot += a[i] * (len(a) - i);
                    if (tot > n) return;
                }
            }
            ans++;
            return;
        }

        rec(x - 1, y, already, pref_sum);
        
        ll cur = already;
        cur += (x * (x + 1) / 2) * y;
        cur += pref_sum * x;
        if (cur > n) return;

        st.push_back(x);
        rec(x, y + 1, cur, pref_sum + x * y);
        st.pop_back();
    })(n, 1, 0, 0);

    cout << ans - 1 << '\n';
}