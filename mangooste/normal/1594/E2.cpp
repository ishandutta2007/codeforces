#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
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

    explicit operator int() {
        return value;
    }

    explicit operator long long() {
        return value;
    }

    friend istream& operator>>(istream &in, mint &x) {
        std::string s;
        cin >> s;

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

template<typename Fun>
struct y_combinator {
    const Fun fun_;

    explicit y_combinator(const Fun&& fun) : fun_(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    decltype(auto) operator()(Args&&... args) const {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    vector<mint> dp(k);
    dp[1] = 4;
    for (int i = 2; i < k; i++)
        dp[i] = dp[i - 1].power(2) * 4;

    map<ll, int> color;
    while (n--) {
        ll pos;
        string name;
        cin >> pos >> name;

        int res;
        if (name == "white")
            res = 0;
        else if (name == "yellow")
            res = 1;
        else if (name == "green")
            res = 2;
        else if (name == "blue")
            res = 3;
        else if (name == "red")
            res = 4;
        else if (name == "orange")
            res = 5;
        else
            assert(false);

        color[pos] = res;
    }

    for (auto [x, c] : color)
        if (color.find(x >> 1) != color.end() && color[x >> 1] / 2 == c / 2) {
            cout << "0\n";
            return 0;
        }

    set<ll> bad;
    for (auto [x, c] : color)
        for (ll y = x; y != 0; y >>= 1)
            bad.insert(y);

    auto res = y_combinator([&](auto solve, ll v, int layer) -> array<mint, 6> {
        array<mint, 6> res;
        res.fill(0);

        if (layer == 1) {
            if (color.find(v) != color.end())
                res[color[v]] = 1;
            else
                res.fill(1);

            return res;
        }

        if (!bad.count(v)) {
            if (layer == 1)
                res.fill(1);
            else
                res.fill(dp[layer - 1].power(2));

            return res;
        }

        auto left = solve(v << 1, layer - 1);
        auto right = solve(v << 1 | 1, layer - 1);

        mint sum_left = accumulate(all(left), mint(0));
        mint sum_right = accumulate(all(right), mint(0));

        for (int i = 0; i < 6; i++) {
            if (color.find(v) != color.end() && i != color[v])
                continue;

            res[i] = (sum_left - left[i] - left[i ^ 1]) * (sum_right - right[i] - right[i ^ 1]);
        }

        return res;
    })(1, k);

    cout << accumulate(all(res), mint(0)) << '\n';
}