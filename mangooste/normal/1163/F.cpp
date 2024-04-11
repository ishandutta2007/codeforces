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

constexpr ll INF = 1e18;

struct segtree {
    int n;
    vector<ll> tree;

    segtree(int n) : n(n), tree(4 * n, INF) {}

    void update(int l, int r, ll value) {
        update(1, 0, n, l, r, value);
    }

    void update(int v, int vl, int vr, int l, int r, ll value) {
        if (r <= vl || vr <= l)
            return;

        if (l <= vl && vr <= r) {
            tree[v] = min(tree[v], value);
            return;
        }

        int vm = (vl + vr) >> 1;
        update(v << 1, vl, vm, l, r, value);
        update(v << 1 | 1, vm, vr, l, r, value);
    }

    ll get_best(int pos) {
        return get_best(1, 0, n, pos, INF);
    }

    ll get_best(int v, int vl, int vr, int pos, ll current) {
        current = min(current, tree[v]);
        if (vr - vl == 1)
            return current;

        int vm = (vl + vr) >> 1;
        return pos < vm ? get_best(v << 1, vl, vm, pos, current) : get_best(v << 1 | 1, vm, vr, pos, current);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n);
    vector<array<int, 3>> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        edges[i][0]--, edges[i][1]--;

        g[edges[i][0]].push_back(i);
        g[edges[i][1]].push_back(i);
    }

    auto another = [&](int id, int v) {
        return edges[id][0] ^ edges[id][1] ^ v;
    };

    using cmp_pq = priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>>;
    cmp_pq pq;

    auto dijkstra = [&](int start) {
        vector<ll> dist(n, INF);
        vector<int> parent(n, -1);

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            const auto [d, v] = pq.top();
            pq.pop();
            if (d != dist[v])
                continue;

            for (const auto id : g[v]) {
                const int u = another(id, v);
                const int w = edges[id][2];
                if (dist[u] > d + w) {
                    dist[u] = d + w;
                    parent[u] = id;
                    pq.push({dist[u], u});
                }
            }
        }

        return pair<vector<ll>, vector<int>>{dist, parent};
    };

    auto [dist_1, parent_1] = dijkstra(0);
    vector<int> way;
    for (int v = n - 1; parent_1[v] != -1; v = another(parent_1[v], v))
        way.push_back(parent_1[v]);

    reverse(all(way));
    dbg(way);

    vector<int> where(m, -1);
    for (int i = 0; i < len(way); i++)
        where[way[i]] = i;

    auto [dist_n, parent_n] = dijkstra(n - 1);

    auto get_id = [&](const vector<ll> &dist, const vector<int> &parent) {
        vector<int> order(n);
        iota(all(order), 0);
        sort(all(order), [&](int v, int u) {
            return dist[v] < dist[u];
        });

        vector<int> length(n);
        vector<int> id(n);
        for (auto v : order) {
            id[v] = 0;
            if (parent[v] == -1)
                continue;

            int u = another(parent[v], v);;
            length[v] = length[u] + 1;
            if (where[parent[v]] == -1 || id[u] != length[u])
                id[v] = id[u];
            else
                id[v] = length[v];
        }

        return id;
    };

    auto id1 = get_id(dist_1, parent_1);
    auto id2 = get_id(dist_n, parent_n);
    for (auto &x : id2)
        x = len(way) - x;

    dbg(id1);
    dbg(id2);

    segtree tree(len(way));
    for (int i = 0; i < m; i++)
        if (where[i] == -1)
            for (int rot = 0; rot < 2; rot++, swap(edges[i][0], edges[i][1])) {
                auto &[v, u, w] = edges[i];
                tree.update(id1[v], id2[u], dist_1[v] + dist_n[u] + w);
            }

    while (q--) {
        int id, new_w;
        cin >> id >> new_w;
        id--;

        ll answer = min(dist_1[edges[id][0]] + new_w + dist_n[edges[id][1]], dist_1[edges[id][1]] + new_w + dist_n[edges[id][0]]);
        if (where[id] == -1)
            cout << min(dist_1[n - 1], answer) << '\n';
        else
            cout << min(answer, tree.get_best(where[id])) << '\n';
    }
}