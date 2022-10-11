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

void solve(int test_num) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    if (n == 1) {
        cout << "1\n";
        return;
    }

    vector<ll> pref(n);
    for (int i = 0; i < n; i++) {
        if (i) pref[i] = pref[i - 1];
        pref[i] += a[i];
    }
    assert(is_sorted(all(pref)));
    vector<ll> suf(n);
    for (int i = n - 1; i >= 0; i--) {
        if (i != n - 1) suf[i] = suf[i + 1];
        suf[i] += a[i];
    }

    map<ll, int> from_pref, to_pref;
    for (int i = 0; i < n; i++) {
        from_pref.emplace(pref[i], i);
        to_pref[pref[i]] = i;
    }

    map<ll, int> from_suf, to_suf;
    for (int i = n - 1; i >= 0; i--) {
        to_suf.emplace(suf[i], i);
        from_suf[suf[i]] = i;
    }

    mint ways = 1;
    map<ll, int> cl, cr;

    auto solve = [&](int c1, int c2) {
        return choose(c1 + c2, c1);
    };
    
    auto add = [&](map<ll, int> &cl, map<ll, int> &cr, ll val) {
        int c1 = cl[val], c2 = cr[val];
        ways /= solve(c1, c2);
        cl[val]++;
        ways *= solve(c1 + 1, c2);
    };

    mint ans = 1;
    int ptr_pref = 0, ptr_suf = n - 1;
    for (auto [val, l_pref] : from_pref) {
        int r_pref = to_pref[val];
        if (!from_suf.count(val)) continue;

        int l_suf = from_suf[val];
        int r_suf = to_suf[val];

        while (ptr_pref < l_pref) {
            add(cl, cr, pref[ptr_pref]);
            ptr_pref++;
        }
        while (ptr_suf > r_suf) {
            add(cr, cl, suf[ptr_suf]);
            ptr_suf--;
        }

        dprint();
        dbg(ans);
        dbg(l_pref, r_pref);
        dbg(l_suf, r_suf);
        dbg(ways);

        for (int pos_pref = l_pref; pos_pref <= r_pref; pos_pref++) {
            int n2 = max(0, r_suf - max(l_suf, pos_pref + 1) + 1);
            if (n2 == 0) continue;

            int n1 = pos_pref - l_pref;
            dbg(n1, n2);
            // for (int x = 0; x <= n1; x++) {
            //     ans += choose(n1, x) * choose(n2, x + 1) * ways;
            //     dbg(x, choose(n1, x) * choose(n2, x + 1), ways);
            // }
            ans += ways * choose(n1 + n2, n1 + 1);
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}