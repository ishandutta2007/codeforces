#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

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
        value = (long long) value * x.inv() % mod;
        return *this;
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

    friend mint operator/=(const mint &x, const mint &y) {
        return mint(x) /= y;
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

// constexpr int MOD = 1'000'000'007;
constexpr int MOD = 998'244'353;
using mint = static_modular_int<MOD>;

namespace factorials {
    std::vector<mint> fact;
    std::vector<mint> ifact;
    std::vector<mint> inv;

    void init(int n) {
        fact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i;

        ifact.resize(n + 1);
        ifact.back() = fact.back().inv();
        for (int i = n; i > 0; i--)
            ifact[i - 1] = ifact[i] * i;

        inv.resize(n + 1);
        for (int i = 1; i <= n; i++)
            inv[i] = ifact[i] * fact[i - 1];
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
using factorials::choose;

template<typename Fun>
class y_combinator {
    const Fun fun_;
public:
    explicit y_combinator(const Fun&& fun) : fun_(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    decltype(auto) operator()(Args&&... args) const {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> l(n);
    vector<int> r(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];

    vector<char> bad(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        bad[a] = bad[b] = 1;
    }

    vector<vector<pair<int, int>>> events(n + 1);
    for (int i = 0; i < n; i++) {
        events[l[i] - 1].emplace_back(i, 0);
        events[r[i]].emplace_back(i, 1);
    }

    vector<int> id(n);
    for (int i = 0; i < n; i++)
        id[i] = bad[i] + (i == 0 ? -1 : id[i - 1]);

    const int count_bad = accumulate(all(bad), 0);

    int count_good = 0;
    vector<vector<int>> current_g(n);
    vector<vector<mint>> dp(count_bad, {1});
    vector<char> active(n);

    int timer = 0;
    vector<int> used(n);

    auto erase_component = [&](int v) {
        if (used[v] == timer)
            return;

        auto mn = y_combinator([&](auto dfs, int v) -> int {
            used[v] = timer;
            int mn = v;
            for (auto u : current_g[v])
                if (used[u] != timer)
                    mn = min(mn, dfs(u));

            return mn;
        })(v);
        dp[id[mn]] = {1};
    };

    vector<int> new_id(n);
    vector<int> connected_mask(n);
    vector<char> good(1 << (m + 1));

    vector<int> popcount(len(good));
    for (int mask = 1; mask < len(good); mask++)
        popcount[mask] = popcount[mask >> 1] + (mask & 1);

    auto solve_component = [&](int v) {
        if (used[v] == timer)
            return;

        vector<int> component;

        y_combinator([&](auto dfs, int v) -> void {
            used[v] = timer;
            component.push_back(v);
            for (auto u : current_g[v])
                if (used[u] != timer)
                    dfs(u);
        })(v);
        sort(all(component));

        const int component_id = id[component[0]];
        for (int i = 0; i < len(component); i++)
            new_id[component[i]] = i;

        for (auto v : component) {
            connected_mask[v] = 0;
            for (auto u : current_g[v])
                connected_mask[v] |= 1 << new_id[u];
        }

        assert(len(component) <= m + 1);
        const int MASK = 1 << len(component);
        good[0] = 1;

        dp[component_id] = vector<mint>(len(component) + 1);
        dp[component_id][0]++;

        for (int mask = 1; mask < MASK; mask++) {
            int b = __lg(mask);
            int sub_mask = mask ^ (1 << b);
            good[mask] = good[sub_mask] && (connected_mask[component[b]] & sub_mask) == 0;

            if (good[mask])
                dp[component_id][popcount[mask]]++;
        }
    };

    auto insert_vertex = [&](int v) {
        if (!bad[v]) {
            count_good++;
            return;
        }

        timer++;
        for (auto u : g[v])
            if (active[u])
                erase_component(u);

        active[v] = 1;
        for (auto u : g[v])
            if (active[u]) {
                current_g[v].push_back(u);
                current_g[u].push_back(v);
            }

        timer++;
        solve_component(v);
    };

    auto erase_vertex = [&](int v) {
        if (!bad[v]) {
            count_good--;
            return;
        }

        timer++;
        erase_component(v);

        active[v] = 0;
        for (auto u : current_g[v])
            current_g[u].erase(find(all(current_g[u]), v));

        timer++;
        for (auto u : current_g[v])
            solve_component(u);
    };

    vector<mint> total(2 * count_bad + 1);
    vector<mint> new_total(2 * count_bad + 1);

    mint answer = 0;
    factorials::init(n);

    for (int x = 0; x < n; x++) {
        for (const auto &[id, type] : events[x])
            type == 0 ? insert_vertex(id) : erase_vertex(id);

        int current_size = 1;
        fill(all(total), 0);
        total[0] = 1;

        for (const auto &ways : dp) {
            fill(all(new_total), 0);
            int new_size = current_size + len(ways) - 1;

            for (int i = 0; i < current_size; i++)
                for (int j = 0; j < len(ways); j++)
                    new_total[i + j] += total[i] * ways[j];

            swap(total, new_total);
            current_size = new_size;
        }

        for (int i = 0; i <= x + 1 && i < current_size; i++)
            answer += total[i] * choose(count_good, x + 1 - i);
    }

    cout << answer << '\n';
}