
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, int>>> adj(n + 1);
    // (counted an edge 0 times, counted an edge 2 times)
    rep(i, 0, m) {
        int u, v; ll w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    minpq<pair<ll, int>> Q;
    vector<bool> vis(4 * n);
    vector<ll> dist(4 * n);
    Q.push({0, 0});
    while(!Q.empty()) {
        ll d; int xx;
        tie(d, xx) = Q.top(); Q.pop();
        if(vis[xx]) continue;
        vis[xx] = true;
        dist[xx] = d;
        int mask = xx / n, x = xx % n;
        for(auto &e : adj[x]) {
            ll w; int y;
            tie(w, y) = e;
            // count 0 times
            if(~mask >> 1 & 1) Q.push({d, (mask | 2) * n + y});
            // count 1 time
            Q.push({d + w, mask * n + y});
            // count 2 times
            Q.push({d + 2 * w, (mask | 1) * n + y});
        }
    }
    rep(i, 1, n) {
        cout << min({dist[i], dist[1 * n + i], dist[3 * n + i]}) << ' ';
    }
    cout << '\n';
}