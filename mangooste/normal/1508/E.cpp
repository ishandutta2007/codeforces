#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template <typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template <typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), where(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        where[a[i]] = i;
    }
    auto initial_a = a;

    vector<int> p(n, -1);
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        p[u] = v;
    }

    vector<int> tin(n), tout(n);
    int timer = 0;

    y_combinator([&](auto dfs, int v) -> void {
        tin[v] = timer++;
        for (auto u : g[v]) {
            dfs(u);
        }
        tout[v] = timer;
    })(0);

    struct binary_index_tree {
        int n;
        vector<int> bit;

        binary_index_tree(int n) : n(n), bit(n + 1) {}

        void add(int pos, int delta) {
            for (pos++; pos <= n; pos += pos & -pos) {
                bit[pos] += delta;
            }
        }

        int query(int pref) {
            int tot = 0;
            for (pref++; pref; pref -= pref & -pref) {
                tot += bit[pref];
            }
            return tot;
        }

        int query(int l, int r) {
            return query(r - 1) - query(l - 1);
        }
    } bit(n);

    for (int i = 0; i < n; i++) {
        bit.add(i, 1);
    }

    vector<int> st;
    vector<bool> used(n);
    vector<vector<int>> g2(n);

    auto pop_back = [&]() {
        if (len(st) != 1) {
            g2[st.end()[-2]].push_back(st.back());
        }
        st.pop_back();
    };

    for (int x = 0; x < n; x++) {
        while (!st.empty() && bit.query(tin[st.back()], tout[st.back()]) == 0) {
            pop_back();
        }

        int v = where[x], u = v;
        vector<int> path;
        while (u != -1 && !used[u]) {
            path.push_back(u);
            u = p[u];
        }
        reverse(all(path));

        if (bit.query(tin[v], tout[v]) == 1) {
            if (!st.empty() && st.back() != u) {
                cout << "NO\n";
                return 0;
            }

            used[v] = true;
            bit.add(tin[v], -1);
            for (auto x : path) {
                used[x] = true;
                st.push_back(x);
            }
        } else {
            if (!(st.empty() || st.back() == u || used[v])) {
                cout << "NO\n";
                return 0;
            }

            for (auto x : path) {
                used[x] = true;
                st.push_back(x);
            }
            while (p[v] != -1) {
                swap(a[v], a[p[v]]);
                v = p[v];
            }
            for (int i = 0; i < len(st); i++) {
                if (a[st[i]] != x + i) {
                    cout << "NO\n";
                    return 0;
                }
            }
            break;
        }
    }
    while (!st.empty()) {
        pop_back();
    }

    auto b = a;
    int cur = 0;

    y_combinator([&](auto dfs, int v) -> void {
        b[v] = cur++;
        for (auto u : g2[v]) {
            dfs(u);
        }
    })(0);

    bool ok = true;
    cur = 0;

    y_combinator([&](auto dfs, int v) -> void {
        sort(all(g[v]), [&](const int i, const int j) {
            return b[i] < b[j];
        });
        ok &= b[v] == cur++;
        for (auto u : g[v]) {
            dfs(u);
        }
    })(0);

    if (!ok) {
        cout << "NO\n";
    } else {
        a = initial_a;
        ll ans = 0;
        fill(all(bit.bit), 0);

        y_combinator([&](auto dfs, int v) -> void {
            ans += bit.query(a[v], n);
            bit.add(a[v], 1);
            for (auto u : g[v]) {
                dfs(u);
            }
            bit.add(a[v], -1);
        })(0);

        cout << "YES\n";
        cout << ans << '\n';
        for (int i = 0; i < n; i++) {
            cout << b[i] + 1 << " \n"[i == n - 1];
        }
    }
}