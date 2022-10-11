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
    int n;
    vector<int> tree;

    segtree(int n) : tree(2 * n) {}

    void init(int size) {
        n = size;
        fill(tree.begin(), tree.begin() + 2 * n, 0);
    }

    void setmax(int pos, int value) {
        pos += n;
        tree[pos] = max(tree[pos], value);

        for (pos >>= 1; pos > 0; pos >>= 1)
            tree[pos] = max(tree[pos << 1], tree[pos << 1 | 1]);
    }

    int get(int l, int r) {
        int answer = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                answer = max(answer, tree[l++]);

            if (r & 1)
                answer = max(answer, tree[--r]);
        }
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    int k;
    cin >> k;
    vector<int> que(k);
    vector<int> dist(n, n);
    for (auto &x : que) {
        cin >> x;
        x--;
        dist[x] = 0;
    }

    for (int st = 0; st < len(que); st++) {
        int v = que[st];
        for (auto u : g[v])
            if (dist[u] > dist[v] + 1) {
                dist[u] = dist[v] + 1;
                que.push_back(u);
            }
    }

    vector<int> answer(n);
    vector<int> size(n);
    vector<int> depth(n);
    segtree tree(2 * n);

    y_combinator([&](auto dfs, int v) -> void {
        int total_size = y_combinator([&](auto dfs, int v, int parent) -> int {
            size[v] = 1;
            for (auto u : g[v])
                if (u != parent)
                    size[v] += dfs(u, v);

            return size[v];
        })(v, -1);

        v = y_combinator([&](auto dfs, int v, int parent) -> int {
            for (auto u : g[v])
                if (u != parent && 2 * size[u] > total_size)
                    return dfs(u, v);

            return v;
        })(v, -1);

        depth[v] = 0;
        vector<int> values;
        values.reserve(2 * total_size);

        y_combinator([&](auto dfs, int v, int parent) -> void {
            values.push_back(depth[v]);
            values.push_back(dist[v] - depth[v]);

            for (auto u : g[v])
                if (u != parent) {
                    depth[u] = depth[v] + 1;
                    dfs(u, v);
                }
        })(v, -1);

        sort(all(values));
        values.resize(unique(all(values)) - values.begin());
        int m = len(values);

        auto get_id = [&](int x) {
            return lower_bound(all(values), x) - values.begin();
        };

        for (int rot = 0; rot < 2; rot++, reverse(all(g[v]))) {
            tree.init(m);

            auto insert_vertex = [&](int v) {
                tree.setmax(get_id(dist[v] - depth[v]), dist[v]);
            };

            auto update_vertex = [&](int v) {
                answer[v] = max(answer[v], tree.get(get_id(depth[v]) + 1, m));
            };

            insert_vertex(v);
            for (auto u : g[v]) {
                y_combinator([&](auto dfs, int v, int parent) -> void {
                    update_vertex(v);
                    for (auto u : g[v])
                        if (u != parent)
                            dfs(u, v);
                })(u, v);

                y_combinator([&](auto dfs, int v, int parent) -> void {
                    insert_vertex(v);
                    for (auto u : g[v])
                        if (u != parent)
                            dfs(u, v);
                })(u, v);
            }
            update_vertex(v);
        }

        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            dfs(u);
        }
    })(0);

    for (int i = 0; i < n; i++)
        cout << answer[i] << " \n"[i == n - 1];
}