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

namespace combinatorics {
    std::vector<mint> fact_, ifact_, inv_;

    void reserve(int size) {
        fact_.reserve(size + 1);
        ifact_.reserve(size + 1);
        inv_.reserve(size + 1);
    }

    void resize(int size) {
        if (fact_.empty()) {
            fact_ = {mint(1), mint(1)};
            ifact_ = {mint(1), mint(1)};
            inv_ = {mint(0), mint(1)};
        }
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

// namespace FFT {
//     template<int mod>
//     void fft(std::vector<static_modular_int<mod>> &a) {
//         using mint = static_modular_int<mod>;

//         if (a.empty())
//             return;

//         static mint primitive_root = mint::primitive_root();
//         int n = int(a.size());
//         assert((n & (n - 1)) == 0);
//         int lg = std::__lg(n);

//         static std::vector<int> reversed_mask;
//         if (int(reversed_mask.size()) != n) {
//             reversed_mask.resize(n);
//             for (int mask = 1; mask < n; mask++)
//                 reversed_mask[mask] = (reversed_mask[mask >> 1] >> 1) + ((mask & 1) << (lg - 1));
//         }

//         static std::vector<mint> roots;
//         if (int(roots.size()) != lg) {
//             roots.resize(lg);
//             for (int i = 0; i < lg; i++)
//                 roots[i] = primitive_root.power((mod - 1) / (2 << i));
//         }

//         for (int i = 0; i < n; i++)
//             if (reversed_mask[i] < i)
//                 std::swap(a[i], a[reversed_mask[i]]);

//         for (int len = 1; len < n; len <<= 1) {
//             int root = roots[std::__lg(len)];
//             for (int i = 0; i < n; i += (len << 1)) {
//                 mint current = 1;
//                 for (int j = 0; j < len; j++, current *= root) {
//                     mint value = a[i + j + len] * current;
//                     a[i + j + len] = a[i + j] - value;
//                     a[i + j] = a[i + j] + value;
//                 }
//             }
//         }
//     }

//     template<int mod, typename T>
//     std::vector<static_modular_int<mod>> multiply(T a_begin, T a_end, T b_begin, T b_end) {
//         using mint = static_modular_int<mod>;

//         std::vector<mint> a(a_begin, a_end);
//         std::vector<mint> b(b_begin, b_end);
//         if (a_begin == a_end || b_begin == b_end)
//             return {};

//         int real_size = int(a.size() + b.size()) - 1;
//         int n = 1;
//         while (n < real_size)
//             n <<= 1;

//         a.resize(n);
//         b.resize(n);
//         fft(a), fft(b);

//         for (int i = 0; i < n; i++)
//             a[i] *= b[i];

//         fft(a);
//         std::reverse(a.begin() + 1, a.end());

//         mint inv_n = mint(n).inv();
//         a.resize(real_size);
//         for (auto &x : a)
//             x *= inv_n;

//         return a;
//     }

//     template<int mod>
//     void fft_2d(std::vector<std::vector<static_modular_int<mod>>> &a, bool invert) {
//         using mint = static_modular_int<mod>;

//         for (int rot : {0, 1}) {
//             for (auto &v : a) {
//                 fft(v);
//                 if (invert) {
//                     std::reverse(v.begin() + 1, v.end());
//                     mint inv_n = mint(v.size()).inv();
//                     for (auto &x : v)
//                         x *= inv_n;
//                 }
//             }

//             for (int i = 0; i < int(a.size()); i++)
//                 for (int j = 0; j < i; j++)
//                     std::swap(a[i][j], a[j][i]);
//         }
//     }

//     template<int mod, typename T>
//     std::vector<std::vector<static_modular_int<mod>>> multiply_2d(T a_begin, T a_end, T b_begin, T b_end) {
//         using mint = static_modular_int<mod>;

//         if (a_begin == a_end || b_begin == b_end || (*a_begin).empty() || (*b_begin).empty())
//             return {};

//         int real_size_x = std::distance(a_begin, a_end) + std::distance(b_begin, b_end) - 1;
//         int real_size_y = int((*a_begin).size() + (*b_begin).size()) - 1;
//         int base = 2;
//         while (base < std::max(real_size_x, real_size_y))
//             base <<= 1;

//         auto get = [&](T a_begin, T a_end) {
//             std::vector<std::vector<mint>> a(base, std::vector<mint>(base));
//             for (int i = 0; a_begin != a_end; i++, a_begin++)
//                 for (int j = 0; j < int((*a_begin).size()); j++)
//                     a[i][j] = (*a_begin)[j];

//             return a;
//         };

//         auto a = get(a_begin, a_end), b = get(b_begin, b_end);
//         fft_2d(a, false);
//         fft_2d(b, false);

//         for (int i = 0; i < base; i++)
//             for (int j = 0; j < base; j++)
//                 a[i][j] *= b[i][j];

//         fft_2d(a, true);
//         a.resize(real_size_x);
//         for (auto &v : a)
//             v.resize(real_size_y);

//         return a;
//     }
// } // namespace FFT

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    constexpr int N = 3e5 + 4;
    vector<mint> pairing(N);
    pairing[0] = 1;
    for (int n = 2; n < N; n += 2) {
        pairing[n] = pairing[n - 2] * (n - 1);
    }

    vector<mint> perm12(N);
    // perm12[0] = 1;
    // for (int n = 1; n < N; n++) {
    //     for (int i = 0; i <= n; i++) {
    //         perm12[n] += pairing[i] * choose(n, n - i);
    //     }
    // }

    // {
    //     auto pol1 = pairing;
    //     for (int i = 0; i < N; i++) pol1[i] *= ifact[i];
    //     vector<mint> pol2(N);
    //     for (int i = 0; i < N; i++) {
    //         pol2[i] = ifact[i];
    //     }
    //     auto prod = FFT::multiply<MOD>(all(pol1), all(pol2));
    //     for (int i = 0; i < N; i++) {
    //         perm12[i] = prod[i] * fact[i];
    //     }
    // }

    perm12[0] = 1;
    for (int n = 1; n < N; n++) {
        perm12[n] = perm12[n - 1];
        if (n >= 2) perm12[n] += (n - 1) * perm12[n - 2];
    }

    vector<mint> p2(N, 1);
    for (int i = 1; i < N; i++) {
        p2[i] = p2[i - 1] + p2[i - 1];
    }

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;

        mint ans = 0;
        for (int take4 = 0; take4 * 4 <= n; take4++) {
            ans += p2[take4] * choose(n - take4 * 2, 2 * take4) * pairing[take4 * 2] * perm12[n - take4 * 4];
        }
        cout << ans << '\n';
    }
}