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

namespace sieve {
    std::vector<int> primes, smallest_factor;

    void init(int n) {
        smallest_factor.resize(n + 1);
        std::iota(smallest_factor.begin(), smallest_factor.end(), 0);

        for (int i = 2; i <= n; i++) {
            if (smallest_factor[i] == i)
                primes.emplace_back(i);

            for (int j = 0; j < int(primes.size()) && primes[j] <= smallest_factor[i] && primes[j] * i <= n; j++)
                smallest_factor[primes[j] * i] = primes[j];
        }
    }

    bool is_prime(int n) {
        if (n <= 1)
            return false;

        return smallest_factor[n] == n;
    }

    std::vector<std::pair<int, int>> get_factors(int n) {
        std::vector<std::pair<int, int>> factors;
        while (n != 1) {
            int prime = smallest_factor[n];
            factors.emplace_back(prime, 0);

            while (smallest_factor[n] == prime) {
                factors.back().second++;
                n /= prime;
            }
        }
        return factors;
    }
} // namespace sieve

using sieve::primes;
using sieve::smallest_factor;
using sieve::is_prime;
using sieve::get_factors;

template<typename T>
struct binary_indexed_tree {
    std::vector<T> bit;

    binary_indexed_tree(int n = 0, T value = 0) : bit(n + 1) {
        for (int i = 1; i <= n; i++)
            bit[i] = value * (i & -i);
    }

    void add(int pos, T delta) {
        for (pos++; pos < int(bit.size()); pos += pos & -pos)
            bit[pos] += delta;
    }

    T query(int pref) {
        T sum = 0;
        for (pref++; pref > 0; pref -= pref & -pref)
            sum += bit[pref];

        return sum;
    }

    T query(int l, int r) {
        if (r >= int(bit.size()))
            r = int(bit.size()) - 1;

        if (l < 0)
            l = 0;

        if (r <= l)
            return 0;

        return query(r - 1) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    sieve::init(1e7);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    vector<int> tin(n), tout(n), dep(n), p(n), pp(n);
    int timer = 0;

    y_combinator([&](auto dfs, int v) -> void {
        if (dep[p[v]] - dep[pp[p[v]]] == dep[pp[p[v]]] - dep[pp[pp[p[v]]]]) {
            pp[v] = pp[pp[p[v]]];
        }

        tin[v] = timer++;
        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            p[u] = pp[u] = v;
            dep[u] = dep[v] + 1;
            dfs(u);
        }
        tout[v] = timer;
    })(0);

    vector<int> a(n);
    vector<array<int, 4>> events;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        auto primes = get_factors(a[i]);
        for (auto &[p, deg] : primes) {
            events.push_back({p, deg, i, -1});
        }
    }

    auto lca = [&](int v, int u) {
        auto is_ancestor = [&](int v, int u) {
            return tin[v] <= tin[u] && tout[u] <= tout[v];
        };
        if (is_ancestor(v, u)) return v;
        while (true) {
            if (!is_ancestor(pp[v], u)) {
                v = pp[v];
            } else if (!is_ancestor(p[v], u)) {
                v = p[v];
            } else {
                return p[v];
            }
        }
        assert(false);
    };

    int q;
    cin >> q;
    vector<mint> ans(q);
    for (int i = 0; i < q; i++) {
        int v, u, x;
        cin >> v >> u >> x;
        v--, u--;
        int w = lca(v, u);
        ans[i] = gcd(x, a[w]);

        auto primes = get_factors(x);
        for (auto &[p, deg] : primes) {
            events.push_back({p, deg, -v - 1, i});
            events.push_back({p, deg, -u - 1, i});
            events.push_back({p, deg, -w - 1 - n, i});
        }
    }

    sort(all(events));
    binary_indexed_tree<int> bit(n);
    for (int i = 0, j = 0; i < len(events); i = j) {
        while (j < len(events) && events[j][0] == events[i][0]) j++;
        int ptr = i;
        for (int d = 1; ptr < j; d++) {
            int new_ptr = ptr;
            while (new_ptr < j && events[new_ptr][1] == d) new_ptr++;

            for (int k = ptr; k < j; k++) {
                if (events[k][2] >= 0) {
                    int v = events[k][2];
                    bit.add(tin[v], 1);
                    bit.add(tout[v], -1);
                }
            }

            for (int k = ptr; k < new_ptr; k++) {
                if (events[k][2] < 0) {
                    int v = -events[k][2] - 1, coeff = 1;
                    if (v >= n) {
                        v -= n;
                        coeff = -2;
                    }
                    ans[events[k][3]] *= mint(events[k][0]).power(bit.query(tin[v]) * coeff);
                }
            }
            ptr = new_ptr;
        }

        for (int k = i; k < j; k++) {
            if (events[k][2] >= 0) {
                int v = events[k][2];
                bit.add(tin[v], -events[k][1]);
                bit.add(tout[v], events[k][1]);
            }
        }
    }

    for (auto x : ans) cout << x << '\n';
}