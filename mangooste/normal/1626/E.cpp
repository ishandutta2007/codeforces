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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> c(n);
    for (auto &x : c)
        cin >> x;

    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    int tot = accumulate(all(c), 0);
    vector<int> tin(n), tout(n), f(n + 1), cnt_black(n);
    int timer = 0;

    auto add_on_seg = [&](int l, int r, int delta) {
        f[l] += delta;
        f[r] -= delta;
    };

    y_combinator([&](auto dfs, int v, int p) -> void {
        tin[v] = timer++;
        cnt_black[v] = c[v];
        for (auto u : g[v])
            if (u != p) {
                dfs(u, v);
                cnt_black[v] += cnt_black[u];
            }

        tout[v] = timer;

        if (c[v]) {
            if (cnt_black[v] != 1) {
                add_on_seg(tin[v], tout[v], -1);
                add_on_seg(0, n, 1);
            }

            for (auto u : g[v])
                if (u != p && cnt_black[u] + 1 != tot)
                    add_on_seg(tin[u], tout[u], 1);
        } else {
            int good1 = 0, good2 = 0;
            for (auto u : g[v])
                if (u != p) {
                    good1 += c[u];
                    good2 += cnt_black[u] - c[u] > 0;
                }

            auto good = [&]() {
                return good1 > 1 || (good1 && good2);
            };

            if (good()) {
                add_on_seg(tin[v], tout[v], -1);
                add_on_seg(0, n, 1);
            }

            if (v != 0) {
                good1 += c[p];
                good2 += tot - cnt_black[v] - c[p] > 0;
            }

            if (good1)
                add_on_seg(tin[v], tin[v] + 1, 1);

            for (auto u : g[v])
                if (u != p) {
                    good1 -= c[u];
                    good2 -= cnt_black[u] - c[u] > 0;

                    if (good())
                        add_on_seg(tin[u], tout[u], 1);

                    good1 += c[u];
                    good2 += cnt_black[u] - c[u] > 0;
                }
        }
    })(0, 0);

    for (int i = 1; i < n; i++)
        f[i] += f[i - 1];

    for (int i = 0; i < n; i++)
        cout << (f[tin[i]] > 0 || c[i]) << " \n"[i == n - 1];
}