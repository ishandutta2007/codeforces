#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        vector<vector<int>> adj(N);
        for (int i = 0; i < M; ++i) {
            int v, u; cin >> v >> u;
            adj[--v].emplace_back(--u);
            adj[u].emplace_back(v);
        }
        vector<int> dist(N, -1);
        dist[0] = 0;
        vector<int> bfs; bfs.emplace_back(0);
        for (int z = 0; z < int(bfs.size()); ++z) {
            int v = bfs[z];
            for (int u : adj[v]) if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                bfs.emplace_back(u);
            }
        }
        if (bfs.size() < N) {
            cout << "NO\n";
            continue;
        }
        vector<int> loc(N); for (int i = 0; i < N; ++i) loc[bfs[i]] = i;
        int tot = 0;
        vector<bool> taken(N);
        for (int v : bfs) {
            taken[v] = true;
            for (int u : adj[v]) if (loc[u] < loc[v] && taken[u]) taken[v] = false;
        }
        cout << "YES\n";
        cout << count(taken.begin(), taken.end(), true) << '\n';
        for (int i = 0; i < N; ++i) if (taken[i]) cout << i+1 << ' '; cout << '\n';
    }
}