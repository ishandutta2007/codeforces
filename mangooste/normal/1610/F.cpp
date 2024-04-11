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

struct link_cut {
    struct node {
        int parent;
        std::array<int, 2> sons;
        bool inv;
        int size;

        node() : parent(-1), sons({-1, -1}), inv(false), size(1) {}
    };

    std::vector<node> tree;

    int size() const {
        return tree.size();
    }

    void push(int v) {
        if (tree[v].inv) {
            tree[v].inv = false;
            std::swap(tree[v].sons[0], tree[v].sons[1]);
            for (const auto u : tree[v].sons)
                if (u != -1)
                    tree[u].inv ^= 1;
        }
    }

    void relax(int v) {
        push(v);
        tree[v].size = 1;
        for (const auto x : tree[v].sons)
            if (x != -1)
                tree[v].size += tree[x].size;
    }

    void rotate(int v) {
        int u = tree[v].parent, w = tree[u].parent;
        push(u), push(v);

        tree[v].parent = w;
        if (w != -1)
            for (auto &x : tree[w].sons)
                if (x == u)
                    x = v;

        int i = tree[u].sons[1] == v;
        tree[u].sons[i] = tree[v].sons[i ^ 1];
        if (tree[v].sons[i ^ 1] != -1)
            tree[tree[v].sons[i ^ 1]].parent = u;

        tree[v].sons[i ^ 1] = u;
        tree[u].parent = v;
        relax(u), relax(v);
    }

    bool is_root(int v) const {
        return tree[v].parent == -1 || (tree[tree[v].parent].sons[0] != v && tree[tree[v].parent].sons[1] != v);
    }

    void splay(int v) {
        while (!is_root(v)) {
            int u = tree[v].parent;
            if (!is_root(u))
                rotate((tree[tree[u].parent].sons[0] == u) == (tree[u].sons[0] == v) ? u : v);

            rotate(v);
        }
        push(v);
    }

    int expose(int v) {
        int prev = -1;
        for (int u = v; u != -1; prev = u, u = tree[u].parent) {
            splay(u);
            tree[u].sons[1] = prev;
            relax(u);
        }
        splay(v);
        assert(tree[v].sons[1] == -1 && tree[v].parent == -1);
        return prev;
    }

    link_cut(int n = 0) : tree(n) {}

    int add() {
        tree.push_back(node());
        return int(tree.size()) - 1;
    }

    void set_root(int root) {
        expose(root);
        tree[root].inv ^= 1;
        push(root);
    }

    bool connected(int v, int u) {
        if (v == u)
            return true;

        expose(v), expose(u);
        return tree[v].parent != -1;
    }

    bool link(int v, int u) {
        if (connected(v, u))
            return false;

        tree[u].inv ^= 1;
        tree[u].parent = v;
        expose(u);
        return true;
    }

    bool cut(int v, int u) {
        if (v == u)
            return false;

        set_root(v), expose(u);
        if (tree[u].sons[0] != v)
            return false;

        tree[u].sons[0] = -1;
        relax(u);
        tree[v].parent = -1;
        return true;
    }

    int parent(int v, int root) {
        if (!connected(v, root))
            return -1;

        set_root(root), expose(v);
        if (tree[v].sons[0] == -1)
            return -1;

        v = tree[v].sons[0];
        while (push(v), tree[v].sons[1] != -1)
            v = tree[v].sons[1];

        splay(v);
        return v;
    }

    int distance(int v, int u) {
        if (!connected(v, u))
            return -1;

        set_root(v), expose(u);
        return tree[u].sons[0] == -1 ? 0 : tree[tree[u].sons[0]].size;
    }

    int lca(int v, int u, int root) {
        set_root(root), expose(v);
        return expose(u);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    array<vector<vector<int>>, 2> g;
    g.fill(vector<vector<int>>(n));
    vector<array<int, 3>> edges(m);

    for (auto &[v, u, w] : edges) {
        cin >> v >> u >> w;
        v--, u--, w--;
        g[w][v].push_back(u);
        g[w][u].push_back(v);
    }

    int ans = 0;
    for (int v = 0; v < n; v++) {
        ans += len(g[0][v]) % 2;
    }
    cout << ans << '\n';

    multiset<array<int, 3>> new_edges;
    array<vector<vector<int>>, 2> new_g;
    new_g.fill(vector<vector<int>>(n));
    for (int type : {0, 1}) {
        link_cut lct(n);
        for (int v = 0; v < n; v++) {
            for (auto u : g[type][v]) {
                if (v > u) continue;
                if (lct.link(v, u)) continue;
                new_edges.insert({v, u, type + 1});
                while (u != v) {
                    int p = lct.parent(u, v);
                    lct.cut(u, p);
                    new_edges.insert({u, p, type + 1});
                    u = p;
                }
            }
        }

        for (int v = 0; v < n; v++) {
            for (auto u : g[type][v]) {
                if (v > u) continue;
                if (lct.parent(u, v) != v) continue;
                lct.cut(u, v);
                new_g[type][v].push_back(u);
                new_g[type][u].push_back(v);
            }
        }
    }
    swap(g, new_g);

    vector<int> par(n, -1);
    vector<bool> used(n);
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        par[i] = i;

        y_combinator([&](auto dfs, int v) -> void {
            used[v] = true;
            for (auto u : g[0][v]) {
                g[0][u].erase(find(all(g[0][u]), v));
                par[u] = v;
                dfs(u);
            }
        })(i);
    }

