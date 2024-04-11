#include <bits/stdc++.h>

struct disjoin_set_union {
    std::vector<int> parent;
    std::vector<int> rank;

    disjoin_set_union(int n = 0) : parent(n), rank(n, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int root(int v) {
        return (v ^ parent[v]) ? parent[v] = root(parent[v]) : v;
    }

    bool unite(int v, int u) {
        v = root(v), u = root(u);
        if (v == u)
            return false;

        if (rank[v] < rank[u])
            std::swap(v, u);

        rank[v] += rank[u];
        parent[u] = v;
        return true;
    }
};

struct link_cut {
    struct node {
        int parent;
        std::array<int, 2> sons;
        bool inv;
        int size;

        int value, tot;

        node() : parent(-1), sons({-1, -1}), inv(false), size(1), value(0), tot(0) {}
    };

    std::vector<node> tree;

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

        tree[v].tot = tree[v].value;
        for (const auto x : tree[v].sons)
            if (x != -1)
                tree[v].tot ^= tree[x].tot;
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

    bool is_root(int v) {
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

    void expose(int v) {
        for (int u = v, prev = -1; u != -1; prev = u, u = tree[u].parent) {
            splay(u);
            tree[u].sons[1] = prev;
            relax(u);
        }
        splay(v);
    }

    link_cut(int n = 0) : tree(n) {}

    int add() {
        tree.push_back(node());
        return int(tree.size()) - 1;
    }

    void set_root(int root) {
        expose(root);
        tree[root].inv ^= 1;
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

    void update(int v, int value) {
        splay(v);
        tree[v].value = value;
        relax(v);
    }

    int query(int v, int u) {
        set_root(v), expose(u);
        return tree[u].value ^ tree[tree[u].sons[0]].tot;
    }
};

int main() {
    using namespace std;
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    disjoin_set_union dsu(n);
    link_cut g(n + m);

    for (int id = n; id < n + m; id++) {
        int v, u, c;
        cin >> v >> u >> c;
        v--, u--;

        if (dsu.root(v) != dsu.root(u)) {
            cout << "YES\n";
            dsu.unite(v, u);

            g.link(v, id);
            g.link(u, id);
            g.update(id, c);
        } else {
            if (!g.connected(v, u) || (g.query(v, u) ^ c) == 0) {
                cout << "NO\n";
                continue;
            }

            cout << "YES\n";
            while (u != v) {
                int w = g.parent(u, v);
                g.cut(u, w);
                u = w;
            }
        }
    }
}