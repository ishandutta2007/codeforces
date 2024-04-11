#include<bits/stdc++.h>
using namespace std;
/**
    view problem as shortest path problem
    Let's say we are at some nodes X
    The traveler always choose the worst possible route
    
    look at reverse graph
    
    d_v = min(d_from + not_already_visited neighbour)
    so we can greedily run dijsktra from reverse graph
*/
const int nax = 3e5 + 10;
const int INF = 1e9;
template <typename T>
using min_heap = priority_queue<T, vector <T>, greater<T>>;
int n, m;
int in_deg[nax];
vector <int> g[nax];
int dist[nax];
bool vis[nax];


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; ++ i) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        in_deg[u] += 1;
    }
    fill(dist + 1, dist + n, INF);
    min_heap <pair <int, int>> pq;
    pq.emplace(dist[n], n);
    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        if (vis[node]) continue;
        vis[node] = true;

        for (int from : g[node]) {           	
            if (!vis[from] && d + in_deg[from] < dist[from]) {
                dist[from] = d + in_deg[from];
                pq.emplace(dist[from], from);
            }            	
          	in_deg[from] -= 1;

        }      	
    }
    cout << dist[1] << '\n';
}