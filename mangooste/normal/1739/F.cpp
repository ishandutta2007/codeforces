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

template<typename A, typename B>
bool setmin(A &a, const B &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<typename A, typename B>
bool setmax(A &a, const B &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<int SZ, typename T>
struct aho_korasik {
    struct node {
        node* nxt[SZ], *parent;
        std::vector<int> ends;
        int parent_index, depth;
        node* suffix_link, *supper_suffix_link;

        // extra info
        int sum = 0, dp[1 << SZ];
        pair<node*, int> par[1 << SZ];

        node() : parent(nullptr), parent_index(-1), depth(0), suffix_link(nullptr), supper_suffix_link(nullptr) {
            std::fill(std::begin(nxt), std::end(nxt), nullptr);
            fill(all(dp), -1e9);
            fill(all(par), pair{nullptr, -1});
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

    constexpr int A = 12;
    auto index = [](char c) {
        return c - 'a';
    };
    aho_korasik<A, decltype(index)> aho(index);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int cost;
        string s;
        cin >> cost >> s;

        string t;
        t += s[1];
        t += s[0];
        vector<bool> used(A);
        used[s[0] - 'a'] = true;
        used[s[1] - 'a'] = true;

        bool fail = false;
        for (int i = 2, pos = 0; i < len(s); i++) {
            if (used[s[i] - 'a']) {
                if (pos && t[pos - 1] == s[i]) {
                    pos--;
                } else if (pos + 1 < len(t) && t[pos + 1] == s[i]) {
                    pos++;
                } else {
                    fail = true;
                    break;
                }
            } else {
                used[s[i] - 'a'] = true;
                if (pos == 0) {
                    t = s[i] + t;
                } else if (pos == len(t) - 1) {
                    t += s[i];
                    pos++;
                } else {
                    fail = true;
                    break;
                }
            }
        }

        if (fail) continue;
        string rev_t = t;
        reverse(all(rev_t));
        assert(t != rev_t);
        aho.add(t)->sum += cost;
        aho.add(rev_t)->sum += cost;
    }

    aho.init();
    auto vertices = aho.get_vertices();
    for (auto v : vertices) {
        if (v->suffix_link) v->sum += v->suffix_link->sum;
    }

    aho.root->dp[0] = 0;
    for (int mask = 0; mask < (1 << A) - 1; mask++) {
        for (auto v : vertices) {
            for (int nxt = 0; nxt < A; nxt++) {
                if (mask >> nxt & 1) continue;
                int nmask = mask ^ (1 << nxt);
                auto u = v->nxt[nxt];
                if (setmax(u->dp[nmask], v->dp[mask] + u->sum)) {
                    u->par[nmask] = {v, nxt};
                }
            }
        }
    }

    int ans = -1e9;
    decltype(aho.root) where = nullptr;
    for (auto v : vertices) {
        if (setmax(ans, v->dp[(1 << A) - 1])) {
            where = v;
        }
    }
    assert(where);
    dbg(ans);

    string res;
    for (int i = 0, mask = (1 << A) - 1; i < A; i++) {
        int cur_c = where->par[mask].second;
        res += 'a' + cur_c;
        where = where->par[mask].first;
        assert(mask >> cur_c & 1);
        mask ^= 1 << cur_c;
    }
    reverse(all(res));
    cout << res << '\n';
}