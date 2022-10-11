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

struct edge {
    int v, u;
    ll w;

    bool operator<(const edge &e) const {
        return w < e.w;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<edge> good_edges;
    vector<vector<pair<int, int>>> g(n);

    while (m--) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;

        if (v < k && u < k) {
            good_edges.push_back({v, u, w});
            continue;
        }

        g[v].emplace_back(u, w);
        g[u].emplace_back(v, w);
    }

    vector<ll> dist(n, LLONG_MAX);
    vector<int> color(n);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    for (int i = 0; i < k; i++) {
        dist[i] = 0;
        color[i] = i;
        pq.push({dist[i], i});
    }

    while (len(pq)) {
        const auto [d, v] = pq.top();
        pq.pop();
        if (d != dist[v])
            continue;

        for (const auto &[u, w] : g[v])
            if (dist[u] > d + w) {
                dist[u] = d + w;
                color[u] = color[v];
                pq.push({dist[u], u});
            }
    }

    map<pair<int, int>, ll> mp;
    for (int v = 0; v < n; v++)
        for (const auto &[u, w] : g[v])
            if (color[v] != color[u]) {
                const pair<int, int> key = minmax(color[v], color[u]);
                if (mp.find(key) == mp.end())
                    mp[key] = dist[v] + dist[u] + w;
                else
                    mp[key] = min(mp[key], dist[v] + dist[u] + w);
            }

    for (const auto &[pair, w] : mp)
        good_edges.push_back({pair.first, pair.second, w});

    vector<vector<pair<int, ll>>> tree(n);
    auto add_edge = [&](int v, int u, ll w) {
        tree[v].emplace_back(u, w);
        tree[u].emplace_back(v, w);
    };

    sort(all(good_edges));
    disjoin_set_union dsu(k);

    for (const auto &[v, u, w] : good_edges)
        if (dsu.unite(v, u))
            add_edge(v, u, w);

    for (int i = 1; i < k; i++)
        assert(dsu.root(i) == dsu.root(0));

    const int LG = __lg(k) + 1;
    vector<vector<int>> parent(LG, vector<int>(k));
    vector<vector<ll>> max_cost(LG, vector<ll>(k));

    const int root = 0;
    parent[0][root] = 0;
    max_cost[0][root] = LLONG_MIN;

    vector<int> depth(n);

    y_combinator([&](auto dfs, int v) -> void {
        for (int level = 1; level < LG; level++) {
            parent[level][v] = parent[level - 1][parent[level - 1][v]];
            max_cost[level][v] = max(max_cost[level - 1][v], max_cost[level - 1][parent[level - 1][v]]);
        }

        for (const auto &[u, w] : tree[v])
            if (u != parent[0][v]) {
                parent[0][u] = v;
                max_cost[0][u] = w;
                depth[u] = depth[v] + 1;
                dfs(u);
            }
    })(root);

    auto la = [&](int v, int h) {
        for (int i = 0; i < LG; i++)
            if (h >> i & 1)
                v = parent[i][v];

        return v;
    };

    auto lca = [&](int v, int u) {
        if (depth[v] < depth[u])
            swap(v, u);

        v = la(v, depth[v] - depth[u]);
        if (v == u)
            return v;

        for (int i = LG - 1; i >= 0; i--)
            if (parent[i][v] != parent[i][u]) {
                v = parent[i][v];
                u = parent[i][u];
            }

        return parent[0][v];
    };

    auto find_max = [&](int v, int u) {
        ll answer = LLONG_MIN;
        int delta_h = depth[v] - depth[u];

        for (int i = 0; i < LG; i++)
            if (delta_h >> i & 1) {
                answer = max(answer, max_cost[i][v]);
                v = parent[i][v];
            }

        return answer;
    };

    while (q--) {
        int v, u;
        cin >> v >> u;
        v--, u--;

        int w = lca(v, u);
        cout << max(find_max(v, w), find_max(u, w)) << '\n';
    }
}