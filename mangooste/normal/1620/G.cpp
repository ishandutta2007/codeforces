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

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector cnt(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (auto c : s)
            cnt[i][c - 'a']++;
    }

    const int MASK = 1 << n;
    vector<mint> value(MASK);
    vector<int> sum_i(MASK), popcount(MASK);

    y_combinator([&](auto dfs, int mask, int pos, int cur_popcount, int cur_sum_i, vector<int> cur_cnt) -> void {
        if (pos == n) {
            if (mask == 0)
                return;

            mint current = 1;
            for (auto &x : cur_cnt)
                current *= x + 1;

            value[mask] = cur_popcount % 2 ? current : -current;
            sum_i[mask] = cur_sum_i;
            popcount[mask] = cur_popcount;
            return;
        }

        dfs(mask, pos + 1, cur_popcount, cur_sum_i, cur_cnt);
        for (int i = 0; i < 26; i++)
            cur_cnt[i] = min(cur_cnt[i], cnt[pos][i]);

        dfs(mask ^ (1 << pos), pos + 1, cur_popcount + 1, cur_sum_i + pos + 1, cur_cnt);
    })(0, 0, 0, 0, vector<int>(26, 1e9));

    for (int bit = 0; bit < n; bit++)
        for (int mask = 0; mask < MASK; mask++)
            if (mask >> bit & 1)
                value[mask] += value[mask ^ (1 << bit)];

    ll answer = 0;
    for (int mask = 1; mask < MASK; mask++)
        answer ^= ll(value[mask]) * sum_i[mask] * popcount[mask];

    cout << answer << '\n';
}