#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int64 oo = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;

struct disjoint_set {
    vector<int> ds;

    disjoint_set(int n) {
        ds = vi(n, -1);
    }

    int root(int a) {
        return ds[a] < 0 ? a : ds[a] = root(ds[a]);
    }

    bool join(int a, int b) {
        a = root(a), b = root(b);
        if (a == b) return false;
        if (a > b) swap(a, b);
        ds[a] = b;
        return true;
    }
};

void myassert(bool target) {
    while (!target);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<vector<pair<int,int64>>> adj(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        int64 c;
        cin >> u >> v >> c;
        --u; --v;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    vector<pair<int64,int>> dist(n, {oo, -1});

    priority_queue<pair<int64,int>> pq;

    for (int i = 0; i < k; ++i) {
        dist[i] = {0, i};
        pq.push({0, i});
    }

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int64 d = -cur.first;
        int u = cur.second;

        if (dist[u].first < d)
            continue;

        for (auto e : adj[u]) {
            int64 c = e.second;
            int v = e.first;

            if (dist[v].first > d + c) {
                dist[v] = {d + c, dist[u].second};
                pq.push({-dist[v].first, v});
            }
        }
    }

    vector<pair<int64, pii>> edges;

    for (int i = 0; i < n; ++i) {
        for (auto e : adj[i]) {
            int u = dist[i].second;
            int v = dist[e.first].second;
            if (u <= v) continue;
            edges.push_back({dist[i].first + dist[e.first].first + e.second, {u, v}});
            auto x = edges.back();
        }
    }

    sort(edges.begin(), edges.end());

    disjoint_set ds(k);

    vector<vector<pair<int,int64>>> tree(k);

    for (auto e : edges) {
        if (ds.join(e.second.first, e.second.second)) {
            tree[e.second.first].push_back({e.second.second, e.first});
            tree[e.second.second].push_back({e.second.first, e.first});
        }
    }

    vector<int> h(k);
    vector<vector<pair<int,int64>>> parent(k);

    function<void(int, int, int64)> dfs = [&](int s, int p, int64 cost) {
        if (p != -1) {
            parent[s].push_back({p, cost});
            int i = 0;

            while (true) {
                int p = parent[s][i].first;
                if (parent[p].size() > i) {
                    auto x = parent[p][i];
                    auto c = parent[s][i].second;
                    parent[s].push_back({x.first, max(x.second, c)});
                } else {
                    break;
                }

                ++i;
            }
        }

        for (auto e : tree[s]) {
            if (e.first == p)
                continue;

            h[e.first] = h[s] + 1;
            dfs(e.first, s, e.second);
        }
    };

    dfs(0, -1, 0);

    auto lca = [&](int a, int b) {
        if (h[a] > h[b]) swap(a, b);

        int64 answer = 0;

        for (int i = 0; h[b] > h[a]; ++i) {
            if ((h[b] - h[a]) >> i & 1) {
                answer = max(answer, parent[b][i].second);
                b = parent[b][i].first;
            }
        }

        if (a == b) return answer;

        int it = parent[a].size() - 1;

        for (int i = it; i >= 0; --i) {
            if (parent[a].size() <= i) continue;
            if (parent[b].size() <= i) continue;

            int pa = parent[a][i].first;
            int pb = parent[b][i].first;

            if (pa != pb) {
                answer = max(answer, parent[a][i].second);
                answer = max(answer, parent[b][i].second);
                a = pa;
                b = pb;
            }
        }

        answer = max(answer, parent[a][0].second);
        answer = max(answer, parent[b][0].second);

        return answer;
    };

    while (q-->0) {
        int u, v; cin >> u >> v;
        u--; v--;
        cout << lca(u, v) << endl;
    }

    return 0;
}