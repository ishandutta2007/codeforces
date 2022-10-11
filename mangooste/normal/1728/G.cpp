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
    #define dprint(...)
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

    bool operator!=(const mint &x) const {
        return value != x.value;
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

    int d, n, m;
    cin >> d >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    sort(all(a));
    sort(all(b));

    b.insert(b.begin(), -d);
    b.push_back(2 * d);
    m += 2;

    vector<mint> dp_left(m), dp_right(m);
    for (int rot : {0, 1}) {
        vector<int> right(n);
        for (int i = 0; i < n; i++) {
            right[i] = lower_bound(all(b), a[i]) - b.begin();
        }

        auto &cur = rot == 0 ? dp_left : dp_right;
        vector<mint> dp(m), ndp(m), aux(m + 1), pref(m + 1);
        for (int limit = 0; limit < m; limit++) {
            fill(all(dp), 0);
            dp[1] = 1;
            for (int i = 0; i < n && a[i] < b[limit]; i++) {
                fill(all(ndp), 0);
                fill(all(aux), 0);
                for (int i = 0; i < m; i++) {
                    pref[i + 1] = pref[i] + dp[i];
                }

                for (int i1 = right[i] - 1, i2 = right[i], last_d = 0;;) {
                    int d1 = i1 == -1 ? 1e9 : a[i] - b[i1];
                    int d2 = i2 == limit + 1 ? 1e9 : b[i2] - a[i];
                    int can = max(0, min({d + 1, d1, d2}) - last_d);

                    if (i1 >= 0) {
                        aux[0] += can;
                        aux[i1 + 1] -= can;
                    }
                    if (i1 + 1 <= i2) {
                        ndp[i2] += (pref[i2 + 1] - pref[i1 + 1]) * can;
                    }
                    if (i2 < limit) {
                        aux[i2 + 1] += can;
                    }

                    if (d1 <= d2) {
                        last_d = d1;
                        i1--;
                    } else {
                        last_d = d2;
                        i2++;
                        if (i2 == limit + 1) break;
                    }
                }

                for (int i = 0; i < m; i++) {
                    if (i) aux[i] += aux[i - 1];
                    ndp[i] += dp[i] * aux[i];
                }
                dp.swap(ndp);
            }
            cur[limit] = dp[limit];
        }

        for (auto &x : a) x *= -1;
        reverse(all(a));
        for (auto &x : b) x *= -1;
        reverse(all(b));
    }
    reverse(all(dp_right));

    vector dp_seg(m, vector<mint>(m));
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            dp_seg[i][j] = 1;
            for (int id = 0; id < n; id++) {
                if (a[id] < b[i] || a[id] > b[j]) continue;
                dp_seg[i][j] *= min({d + 1, a[id] - b[i], b[j] - a[id]});
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        mint ans = (d + 1) * dp_left[m - 1];
        for (int i = 1; i < m - 1; i++) {
            for (int j = i; j < m - 1; j++) {
                ans += dp_seg[i][j] * max(0, d + 1 - max(abs(x - b[i]), abs(x - b[j]))) * dp_left[i] * dp_right[j];
            }
        }
        cout << ans << '\n';
    }
}