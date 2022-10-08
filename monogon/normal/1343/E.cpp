
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int t, n, m, a, b, c, u, v;
vector<int> adj[N];
bool vis[N];
ll p[N];

vector<int> bfs(int x) {
    fill(vis + 1, vis + n + 1, false);
    queue<int> q;
    q.push(x);
    vector<int> dist(n + 1, 0);
    vis[x] = true;
    while(!q.empty()) {
        int y = q.front(); q.pop();
        for(int z : adj[y]) {
            if(!vis[z]) {
                q.push(z);
                vis[z] = true;
                dist[z] = dist[y] + 1;
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m >> a >> b >> c;
        for(int i = 1; i <= n; i++) adj[i].clear();
        for(int i = 1; i <= m; i++) {
            cin >> p[i];
        }
        sort(p + 1, p + m + 1);
        for(int i = 1; i <= m; i++) {
            p[i] += p[i - 1];
        }
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        vector<int> dista = bfs(a);
        vector<int> distb = bfs(b);
        vector<int> distc = bfs(c);
        ll ans = LLONG_MAX;
        for(int d = 1; d <= n; d++) {
            if(distb[d] + dista[d] + distc[d] <= m) {
                ans = min(ans, p[distb[d]] + p[distb[d] + dista[d] + distc[d]]);
            }
        }
        cout << ans << '\n';
    }
}