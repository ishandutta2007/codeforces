#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxP = 51;
const int maxN = 1e5 + 10;
int dist[(maxN + 1) * (maxP + 1)];
int m;
int n;
vector<pair<int,int>> g[maxN];
const int INF = 2e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < maxP; j++) {
            dist[i * maxP + j] = INF;
        }
    }
    int st = 1 * maxP + 0;
    dist[st] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(-dist[st], st));
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int id =  it.second;
        int d = -it.first;
        if (dist[id] != d) continue;
        int w = id % maxP;
        int v = id / maxP;
        for (auto& it : g[v]) {
            if (w == 0) {
                int new_v = it.first * maxP + it.second;
                if (dist[new_v] > d) {
                    dist[new_v] = d;
                    pq.push(make_pair(-dist[new_v], new_v));
                }
            }
            else {
                int new_d = d + (it.second + w) * (it.second + w);
                int new_v = it.first * maxP + 0;
                if (dist[new_v] > new_d) {
                    dist[new_v] = new_d;
                    pq.push(make_pair(-dist[new_v], new_v));
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i * maxP] == INF) cout << -1 << " ";
        else cout << dist[i * maxP] << " ";
    }
    return 0;
}