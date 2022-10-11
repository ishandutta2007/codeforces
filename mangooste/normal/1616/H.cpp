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

    int n, x;
    cin >> n >> x;
    x++;
    int highest_bit = __lg(x);

    map<int, vector<int>> groups;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int y = x >> (highest_bit + 1) << (highest_bit + 1);
        groups[y].push_back(x ^ y);
    }

    vector<mint> p2(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        p2[i] = p2[i - 1] + p2[i - 1];
    }

    auto solve = [&](const vector<int> &elements) {
        vector<int> left, right;
        for (auto v : elements) {
            if (v >> highest_bit & 1) {
                right.push_back(v ^ x);
            } else {
                left.push_back(v);
            }
        }
        sort(all(left));
        sort(all(right));
        mint ans = 0;

        auto get_seg = [&](int mask, int bit) {
            int l = lower_bound(all(right), mask) - right.begin();
            int r = upper_bound(all(right), mask ^ ((1 << (bit + 1)) - 1)) - right.begin();
            assert(l <= r);
            return r - l;
        };

        y_combinator([&](auto dfs, int l, int r, int bit, int mask_up, int tot_up) -> mint {
            if (r <= l) return 0;
            if (bit == -1) {
                ans += (p2[r - l] - 1) * p2[tot_up];
                return p2[r - l] - 1;
            }

            int m = l;
            while (m < r && !(left[m] >> bit & 1)) m++;
            bool can_flip = x >> bit & 1;

            int len1 = 0;
            if (can_flip) len1 = get_seg(mask_up ^ (1 << bit), bit - 1);
            auto left = dfs(l, m, bit - 1, mask_up, tot_up + len1);

            int len2 = 0;
            if (can_flip) len2 = get_seg(mask_up, bit - 1);
            auto right = dfs(m, r, bit - 1, mask_up ^ (1 << bit), tot_up + len2);

            if (can_flip) {
                ans += p2[tot_up] * left * right;
                return left * p2[len1] + right * p2[len2] + left * right;
            }
            ans += p2[tot_up] * (p2[m - l] - 1) * (p2[r - m] - 1);
            return left + right + (p2[m - l] - 1) * (p2[r - m] - 1);
        })(0, len(left), highest_bit - 1, 0, 0);

        ans += p2[len(right)] - 1;
        return ans;
    };

    mint ans = 0;
    for (auto &[_, a] : groups) {
        ans += solve(a);
    }
    cout << ans << '\n';
}