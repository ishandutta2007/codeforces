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

constexpr int MOD = 1'000'000'007;
// constexpr int MOD = 998'244'353;
using mint = static_modular_int<MOD>;

namespace combinatorics {
    std::vector<mint> fact_({mint(1), mint(1)});
    std::vector<mint> ifact_({mint(1), mint(1)});
    std::vector<mint> inv_({mint(0), mint(1)});

    void reserve(int size) {
        fact_.reserve(size + 1);
        ifact_.reserve(size + 1);
        inv_.reserve(size + 1);
    }

    void resize(int size) {
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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<mint> a(n);
    for (auto &x : a) cin >> x;
    k--;

    if (k == 0) {
        cout << n * accumulate(all(a), mint(0)) << '\n';
        return 0;
    }

    // brute force
    // mint ans = 0;
    // for (int sz = 1; sz < n; sz++) {
    //     mint cur = 0;
    //     for (int i = 1; i <= k; i++) {
    //         mint tmp = choose(k, i) * mint(i).power(n - sz);
    //         cur += tmp * ((k - i) % 2 ? -1 : 1);
    //     }
    //     cur *= choose(n - 1, sz - 1) * sz;
    //     ans += cur;
    // }

    auto calc = [&](int n, mint x) {
        // mint res = 0;
        // for (int i = 0; i <= n; i++) {
        //     res += i * choose(n, i) * x.power(i);
        // }
        // return res;
        return n * x * (x + 1).power(n - 1);
    };

    auto calc2 = [&](int n, mint x) {
        // mint res = 0;
        // for (int i = 0; i <= n; i++) {
        //     res += (n - i) * choose(n, i) * x.power(i);
        // }
        // return res;
        return n * mint(x + 1).power(n - 1);
    };

    mint ans = 0;
    for (int i = 1; i <= k; i++) {
        mint cur = 0;
        // for (int s = 0; s <= n - 2; s++) {
        //     cur += choose(n - 1, s) * mint(i).power(n - 1 - s);
        // }
        cur += mint(i + 1).power(n - 1) - 1;

        // for (int s = 0; s <= n - 2; s++) {
        //     cur += s * choose(n - 1, s) * mint(i).power(n - 1 - s);
        // }
        // cur += calc(n - 1, mint(i).inv()) * mint(i).power(n - 1) - (n - 1);
        cur += calc2(n - 1, i) - (n - 1);
        // calc(n - 1, mint(1).inv()) * mint(i).power(n - 1) == calc2(n - 1, i)

        cur *= choose(k, i);
        ans += cur * ((k - i) % 2 ? -1 : 1);
    }
    cout << ans * accumulate(all(a), mint(0)) / fact[k] << '\n';
}