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

namespace factorials {
    std::vector<mint> fact, ifact, inv, p2;

    void init(int n) {
        fact.assign(n + 1, mint(1));
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i;

        ifact.resize(n + 1);
        ifact.back() = fact.back().inv();
        for (int i = n; i > 0; i--)
            ifact[i - 1] = ifact[i] * i;

        inv.resize(n + 1);
        for (int i = 1; i <= n; i++)
            inv[i] = ifact[i] * fact[i - 1];

        p2.assign(n + 1, mint(1));
        for (int i = 1; i <= n; i++)
            p2[i] = p2[i - 1] + p2[i - 1];
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
using factorials::p2;
using factorials::choose;

template<typename T, typename is_zero_t>
struct gauss {
    std::vector<std::vector<T>> mat;
    is_zero_t is_zero;

    gauss(is_zero_t is_zero) : is_zero(is_zero) {}
    gauss(int n, is_zero_t is_zero) : mat(n, std::vector<T>(n + 1)), is_zero(is_zero) {}

    std::vector<T>& operator[](size_t i) {
        return mat[i];
    }

    const std::vector<T>& operator[](size_t i) const {
        return mat[i];
    }

    const int size() const {
        return mat.size();
    }

    void transform() {
        for (int col = 0; col < int(mat.size()); col++) {
            int row = col;
            while (row < int(mat.size()) && is_zero(mat[row][col]))
                row++;

            if (row == int(mat.size()))
                continue;

            for (; row != col; row--)
                std::swap(mat[row], mat[row - 1]);

            for (int i = 0; i < int(mat.size()); i++)
                if (i != col) {
                    T coeff = mat[i][col] / mat[col][col];
                    for (int j = col; j <= int(mat.size()); j++)
                        mat[i][j] -= mat[col][j] * coeff;
                }
        }
    }

    std::vector<T> solutions() const {
        std::vector<T> res(mat.size());
        for (int i = 0; i < int(mat.size()); i++)
            if (!is_zero(mat[i][i]))
                res[i] = -mat[i].back() / mat[i][i];

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
    }

    vector<int> a(n, -1);

    for (int v = 0; v < n; v++) {
        if (a[v] != -1) continue;
        y_combinator([&](auto dfs, int v) -> void {
            a[v] = 0;
            vector<bool> used(len(g[v]) + 1);
            for (auto u : g[v]) {
                if (a[u] == -1) dfs(u);
                if (a[u] < len(used)) used[a[u]] = true;
            }
            while (used[a[v]]) a[v]++;
        })(v);
    }

    const int A = 2 << __lg(max(1, *max_element(all(a))));
    auto is_zero = [&](const mint &a) { return a.value == 0; };
    gauss<mint, decltype(is_zero)> gs(A, is_zero);

    vector<int> cnt(A);
    for (auto &x : a) cnt[x]++;
    for (int x = 0; x < A; x++) {
        gs[x][x] = 1;
        if (x != 0) gs[x][A] = -mint(n + 1).inv();
        for (int y = 0; y < A; y++) {
            gs[x][y] -= mint(n + 1).inv() * cnt[x ^ y];
        }
    }

    gs.transform();
    cout << gs.solutions()[0] << '\n';
}