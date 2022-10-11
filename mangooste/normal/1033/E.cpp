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

    if (n == 1) {
        cout << "Y 1\n1\n";
        return 0;
    }

    auto query = [&](const vector<int> &s) {
        cout << "? " << len(s) << '\n';
        for (auto v : s)
            cout << v + 1 << ' ';

        cout << endl;

        int res;
        cin >> res;
        return res;
    };

    auto find_edge = [&](const vector<int> &first, const vector<int> &second, const vector<int> &pref_edges) {
        int l = -1, r = len(second), last_res = -1;
        while (r - l > 1) {
            int mid = (l + r) >> 1;

            vector v(second.begin(), second.begin() + mid + 1);
            int tot = -query(v) - pref_edges[len(first) - 1];

            v.insert(v.begin(), all(first));
            tot += query(v);

            if (tot != 0) {
                r = mid;
                last_res = tot;
            } else {
                l = mid;
            }
        }

        int vertex = second[r];
        l = -1, r = len(first) - 1;
        while (r - l > 1) {
            int mid = (l + r) >> 1;

            vector v(first.begin(), first.begin() + mid + 1);
            v.push_back(vertex);

            (query(v) - pref_edges[mid] > 0 ? r : l) = mid;
        }

        return array{first[r], vertex, last_res};
    };

    vector<int> alive(n - 1);
    iota(all(alive), 1);
    vector<int> pref_edges{0}, cur_set{0};
    vector<vector<int>> g(n);

    for (int i = 1; i < n; i++) {
        auto [v, u, new_edges] = find_edge(cur_set, alive, pref_edges);
        pref_edges.push_back(pref_edges.back() + new_edges);
        alive.erase(find(all(alive), u));

        cur_set.push_back(u);
        g[v].push_back(u);
        g[u].push_back(v);
    }

    array<vector<int>, 2> groups;

    y_combinator([&](auto dfs, int v, int p, int type) -> void {
        groups[type].push_back(v);
        for (auto u : g[v])
            if (u != p)
                dfs(u, v, type ^ 1);
    })(0, 0, 0);

    assert(!groups[0].empty() && !groups[1].empty());
    for (auto group : groups) {
        if (query(group) == 0)
            continue;

        int v = -1, u = -1;
        pref_edges.assign(len(group) + 1, 0);

        for (int i = 1; i < len(group); i++) {
            if (query(vector(group.begin(), group.begin() + i + 1)) != 0) {
                vector first(group.begin(), group.begin() + i), second(group.begin() + i, group.end());
                auto [cur_v, cur_u, lol] = find_edge(first, second, pref_edges);
                v = cur_v;
                u = cur_u;
                break;
            }
        }

        assert(v != -1 && u != -1);
        vector<int> parent(n);

        y_combinator([&](auto dfs, int v) -> void {
            for (auto u : g[v]) {
                g[u].erase(find(all(g[u]), v));
                parent[u] = v;
                dfs(u);
            }
        })(v);

        vector<int> cycle;
        for (; u != v; u = parent[u])
            cycle.push_back(u);

        cycle.push_back(v);
        assert(len(cycle) % 2);

        cout << "N " << len(cycle) << '\n';
        for (int i = 0; i < len(cycle); i++)
            cout << cycle[i] + 1 << " \n"[i == len(cycle) - 1];

        return 0;
    }

    cout << "Y " << len(groups[0]) << '\n';
    for (int i = 0; i < len(groups[0]); i++)
        cout << groups[0][i] + 1 << " \n"[i == len(groups[0]) - 1];
}