#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int64_t INF = 1e17;
int n,m;
int64_t dist[nax];
vector <pair <int, int>> g[nax];
vector <pair <int, int>> g_rev[nax];
template <typename T>
using min_heap = priority_queue <T, vector <T>, greater<T>>;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1 ; i <= m ; ++ i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g_rev[v].emplace_back(u, w);
    }

    min_heap <pair <int64_t, int>> pq;
    static bool vis[nax];
    memset(vis, false, sizeof(vis));
    pq.emplace(0, 1);

    fill(dist, dist + 1 + n, INF);
    dist[1] = 0;
    while (!pq.empty()) {

        auto [cst, v] = pq.top();
        pq.pop();
        if (vis[v]) continue;
        vis[v] = true;

        for (auto [to, w] : g[v]) {
            if (dist[to] > dist[v] + w) {
                dist[to] = dist[v] + w;
                pq.emplace(dist[to], to);
            }
        }
    }

    memset(vis, false, sizeof(vis));
    while (!pq.empty()) pq.pop();
    for (int i = 1 ; i <= n ; ++ i) {
        if (dist[i] != INF) pq.emplace(dist[i], i);
    }


    while (!pq.empty()) {
        auto [cst, v] = pq.top();
        pq.pop();
        if (vis[v]) continue;
        vis[v] = true;
        for (auto [to, w] : g_rev[v]) {
            if (dist[to] > dist[v] + w) {
                dist[to] = dist[v] + w;
                pq.emplace(dist[to], to);
            }
        }
    }
    for (int i = 2 ; i <= n ; ++ i) {
        if (dist[i] == INF) dist[i] = -1;
        cout << dist[i] << ' ';
    }
    cout << '\n';
}