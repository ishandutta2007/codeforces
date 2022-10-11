#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

namespace FFT {
    constexpr int MOD = 998'244'353;

    namespace mod_operations {
        int add(int a, int b) {
            a += b;
            return a - MOD * (a >= MOD);
        }

        int sub(int a, int b) {
            a -= b;
            return a + MOD * (a < 0);
        }

        int mult(int a, int b) {
            return int64_t(a) * b % MOD;
        }

        int power(int a, int b) {
            int prod = 1;
            for (; b; b >>= 1, a = mult(a, a))
                if (b & 1)
                    prod = mult(prod, a);

            return prod;
        }

        int rev(int a) {
            return power(a, MOD - 2);
        }

        int div(int a, int b) {
            return mult(a, rev(b));
        }
    } // namespace mod_operations

    void fft(std::vector<int> &a) {
        using namespace mod_operations;

        if (a.empty())
            return;

        static auto get_primitive_root = [&]() {
            if (MOD == 998'244'353)
                return 3;

            std::vector<int> primes;
            int value = MOD - 1;
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
                    if (power(r, (MOD - 1) / p) == 1) {
                        ok = false;
                        break;
                    }

                if (ok)
                    return r;
            }
        };

        static int primitive_root = get_primitive_root();

        int n = int(a.size());
        assert((n & (n - 1)) == 0);
        int lg = std::__lg(n);

        static std::vector<int> reversed_mask;
        if (int(reversed_mask.size()) != n) {
            reversed_mask.resize(n);
            for (int mask = 1; mask < n; mask++)
                reversed_mask[mask] = (reversed_mask[mask >> 1] >> 1) + ((mask & 1) << (lg - 1));
        }

        static std::vector<int> roots;
        if (int(roots.size()) != lg) {
            roots.resize(lg);
            for (int i = 0; i < lg; i++)
                roots[i] = power(primitive_root, (MOD - 1) / (2 << i));
        }

        for (int i = 0; i < n; i++)
            if (reversed_mask[i] < i)
                std::swap(a[i], a[reversed_mask[i]]);

        for (int len = 1; len < n; len <<= 1) {
            int root = roots[std::__lg(len)], current;
            for (int i = 0; i < n; i += (len << 1)) {
                current = 1;
                for (int j = 0; j < len; j++, current = mult(current, root)) {
                    int value = mult(a[i + j + len], current);
                    a[i + j + len] = sub(a[i + j], value);
                    a[i + j] = add(a[i + j], value);
                }
            }
        }
    }

    template<typename T>
    std::vector<int> multiply(T a_begin, T a_end, T b_begin, T b_end) {
        using namespace mod_operations;

        std::vector<int> a(a_begin, a_end);
        std::vector<int> b(b_begin, b_end);
        if (a_begin == a_end || b_begin == b_end)
            return {};

        int real_size = int(a.size() + b.size()) - 1;
        int n = 1;
        while (n < real_size)
            n <<= 1;

        a.resize(n);
        b.resize(n);
        fft(a), fft(b);

        for (int i = 0; i < n; i++)
            a[i] = mult(a[i], b[i]);

        fft(a);
        std::reverse(a.begin() + 1, a.end());

        int rev_n = rev(n);
        a.resize(real_size);
        for (auto &x : a)
            x = mult(x, rev_n);

        return a;
    }
} // namespace FFT

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

    explicit operator int() {
        return value;
    }

    explicit operator long long() {
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
    std::vector<mint> fact;
    std::vector<mint> ifact;
    std::vector<mint> inv;

    void init(int n) {
        fact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i;

        ifact.resize(n + 1);
        ifact.back() = fact.back().inv();
        for (int i = n; i > 0; i--)
            ifact[i - 1] = ifact[i] * i;

        inv.resize(n + 1);
        for (int i = 1; i <= n; i++)
            inv[i] = ifact[i] * fact[i - 1];
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
using factorials::choose;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> deg(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        deg[v - 1]++;
        deg[u - 1]++;
    }

    vector<int> cnt(n);
    for (int i = 0; i < n; i++)
        cnt[deg[i] - (i != 0)]++;

    vector dp{1};
    factorials::init(n);

    vector<pair<int, int>> tot;
    for (int i = 1; i < n; i++)
        if (cnt[i])
            tot.emplace_back(cnt[i], i);

    sort(all(tot));

    for (auto &[c, i] : tot) {
        if (!c)
            continue;

        vector<int> window(c + 1);
        mint pw = 1;
        for (int j = 0; j <= c; j++, pw *= i)
            window[j] = (pw * choose(c, j)).value;

        dp = FFT::multiply(all(dp), all(window));
    }

    mint answer = 0;
    for (int e = 0; e < len(dp); e++) {
        mint cur = dp[e] * fact[n - e];
        if (e & 1)
            answer -= cur;
        else
            answer += cur;
    }

    cout << answer << '\n';
}