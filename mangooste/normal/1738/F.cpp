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

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

void solve(int test_num) {
    int n;
    cin >> n;
    vector<int> d(n);

#ifdef LOCAL
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<vector<int>> g_(n);
    set<pair<int, int>> edges;
    int m_ = rng() % (3 * n);
    for (int it = 0; it < m_; it++) {
        int v = rng() % n, u = rng() % n;
        if (v == u || edges.count(minmax(v, u))) continue;
        d[v]++;
        d[u]++;
        g_[v].push_back(u);
        g_[u].push_back(v);
        edges.insert(minmax(v, u));
    }
#else
    for (auto &x : d) cin >> x;
#endif

    auto query = [&](int v) {
#ifdef LOCAL
        assert(!g_[v].empty());
        int u = g_[v].back();
        g_[v].pop_back();
        return u;
#else
        cout << "? " << v + 1 << endl;
        int u;
        cin >> u;
        return u - 1;
#endif
    };


    vector<int> par(n), rank(n, 1), sum_deg = d;
    iota(all(par), 0);

    auto root = y_combinator([&](auto root, int v) -> int {
        return par[v] == v ? v : par[v] = root(par[v]);
    });

    auto unite = [&](int v, int u) {
        v = root(v);
        u = root(u);
        assert(v != u);
        par[u] = v;
        rank[v] += rank[u];
        sum_deg[v] += sum_deg[u];
    };

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](const int v, const int u) {
        return d[v] > d[u];
    });

    vector<bool> used(n);
    for (int v : ord) {
        if (used[v]) continue;
        used[v] = true;
        for (int it = 0; it < d[v]; it++) {
            int u = query(v);
            if (root(v) == root(u)) break;
            if (used[u]) {
                unite(v, u);
                break;
            }
            used[u] = true;
            unite(v, u);
        }
    }

    for (int v = 0; v < n; v++) {
        if (v == root(v)) {
            assert(rank[v] * rank[v] >= sum_deg[v]);
        }
    }

    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << root(i) + 1 << " \n"[i == n - 1];
    }
    cout << flush;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}