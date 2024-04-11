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

    if (n == 1)
        return 0;

    if (n == 2) {
        cout << "1 2 1\n";
        return 0;
    }

    vector<int> size(n);

    auto init_sizes = y_combinator([&](auto dfs, int v, int parent) -> void {
        size[v] = 1;
        for (const auto u : g[v])
            if (u != parent) {
                dfs(u, v);
                size[v] += size[u];
            }
    });
    init_sizes(0, -1);

    const int root = y_combinator([&](auto dfs, int v, int parent) -> int {
        for (const auto u : g[v])
            if (u != parent && 2 * size[u] > n)
                return dfs(u, v);

        return v;
    })(0, -1);

    vector<int> parent(len(g[root]));
    iota(all(parent), 0);

    auto get_root = y_combinator([&](auto root, int v) -> int {
        return parent[v] == v ? v : parent[v] = root(parent[v]);
    });

    init_sizes(root, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 0; i < len(g[root]); i++)
        pq.push({size[g[root][i]], i});

    auto pop = [&]() {
        auto value = pq.top();
        pq.pop();
        return value;
    };

    while (len(pq) > 2) {
        const auto [size_a, a] = pop();
        const auto [size_b, b] = pop();
        parent[a] = b;
        pq.push({size_a + size_b, b});
    }

    const auto [size1, group1] = pop();
    const auto [size2, group2] = pop();

    int ptr1 = 0;
    vector<int> values1(size1);
    iota(all(values1), 1);

    int ptr2 = 0;
    vector<int> values2(size2);
    iota(all(values2), 1);
    for (auto &x : values2)
        x *= size1 + 1;

    vector<array<int, 3>> edges;
    edges.reserve(n - 1);

    auto dfs = y_combinator([&](auto dfs, int v, int parent, const vector<int> &values, int &ptr, int sum_up) -> void {
        for (const auto u : g[v])
            if (u != parent) {
                assert(values[ptr] > sum_up);
                edges.push_back({v, u, values[ptr] - sum_up});
                ptr++;
                dfs(u, v, values, ptr, values[ptr - 1]);
            }
    });

    for (int i = 0; i < len(g[root]); i++)
        if (get_root(i) == group1) {
            edges.push_back({root, g[root][i], values1[ptr1++]});
            dfs(g[root][i], root, values1, ptr1, values1[ptr1 - 1]);
        } else {
            edges.push_back({root, g[root][i], values2[ptr2++]});
            dfs(g[root][i], root, values2, ptr2, values2[ptr2 - 1]);
        }

    assert(len(edges) == n - 1);
    for (const auto &[v, u, w] : edges)
        cout << v + 1 << ' ' << u + 1 << ' ' << w << '\n';
}