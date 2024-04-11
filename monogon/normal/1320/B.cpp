
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, m, u, v, k, p[N];
vector<int> adj[N];
int vis[N], dist[N];

void bfs(int x) {
    queue<int> q;
    q.push(x);
    dist[x] = 0;
    vis[x] = 1;
    while(!q.empty()) {
        x = q.front(); q.pop();
        for(int y : adj[x]) {
            if(vis[y] == 0) {
                dist[y] = dist[x] + 1;
                q.push(y);
                vis[y] = 1;
            }else if(dist[y] == dist[x] + 1) {
                vis[y]++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[v].push_back(u);
    }
    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> p[i];
    }
    bfs(p[k - 1]);
    int a = 0, b = 0;
    for(int i = 0; i < k - 1; i++) {
        b += (vis[p[i]] > 1 || dist[p[i]] <= dist[p[i + 1]]);
        a += (dist[p[i]] <= dist[p[i + 1]]);
    }
    cout << a << " " << b << endl;
}