    fill(all(used), false);
    vector<vector<int>> paths;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;

        auto path = y_combinator([&](auto dfs, int v) -> vector<int> {
            used[v] = true;
            vector<int> cur_path;

            for (auto u : g[1][v]) {
                g[1][u].erase(find(all(g[1][u]), v));
                auto new_path = dfs(u);
                if (cur_path.empty()) {
                    cur_path = new_path;
                    continue;
                }

                reverse(all(new_path));
                cur_path.push_back(v);
                for (auto x : new_path) cur_path.push_back(x);
                paths.push_back({});
                swap(paths.back(), cur_path);
            }
            cur_path.push_back(v);
            return cur_path;
        })(i);

        if (path.size() > 1) paths.push_back(path);
    }

    multiset<pair<int, int>> new_e;
    link_cut lct(n + 1);
    for (auto &path : paths) {
        assert(len(path) > 1);
        int first = par[path[0]], last = par[path.back()];
        if (lct.link(first, last)) continue;
        new_e.emplace(last, first);
        while (first != last) {
            int p = lct.parent(first, last);
            lct.cut(first, p);
            new_e.emplace(first, p);
            first = p;
        }
    }

    vector<vector<int>> gg(n + 1);
    for (auto &path : paths) {
        int first = par[path[0]], last = par[path.back()];
        if (lct.parent(first, last) != last) continue;
        lct.cut(first, last);
        gg[first].push_back(last);
        gg[last].push_back(first);
    }

    used.assign(n + 1, false);
    for (int i = 0; i <= n; i++) {
        if (used[i]) continue;

        auto add_path = [&](const vector<int> &path) {
            for (int i = 0; i < len(path) - 1; i++) {
                new_e.emplace(path[i], path[i + 1]);
            }
        };

        auto path = y_combinator([&](auto dfs, int v) -> vector<int> {
            used[v] = true;
            vector<int> cur_path;

            for (auto u : gg[v]) {
                gg[u].erase(find(all(gg[u]), v));
                auto new_path = dfs(u);
                if (cur_path.empty()) {
                    cur_path = new_path;
                    continue;
                }

                reverse(all(new_path));
                cur_path.push_back(v);
                for (auto x : new_path) cur_path.push_back(x);
                add_path(cur_path);
                cur_path.clear();
            }
            cur_path.push_back(v);
            return cur_path;
        })(i);

        if (path.size() > 1) add_path(path);
    }

    vector<array<set<int>, 2>> taked(n + 1);
    for (auto &path : paths) {
        int first = path[0], last = path.back();
        auto it = new_e.find({par[first], par[last]});
        if (it == new_e.end()) {
            it = new_e.find({par[last], par[first]});
            swap(first, last);
            reverse(all(path));
        }

        assert(it != new_e.end());
        new_e.erase(it);

        taked[par[first]][0].insert(first);
        taked[par[last]][1].insert(last);
        for (int i = 0; i < len(path) - 1; i++) {
            new_edges.insert({path[i], path[i + 1], 2});
        }
    }

    fill(all(used), false);
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;

        y_combinator([&](auto dfs, int v) -> void {
            used[v] = true;
            assert(abs(len(taked[v][0]) - len(taked[v][1])) <= 1);
            int cur = len(taked[v][1]) < len(taked[v][0]);

            for (auto u : g[0][v]) {
                auto insert_edge = [&](int type) {
                    if (type) {
                        new_edges.insert({u, v, 1});
                    } else {
                        new_edges.insert({v, u, 1});
                    }
                };

                bool any = false;
                for (int rot : {0, 1}) {
                    if (taked[v][rot].count(u)) {
                        assert(!any);
                        any = true;
                        insert_edge(rot);
                    }
                }

                if (!any) {
                    insert_edge(cur);
                    cur ^= 1;
                }
                dfs(u);
            }
        })(i);
    }

    for (auto [v, u, w] : edges) {
        auto it = new_edges.find({v, u, w + 1});
        if (it == new_edges.end()) {
            it = new_edges.find({u, v, w + 1});
            cout << 2;
        } else {
            cout << 1;
        }

        assert(it != new_edges.end());
        new_edges.erase(it);
    }
    cout << '\n';
}