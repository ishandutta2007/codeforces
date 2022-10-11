#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template <typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun &&fun) : fun(std::forward<const Fun>(fun)) {}

    template <typename... Args>
    auto operator()(Args &&...args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <typename T>
int normalize(T value, int mod) {
    if (value < -mod || value >= 2 * mod)
        value %= mod;

    if (value < 0)
        value += mod;

    if (value >= mod)
        value -= mod;

    return value;
}

template <int mod>
struct static_modular_int {
    using mint = static_modular_int<mod>;

    int value;

    static_modular_int() : value(0) {}
    static_modular_int(const mint &x) : value(x.value) {}

    template <typename T>
    static_modular_int(T value) : value(normalize(value, mod)) {}

    template <typename T>
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

    mint &operator=(const mint &x) {
        value = x.value;
        return *this;
    }

    mint &operator+=(const mint &x) {
        value += x.value;
        if (value >= mod)
            value -= mod;

        return *this;
    }

    mint &operator-=(const mint &x) {
        value -= x.value;
        if (value < 0)
            value += mod;

        return *this;
    }

    mint &operator*=(const mint &x) {
        value = (long long)value * x.value % mod;
        return *this;
    }

    mint &operator/=(const mint &x) {
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

    mint &operator++() {
        ++value;
        if (value == mod)
            value = 0;

        return *this;
    }

    mint &operator--() {
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

    template <typename T>
    explicit operator T() {
        return value;
    }

    friend istream &operator>>(istream &in, mint &x) {
        std::string s;
        in >> s;

        x = 0;
        for (const auto c : s)
            x = x * 10 + (c - '0');

        return in;
    }

    friend ostream &operator<<(ostream &out, const mint &x) {
        return out << x.value;
    }
};

// constexpr int MOD = 1'000'000'007;
constexpr int MOD = 998'244'353;
using mint = static_modular_int<MOD>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(k), ig(k);

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        vector<int> a(c);
        for (auto &x : a) cin >> x, x--;

        set<int> st;
        bool ok = true;
        for (int i = 0; i < c; i++) {
            if (st.count(a[i])) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;

        for (int i = 0; i < c; i++) {
            if (i != c - 1) g[a[i]].push_back(a[i + 1]);
            if (i) ig[a[i]].push_back(a[i - 1]);
        }
    }

    for (auto &v : g) {
        sort(all(v));
        v.resize(unique(all(v)) - v.begin());
    }
    for (auto &v : ig) {
        sort(all(v));
        v.resize(unique(all(v)) - v.begin());
    }

    vector<bool> used(k);
    vector<int> a;
    for (int i = 0; i < k; i++) {
        if (used[i]) continue;

        int cnt1 = 0, cnt2 = 0, sz = 0;

        y_combinator([&](auto dfs, int v) -> void {
            used[v] = true;
            sz++;
            cnt1 += len(g[v]) + len(ig[v]) == 1;
            cnt2 += len(g[v]) + len(ig[v]) == 2;
            if (len(g[v]) > 1 || len(ig[v]) > 1) cnt1 = -1e9;
            for (auto u : g[v]) {
                if (!used[u]) dfs(u);
            }
            for (auto u : ig[v]) {
                if (!used[u]) dfs(u);
            }
        })(i);

        if (sz == 1 || !(cnt1 != 2 || cnt2 != sz - 2 || cnt1 + cnt2 != sz)) {
            a.push_back(sz);
        }
    }

    sort(all(a));
    vector<pair<int, int>> lens;
    for (int i = 0, j = 0; i < len(a); i = j) {
        while (j < len(a) && a[i] == a[j]) j++;
        lens.emplace_back(a[i], j - i);
    }

    vector<mint> dp(m + 1);
    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (auto &[ln, cnt] : lens) {
            if (i >= ln) dp[i] += dp[i - ln] * cnt;
        }
    }
    cout << dp[m] << '\n';
}