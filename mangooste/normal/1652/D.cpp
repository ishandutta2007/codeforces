#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

template<typename Fun>
struct y_combinator {
    const Fun fun;

    y_combinator(const Fun&& fun) : fun(forward<const Fun>(fun)) {}

    template<typename... Tail>
    decltype(auto) operator()(Tail&&... tail) const {
        return fun(ref(*this), forward<Tail>(tail)...);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<array<int, 3>>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u, a, b;
        cin >> v >> u >> a >> b;
        v--, u--;
        g[v].push_back({u, b, a});
        g[u].push_back({v, a, b});
    }

    vector<int> sieve(n + 1);
    iota(all(sieve), 0);
    for (int i = 2; i <= n; i++) {
        if (sieve[i] != i) continue;
        for (int j = i + i; j <= n; j += i) {
            sieve[j] = min(sieve[j], i);
        }
    }

    vector<int> tin(n), tout(n);
    int timer = 0;
    vector<vector<pair<int, int>>> events(n + 1);

    y_combinator([&](auto dfs, int v) -> void {
        tin[v] = timer++;
        for (auto [u, a, b] : g[v]) {
            g[u].erase(find(all(g[u]), array{v, b, a}));
            dfs(u);
            vector<int> primes;
            for (int value : {a, b}) {
                while (value != 1) {
                    int p = sieve[value];
                    while (value % p == 0) value /= p;
                    primes.push_back(p);
                }
            }
            sort(all(primes));
            primes.resize(unique(all(primes)) - primes.begin());
            for (auto p : primes) {
                int deg1 = 0;
                while (a % p == 0) a /= p, deg1++;
                int deg2 = 0;
                while (b % p == 0) b /= p, deg2++;
                events[p].emplace_back(u, deg2 - deg1);
            }
        }
        tout[v] = timer;
    })(0);

    // struct segtree {
    //     vector<ll> a;
        
    //     segtree(int n) : a(n) {}

    //     void add(int l, int r, int delta) {
    //         for (int i = l; i < r; i++) a[i] += delta;
    //     }

    //     int get_max() {
    //         return *max_element(all(a));
    //     }
    // } tree(n);

    struct segtree {
        int n;
        vector<int> tree, mod;

        segtree(int n) : n(n), tree(4 * n), mod(4 * n) {}

        void add(int l, int r, int value) {
            add(1, 0, n, l, r, value);
        }

        void apply(int v, int value) {
            tree[v] += value;
            mod[v] += value;
        }

        void push(int v) {
            apply(v << 1, mod[v]);
            apply(v << 1 | 1, mod[v]);
            mod[v] = 0;
        }

        void add(int v, int vl, int vr, int l, int r, int value) {
            if (r <= vl || vr <= l) return;
            if (l <= vl && vr <= r) {
                apply(v, value);
                return;
            }
            push(v);
            int vm = (vl + vr) >> 1;
            add(v << 1, vl, vm, l, r, value);
            add(v << 1 | 1, vm, vr, l, r, value);
            tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
        }

        int get_max() {
            return tree[1];
        }
    } tree(n);

    constexpr int MOD = 998244353;

    auto mult = [&](int a, int b) -> int {
        return 1ll * a * b % MOD;
    };

    auto add = [&](int a, int b) {
        a += b;
        if (a >= MOD) a -= MOD;
        return a;
    };

    auto power = [&](int a, ll b) {
        int res = 1;
        for (; b; b >>= 1, a = mult(a, a)) {
            if (b & 1) res = mult(res, a);
        }
        return res;
    };

    int first = 1;
    for (int x = 2; x <= n; x++) {
        if (sieve[x] != x) continue;
        for (auto &[v, delta] : events[x]) {
            tree.add(tin[v], tout[v], delta);
        }
        first = mult(first, power(x, tree.get_max()));
        for (auto &[v, delta] : events[x]) {
            tree.add(tin[v], tout[v], -delta);
        }
    }

    int ans = 0;
    y_combinator([&](auto dfs, int v, int x) -> void {
        ans = add(ans, x);
        for (auto &[u, a, b] : g[v]) {
            int new_x = mult(x, a);
            new_x = mult(new_x, power(b, MOD - 2));
            dfs(u, new_x);
        }
    })(0, first);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests = 1;
    cin >> tests;
    while (tests--) solve();
}