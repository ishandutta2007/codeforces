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

template<typename T>
void hadamard_transformation(std::vector<T> &a) {
    int n = a.size();
    assert(!(n & (n - 1)));
    for (int length = 1; length < n; length <<= 1)
        for (int i = 0; i < n; i += length << 1)
            for (int j = 0; j < length; j++) {
                T v = a[i + j], u = a[i + length + j];
                a[i + j] = v + u;
                a[i + length + j] = v - u;
            }
}

template<typename result_t, typename T1, typename T2>
std::vector<result_t> hadamard(T1 a_begin, T1 a_end, T2 b_begin, T2 b_end) {
    if (a_begin == a_end || b_begin == b_end)
        return {};

    std::vector<result_t> a(a_begin, a_end);
    std::vector<result_t> b(b_begin, b_end);
    int n = std::max(a.size(), b.size());
    while (n & (n - 1))
        n++;

    a.resize(n);
    b.resize(n);
    hadamard_transformation(a);
    hadamard_transformation(b);
    for (int i = 0; i < n; i++)
        a[i] *= b[i];

    hadamard_transformation(a);
    for (auto &x : a)
        x /= n;

    return a;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    int initial_m = m;
    m = max(m, 2);
    if (m & 1) m++;

    vector<ll> gauss(m, -1);
    auto add_value = [&](ll value) {
        while (value) {
            int bit = __lg(value);
            if (gauss[bit] == -1) gauss[bit] = value;
            value ^= gauss[bit];
        }
    };

    for (auto x : a) add_value(x);
    int bases = m - count(all(gauss), -1);

    const int half = m / 2;
    vector cnt(half + 1, vector<ll>(1 << half));
    for (int mask = 0; mask < (1 << half); mask++) {
        bool fail = false;
        for (int i = 0; i < half; i++) {
            if (mask >> i & 1) fail |= gauss[half + i] == -1;
        }
        if (fail) continue;

        ll x = 0;
        for (int i = 0; i < half; i++) {
            if (mask >> i & 1) x ^= gauss[half + i];
        }
        int high = x >> half, low = x & ((1 << half) - 1);
        cnt[__builtin_popcount(high)][low]++;
    }

    vector<int> possible(1 << half);
    for (int mask = 0; mask < (1 << half); mask++) {
        bool fail = false;
        for (int i = 0; i < half; i++) {
            if (mask >> i & 1) fail |= gauss[i] == -1;
        }
        if (fail) continue;

        int x = 0;
        for (int i = 0; i < half; i++) {
            if (mask >> i & 1) x ^= gauss[i];
        }
        assert(!possible[x]);
        possible[x] = 1;
    }

    vector<ll> ans(m + 1);
    for (int bits = 0; bits <= half; bits++) {
        auto res = hadamard<ll>(all(cnt[bits]), all(possible));
        for (int i = 0; i < len(res); i++) {
            ans[bits + __builtin_popcount(i)] += res[i];
        }
    }

    mint to_mult = mint(2).power(n - bases);
    for (int i = 0; i <= initial_m; i++) {
        cout << ans[i] * to_mult << " \n"[i == initial_m];
    }
}