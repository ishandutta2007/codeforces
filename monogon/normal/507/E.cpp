
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// broken road costs m+2, working road costs m+1

const int N = 1e5 + 5;
int n, m, u[N], v[N], z[N], par[N];
ll dist[N];
vector<pair<int, ll>> adj[N];
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int tot = 0;
    for(int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> z[i];
        adj[u[i]].emplace_back(v[i], m + 1 + !z[i]);
        adj[v[i]].emplace_back(u[i], m + 1 + !z[i]);
        tot += z[i];
    }
    fill(dist, dist + N, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    Q.emplace(0, 1);
    while(!Q.empty()) {
        auto [d, x] = Q.top(); Q.pop();
        if(vis[x]) continue;
        dist[x] = d;
        vis[x] = true;
        for(auto &p : adj[x]) {
            auto [y, w] = p;
            if(!vis[y] && d + w < dist[y]) {
                par[y] = x;
                dist[y] = d + w;
                Q.emplace(dist[y], y);
            }
        }
    }
    int len = dist[n] / (m + 1);
    int broken = dist[n] % (m + 1);
    cout << (tot - (len - broken) + broken) << '\n';
    int x = n;
    while(x != 1) {
        vis[x] = false;
        x = par[x];
    }
    vis[1] = false;
    for(int i = 0; i < m; i++) {
        if(!vis[u[i]] && !vis[v[i]]) {
            if(z[i] == 0) {
                cout << u[i] << " " << v[i] << " " << !z[i] << '\n';
            }
        }else if(z[i] == 1) {
            cout << u[i] << " " << v[i] << " " << !z[i] << '\n';
        }
    }
}