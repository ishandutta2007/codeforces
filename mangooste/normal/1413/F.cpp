#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

template<typename Fun>
class y_combinator {
    const Fun fun_;
public:
    explicit y_combinator(const Fun&& fun) : fun_(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    decltype(auto) operator()(Args&&... args) const {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

struct segtree {
    struct node {
        bool mod;
        array<int, 2> deapest;

        node() : mod(false), deapest({-1, -1}) {}
    };

    node merge(const node &left, const node &right) {
        node res;
        for (int i : {0, 1})
            res.deapest[i] = max(left.deapest[i], right.deapest[i]);

        return res;
    }

    int n;
    vector<node> tree;

    segtree() {}
    segtree(int n) : n(n), tree(4 * n) {}

    void push(int v, int vl, int vr) {
        if (!tree[v].mod)
            return;

        if (vr - vl > 1)
            tree[v << 1].mod ^= 1, tree[v << 1 | 1].mod ^= 1;

        swap(tree[v].deapest[0], tree[v].deapest[1]);
        tree[v].mod = false;
    }

    void set(int pos, int type, int depth) {
        set(1, 0, n, pos, type, depth);
    }

    void set(int v, int vl, int vr, int pos, int type, int depth) {
        if (vr - vl == 1) {
            tree[v].deapest[type] = depth;
            return;
        }

        int vm = (vl + vr) >> 1;
        pos < vm ? set(v << 1, vl, vm, pos, type, depth) : set(v << 1 | 1, vm, vr, pos, type, depth);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }

    void inv(int l, int r) {
        inv(1, 0, n, l, r);
    }

    void inv(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (r <= vl || vr <= l)
            return;

        if (l <= vl && vr <= r) {
            tree[v].mod ^= 1;
            push(v, vl, vr);
            return;
        }

        int vm = (vl + vr) >> 1;
        inv(v << 1, vl, vm, l, r);
        inv(v << 1 | 1, vm, vr, l, r);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }

    int get() {
        push(1, 0, n);
        return tree[1].deapest[0];
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<array<int, 3>> edges(n - 1);
    vector<vector<pair<int, int>>> g(n);

    for (auto &[v, u, t] : edges) {
        cin >> v >> u >> t, v--, u--;
        g[v].emplace_back(u, t);
        g[u].emplace_back(v, t);
    }

    auto find_deapest = y_combinator([&](auto dfs, int v, int parent, int depth) -> pair<int, int> {
        pair<int, int> deapest{depth, v};
        for (const auto &[u, t] : g[v])
            if (u != parent)
                deapest = max(deapest, dfs(u, v, depth + 1));

        return deapest;
    });

    array<int, 2> roots;
    roots[0] = find_deapest(0, -1, 0).second;
    roots[1] = find_deapest(roots[0], -1, 0).second;

    array<segtree, 2> trees;
    trees.fill(segtree(n));

    array<vector<int>, 2> tin, tout;
    tin.fill(vector<int>(n));
    tout.fill(vector<int>(n));

    for (int i : {0, 1}) {
        int timer = 0;
        y_combinator([&](auto dfs, int v, int parent, int depth, int type) -> void {
            tin[i][v] = timer++;
            trees[i].set(tin[i][v], type, depth);

            for (const auto &[u, t] : g[v])
                if (u != parent)
                    dfs(u, v, depth + 1, type ^ t);

            tout[i][v] = timer;
        })(roots[i], -1, 0, 0);
    }

    int q;
    cin >> q;
    while (q--) {
        int id;
        cin >> id, id--;

        int answer = 0;
        for (int i : {0, 1}) {
            int v = tin[i][edges[id][0]] < tin[i][edges[id][1]] ? edges[id][1] : edges[id][0];
            trees[i].inv(tin[i][v], tout[i][v]);
            answer = max(answer, trees[i].get());
        }
        cout << answer << '\n';
    }
}