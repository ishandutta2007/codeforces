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

template<typename T>
struct nonstatic_modular_int {
    using mint = nonstatic_modular_int<T>;

    int value;

    nonstatic_modular_int() : value(0) {}
    nonstatic_modular_int(const mint &x) : value(x.value) {}

    template<typename U, typename V = std::enable_if_t<std::is_integral<U>::value>>
    nonstatic_modular_int(U value) : value(normalize(value, T::mod)) {}

    template<typename U>
    mint power(U degree) const {
        degree = normalize(degree, T::mod - 1);
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
        if (value >= T::mod)
            value -= T::mod;

        return *this;
    }

    mint& operator-=(const mint &x) {
        value -= x.value;
        if (value < 0)
            value += T::mod;

        return *this;
    }

    mint& operator*=(const mint &x) {
        value = (long long) value * x.value % T::mod;
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
        if (value == T::mod)
            value = 0;

        return *this;
    }

    mint& operator--() {
        --value;
        if (value == -1)
            value = T::mod - 1;

        return *this;
    }

    mint operator++(int) {
        mint prev = *this;
        value++;
        if (value == T::mod)
            value = 0;

        return prev;
    }

    mint operator--(int) {
        mint prev = *this;
        value--;
        if (value == -1)
            value = T::mod - 1;

        return prev;
    }

    mint operator-() const {
        return mint(0) - *this;
    }

    bool operator==(const mint &x) const {
        return value == x.value;
    }

    template<typename U>
    explicit operator U() {
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
        if constexpr (T::mod == 1'000'000'007)
            return 5;

        if constexpr (T::mod == 998'244'353)
            return 3;

        if constexpr (T::mod == 786433)
            return 10;

        static int root = -1;
        if (root != -1)
            return root;

        std::vector<int> primes;
        int value = T::mod - 1;
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
                if ((mint(r).power((T::mod - 1) / p)).value == 1) {
                    ok = false;
                    break;
                }

            if (ok)
                return root = r;
        }
    }
};

struct nonstatic_modular_int_mod {
    static int mod;
};

int nonstatic_modular_int_mod::mod = 0;
int &mod = nonstatic_modular_int_mod::mod;

using mint = nonstatic_modular_int<nonstatic_modular_int_mod>;

void solve(int test_num) {
    int n, m;
    cin >> n >> m;
    vector<bool> used(m + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        used[x] = true;
    }

    mod = int(1e9) + 7;
    vector<mint> ways(m + 1);
    int cnt_bad = count(all(used), true);

    auto update = [&](int val, int coeff) {
        if (used[val] && ways[val].value == 0) {
            cnt_bad += coeff;
        }
    };

    auto add = [&](int pos, mint val) {
        update(pos, -1);
        ways[pos] += val;
        update(pos, 1);
    };

    const int MIN = find(all(used), true) - used.begin();
    int ans = m;
    for (int from = 1, to = 1; from <= MIN; from++) {
        if (from == 2) {
            to = 2;
            cnt_bad = count(all(used), true);
            fill(all(ways), 0);
        }

        assert(to >= from);
        for (; cnt_bad; to++) {
            assert(to <= m);
            add(to, 1);
            for (int i = to; i <= m; i += to) {
                add(i, ways[i / to]);
            }
        }
        assert(to > from);
        ans = min(ans, to - from - 1);

        for (int i = (m / from) * from; i >= from; i -= from) {
            add(i, -ways[i / from]);
        }
        add(from, -1);
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