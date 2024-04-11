#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    const int INF = 1e9;
    const int MOD = 998244353;
    int N, M; cin >> N >> M;
    vector<array<vector<int>, 2>> adj(N);
    for (int i = 0; i < M; ++i) {
        int v, u; cin >> v >> u; --v, --u;
        adj[v][0].emplace_back(u);
        adj[u][1].emplace_back(v);
    }
    {
        vector<array<array<int, 2>, 20>> dist(N);
        for (int v = 0; v < N; ++v) {
            for (int z = 0; z < 20; ++z) {
                dist[v][z][0] = dist[v][z][1] = INF;
            }
        }
        using pq_type = tuple<int, int, int, int>;
        priority_queue<pq_type, vector<pq_type>, greater<pq_type>> pq;
        dist[0][0][0] = 0;
        pq.emplace(0, 0, 0, 0);
        auto push = [&](int v, int z, int t, int d) {
            if (dist[v][z][t] > d) {
                dist[v][z][t] = d;
                pq.emplace(d, v, z, t);
            }
        };
        while (!pq.empty()) {
            int d, v, z, t; tie(d, v, z, t) = pq.top(); pq.pop();
            if (d != dist[v][z][t]) continue;
            if (z+1<20) push(v, z+1, t^1, d+(1<<z));
            for (int u : adj[v][t]) push(u, z, t, d+1);
        }
        int ans = INF;
        for (int z = 0; z < 20; ++z) {
            ans = min(ans, dist[N-1][z][0]);
            ans = min(ans, dist[N-1][z][1]);
        }
        if (ans != INF) {
            cout << ans << '\n';
            return 0;
        }
    }
    {
        vector<array<pair<int, int>, 2>> dist(N);
        for (int v = 0; v < N; ++v) {
            dist[v][0] = dist[v][1] = make_pair(INF, INF);
        }
        using pq_type = tuple<pair<int, int>, int, int>;
        priority_queue<pq_type, vector<pq_type>, greater<pq_type>> pq;
        auto push = [&](int v, int t, pair<int, int> d) {
            if (dist[v][t] > d) {
                dist[v][t] = d;
                pq.emplace(d, v, t);
            }
        };
        push(0, 0, {0, 0});
        while (!pq.empty()) {
            int v, t; pair<int, int> d; tie(d, v, t) = pq.top(); pq.pop();
            if (d != dist[v][t]) continue;
            push(v, t^1, {d.first+1, d.second});
            for (int u : adj[v][t]) push(u, t, {d.first, d.second+1});
        }
        pair<int, int> ans = min(dist[N-1][0], dist[N-1][1]);
        int tot = 0;
        for (int z = 0; z < ans.first; ++z) {
            tot = (tot + tot + 1) % MOD;
        }
        tot += ans.second;
        if (tot >= MOD) tot -= MOD;
        cout << tot << '\n';
    }
}