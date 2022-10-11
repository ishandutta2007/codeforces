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

struct strongly_connected_component {
    int n;
    std::vector<std::vector<int>> g, rev_g;

    strongly_connected_component(int n = 0) : n(n), g(n), rev_g(n) {}

    int size() const {
        return n;
    }

    void add(int from, int to) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        g[from].push_back(to);
        rev_g[to].push_back(from);
    }

    std::vector<int> scc() const {
        std::vector<int> order;
        order.reserve(n);
        std::vector<char> used(n);

        std::function<void(int)> dfs_order = [&](int v) {
            used[v] = 1;
            for (auto u : g[v])
                if (!used[u])
                    dfs_order(u);

            order.push_back(v);
        };

        for (int i = 0; i < n; i++)
            if (!used[i])
                dfs_order(i);

        std::reverse(order.begin(), order.end());
        int current_num = 0;
        std::vector<int> scc_num(n, -1);

        std::function<void(int)> dfs_fill = [&](int v) {
            scc_num[v] = current_num;
            for (auto u : rev_g[v])
                if (scc_num[u] == -1)
                    dfs_fill(u);
        };

        for (auto i : order)
            if (scc_num[i] == -1) {
                dfs_fill(i);
                current_num++;
            }

        return scc_num;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &s : grid) cin >> s;
    vector<int> a(m);
    for (auto &x : a) cin >> x;

    int nvers = 0;
    vector id(n, vector<int>(m, -1));
    vector<int> col;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                id[i][j] = nvers++;
                col.push_back(j);
            }
        }
    }
    if (nvers == 0) {
        cout << "0\n";
        return 0;
    }

    strongly_connected_component scc(nvers);
    vector<int> last(m, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (id[i][j] != -1 && last[j] != -1) {
                scc.add(last[j], id[i][j]);
            }
            if (i && id[i][j] != -1 && id[i - 1][j] != -1) {
                scc.add(id[i][j], id[i - 1][j]);
            }
        }
        for (int j = 0; j < m; j++) {
            if (id[i][j] != -1) {
                last[j] = id[i][j];
            }
        }
        for (int j = 0; j < m; j++) {
            if (id[i][j] == -1) continue;
            if (j && last[j - 1] != -1) {
                scc.add(last[j - 1], id[i][j]);
            }
            if (j != m - 1 && last[j + 1] != -1) {
                scc.add(last[j + 1], id[i][j]);
            }
        }
    }

    auto scc_num = scc.scc();
    int new_vers = *max_element(all(scc_num)) + 1;
    vector<vector<int>> g(new_vers);
    vector<int> in_deg(new_vers);
    for (int v = 0; v < nvers; v++) {
        for (auto u : scc.g[v]) {
            if (scc_num[v] != scc_num[u]) {
                g[scc_num[v]].push_back(scc_num[u]);
                in_deg[scc_num[u]]++;
            }
        }
    }

    vector<bool> need(new_vers);
    for (int j = 0; j < m; j++) {
        if (a[j] == 0) continue;
        int i = n - 1;
        while (true) {
            if (grid[i][j] == '.') {
                i--;
                continue;
            }
            a[j]--;
            if (a[j] == 0) break;
            i--;
        }
        need[scc_num[id[i][j]]] = true;
    }

    vector<bool> removed(new_vers);
    queue<int> que;
    for (int i = 0; i < new_vers; i++) {
        if (in_deg[i] == 0) que.push(i);
    }

    auto initial_in_deg = in_deg;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto u : g[v]) {
            if (removed[v] || need[v]) removed[u] = true;
            if (--in_deg[u] == 0) que.push(u);
        }
    }
    in_deg = initial_in_deg;

    vector<vector<int>> scc_components(new_vers);
    for (int i = 0; i < nvers; i++) {
        scc_components[scc_num[i]].push_back(i);
    }

    vector<int> alive;
    for (int i = 0; i < new_vers; i++) {
        if (need[i] && !removed[i]) {
            for (auto id : scc_components[i]) {
                alive.push_back(col[id]);
            }
        }
    }
    sort(all(alive));
    alive.resize(unique(all(alive)) - alive.begin());

    if (alive.empty()) {
        cout << "0\n";
        return 0;
    }

    vector<int> from(new_vers, len(alive)), to(new_vers, -1);
    for (int i = 0; i < new_vers; i++) {
        if (need[i] && !removed[i]) {
            for (auto id : scc_components[i]) {
                int cur = lower_bound(all(alive), col[id]) - alive.begin();
                from[i] = min(from[i], cur);
                to[i] = max(to[i], cur);
            }
        }
    }

    vector<bool> used(new_vers);
    for (int i = 0; i < new_vers; i++) {
        if (used[i]) continue;

        y_combinator([&](auto dfs, int v) -> void {
            used[v] = true;
            for (auto u : g[v]) {
                if (!used[u]) dfs(u);
                from[v] = min(from[v], from[u]);
                to[v] = max(to[v], to[u]);
            }
        })(i);
    }

    vector<int> right(len(alive), -1);
    for (int i = 0; i < new_vers; i++) {
        if (to[i] == -1 || in_deg[i]) continue;
        right[from[i]] = max(right[from[i]], to[i]);
    }

    int ans = 0, cur = -1;
    for (int i = 0; cur < len(alive) - 1;) {
        assert(cur + 1 >= i);
        int mx = -1;
        for (; i <= cur + 1; i++) {
            mx = max(mx, right[i]);
        }
        assert(mx > cur);
        cur = mx;
        ans++;
    }
    cout << ans << '\n';
}