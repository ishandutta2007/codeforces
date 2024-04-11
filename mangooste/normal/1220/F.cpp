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

std::mt19937 __rng__(std::chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
struct cartesian_tree {
    struct node {
        T x, mx;
        int left, right, sz, y;
        T mod;

        node(T x) : x(x), mx(x), left(-1), right(-1), sz(1), y(__rng__()), mod(0) {}
    };

    int root;
    std::vector<node> tree;

    cartesian_tree() : root(-1) {}

    void push(int v) {
        if (v == -1 || tree[v].mod == 0)
            return;

        for (int u : {tree[v].left, tree[v].right})
            if (u != -1)
                tree[u].mod += tree[v].mod;

        tree[v].x += tree[v].mod;
        tree[v].mx += tree[v].mod;
        tree[v].mod = 0;
    }

    void relax(int v) {
        for (auto u : {tree[v].left, tree[v].right})
            if (u != -1)
                push(u);

        tree[v].sz = 1 + size(tree[v].left) + size(tree[v].right);
        tree[v].mx = max({tree[v].x, mx(tree[v].left), mx(tree[v].right)});
    }

    int mx(int v) {
        return v == -1 ? INT_MIN : tree[v].mx;
    }

    int size(int v) const {
        return (v == -1 ? 0 : tree[v].sz);
    }

    int new_node(T x) {
        int id = int(tree.size());
        tree.push_back(node(x));
        return id;
    }

    std::pair<int, int> split_by_size(int v, int n) {
        push(v);
        if (v == -1)
            return {v, v};

        if (size(tree[v].left) + 1 <= n) {
            auto cur = split_by_size(tree[v].right, n - size(tree[v].left) - 1);
            tree[v].right = cur.first;
            relax(v);
            return {v, cur.second};
        } else {
            auto cur = split_by_size(tree[v].left, n);
            tree[v].left = cur.second;
            relax(v);
            return {cur.first, v};
        }
    }

    int merge(int left, int right) {
        push(left), push(right);
        if (left == -1)
            return right;

        if (right == -1)
            return left;

        if (tree[left].y > tree[right].y) {
            tree[left].right = merge(tree[left].right, right);
            relax(left);
            return left;
        } else {
            tree[right].left = merge(left, tree[right].left);
            relax(right);
            return right;
        }
    }

    int get() {
        push(root);
        return tree[root].mx;
    }
};

struct segtree {
    int n;
    vector<pair<int, int>> tree;

    segtree(const vector<int> &perm) : n(len(perm)), tree(2 * n) {
        for (int i = 0; i < n; i++)
            tree[n + i] = {perm[i], i};

        for (int i = n - 1; i; i--)
            tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    }

    int get(int l, int r) {
        pair<int, int> best{n, -1};
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                best = min(best, tree[l++]);

            if (r & 1)
                best = min(best, tree[--r]);
        }
        return best.second;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> perm(n);
    for (auto &x : perm)
        cin >> x, x--;

    const int SHIFT = find(all(perm), 0) - perm.begin();
    rotate(perm.begin(), perm.begin() + SHIFT, perm.end());

    segtree tree(perm);
    vector<array<int, 2>> g(n, {-1, -1});

    y_combinator([&](auto build, int l, int r, int parent, int type) -> void {
        if (r <= l)
            return;

        int mn = tree.get(l, r);
        g[parent][type] = mn;
        build(l, mn, mn, 0);
        build(mn + 1, r, mn, 1);
    })(1, n, 0, 1);

    cartesian_tree<int> order;

    y_combinator([&](auto dfs, int v, int depth) -> void {
        if (v == -1)
            return;

        order.root = order.merge(order.root, order.new_node(depth));
        for (int i : {0, 1})
            dfs(g[v][i], depth + 1);
    })(0, 1);

    vector<int> left_stack;
    for (int v = 0; v != -1; v = g[v][0])
        left_stack.push_back(v);

    vector<int> right_stack;
    for (int v = 0; v != -1; v = g[v][1])
        right_stack.push_back(v);

    pair<int, int> answer{n + 1, -1};
    for (int i = 0; i < n; i++) {
        answer = min(answer, pair<int, int>{order.get(), i});
        if (i == n - 1)
            continue;

        int who = right_stack.back();
        right_stack.pop_back();

        {
            int cnt = n - 1 - (right_stack.back() + i) % n;
            auto [left, mid_right] = order.split_by_size(order.root, n - cnt);
            auto [mid, right] = order.split_by_size(mid_right, 1);

            if (right != -1)
                order.tree[right].mod--;

            order.root = order.merge(left, right);
        }

        {
            while (perm[left_stack.back()] > perm[who])
                left_stack.pop_back();

            int cnt = (left_stack.back() + i) % n;
            left_stack.push_back(who);

            auto [left, mid_right] = order.split_by_size(order.root, len(left_stack) - 1);
            auto [mid, right] = order.split_by_size(mid_right, cnt);
            if (mid != -1)
                order.tree[mid].mod++;

            order.root = order.merge(left, order.new_node(len(left_stack)));
            order.root = order.merge(order.root, order.merge(mid, right));
        }

        for (int v = g[who][0]; v != -1; v = g[v][1])
            right_stack.push_back(v);
    }

    cout << answer.first << ' ' << (n - answer.second + SHIFT) % n << '\n';
}