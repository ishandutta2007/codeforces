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

template<int SZ, typename T>
struct aho_korasik {
    struct node {
        node* nxt[SZ], *parent;
        std::vector<int> ends;
        int parent_index, depth;
        node* suffix_link, *supper_suffix_link;

        // extra data
        int vertex_id = -1;

        node() : parent(nullptr), parent_index(-1), depth(0), suffix_link(nullptr), supper_suffix_link(nullptr) {
            std::fill(std::begin(nxt), std::end(nxt), nullptr);
        }

        bool is_terminal() const {
            return !ends.empty();
        }

        node* go_ignoring_extra_edges(int index) const {
            node* v = nxt[index];
            return v && v->depth == depth + 1 ? v : nullptr;
        }
    };

    T index;
    node* root;

    aho_korasik(T index) : index(index), root(new node()) {}

    template<typename U>
    node* add(const U &str, int id = -1) {
        node* v = root;
        for (int i = 0; i < int(str.size()); i++) {
            int cur_index = index(str[i]);
            if (!v->nxt[cur_index]) {
                v->nxt[cur_index] = new node();
                v->nxt[cur_index]->parent = v;
                v->nxt[cur_index]->parent_index = cur_index;
                v->nxt[cur_index]->depth = v->depth + 1;
            }
            v = v->nxt[cur_index];
        }
        if (id != -1)
            v->ends.push_back(id);

        return v;
    }

    void init() {
        std::queue<node*> que;
        que.push(root);

        while (!que.empty()) {
            node* v = que.front();
            que.pop();

            if (v != root) {
                if (v->parent == root)
                    v->suffix_link = root;
                else
                    v->suffix_link = v->parent->suffix_link->nxt[v->parent_index];

                if (v->suffix_link->is_terminal())
                    v->supper_suffix_link = v->suffix_link;
                else
                    v->supper_suffix_link = v->suffix_link->supper_suffix_link;
            }

            for (int i = 0; i < SZ; i++)
                if (v->nxt[i])
                    que.push(v->nxt[i]);
                else if (v == root)
                    v->nxt[i] = root;
                else
                    v->nxt[i] = v->suffix_link->nxt[i];
        }
    }

    std::vector<node*> get_vertices() {
        std::vector<node*> vertices{root};
        for (int i = 0; i < int(vertices.size()); i++)
            for (int j = 0; j < SZ; j++) {
                auto vertex = vertices[i]->go_ignoring_extra_edges(j);
                if (vertex)
                    vertices.push_back(vertex);
            }

        return vertices;
    }

    ~aho_korasik() {
        for (auto vertex : get_vertices())
            delete vertex;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    
    auto index = [&](const char c) {
        return c - 'a';
    };
    using T = aho_korasik<26, decltype(index)>;
    T aho(index);
    vector<string> s(n);
    vector<vector<T::node*>> path(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        aho.add(s[i], i);

        path[i].reserve(len(s[i]));
        auto v = aho.root;
        for (int pos = 0; pos < len(s[i]); pos++) {
            v = v->nxt[index(s[i][pos])];
            path[i].push_back(v);
        }
    }

    int sz = 0;
    y_combinator([&](auto dfs, T::node* v) -> void {
        if (!v) return;
        v->vertex_id = sz++;
        for (int c = 0; c < 26; c++) {
            dfs(v->nxt[c]);
        }
    })(aho.root);

    assert(aho.root->vertex_id == 0); // root of the tree
    aho.init();
    vector<vector<int>> tree(sz);
    for (auto v : aho.get_vertices()) {
        if (v->suffix_link) {
            tree[v->suffix_link->vertex_id].push_back(v->vertex_id);
        }
    }

    vector<int> tin(sz), tout(sz);
    int timer = 0;
    y_combinator([&](auto dfs, int v) -> void {
        tin[v] = timer++;
        for (auto u : tree[v]) dfs(u);
        tout[v] = timer++;
    })(0);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> left(len(s[i]), len(s[i]));
        vector<T::node*> where(len(s[i]));

        for (int pos = 0; pos < len(s[i]); pos++) {
            auto v = path[i][pos];
            if (pos == len(s[i]) - 1) v = v->suffix_link;
            if (!v->is_terminal()) v = v->supper_suffix_link;
            where[pos] = v;
            if (!v) continue;
            left[pos] = pos - v->depth + 1;
        }

        vector<pair<int, int>> suf_min(len(s[i]) + 1, {len(s[i]), -1});
        for (int pos = len(s[i]) - 1; pos >= 0; pos--) {
            suf_min[pos] = suf_min[pos + 1];
            if (suf_min[pos].first > left[pos]) {
                suf_min[pos] = {left[pos], pos};
            }
        }

        vector<int> good;
        good.reserve(len(s[i]));
        for (int pos = 0; pos < len(s[i]); pos++) {
            if (suf_min[pos].first <= pos) good.push_back(pos);
        }
        sort(all(good), [&](const int i, const int j) {
            if (i - suf_min[i].first != j - suf_min[j].first) {
                return i - suf_min[i].first > j - suf_min[j].first;
            }
            if (suf_min[j].second != j) return false;
            if (suf_min[i].second != i) return true;
            return false;
        });

        set<int> bad;
        for (auto pos : good) {
            if (suf_min[pos].second == pos) {
                int id = where[pos]->vertex_id;
                auto it = bad.lower_bound(tin[id]);
                if (it == bad.end() || *it >= tout[id]) ans++;
            }
            int str_id = where[suf_min[pos].second]->ends[0];
            int id = path[str_id][pos - suf_min[pos].first]->vertex_id;
            bad.insert(tin[id]);
        }
    }
    cout << ans << '\n';
}