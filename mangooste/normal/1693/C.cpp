#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    while (m--) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        deg[v]++;
        g[u].push_back(v);
    }

    vector<int> dist(n, 1e9), have(n);
    dist[n - 1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, n - 1});

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (d != dist[v]) continue;
        
        for (auto u : g[v]) {
            have[u]++;
            int new_d = d + deg[u] - have[u] + 1;
            if (new_d < dist[u]) {
                dist[u] = new_d;
                pq.push({new_d, u});
            }
        }
    }
    cout << dist[0] << '\n';
}