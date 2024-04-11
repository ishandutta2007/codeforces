
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
    int n, m, q;
    cin >> n >> m;
    vector<vector<ll>> dist(2 * n, vector<ll>(2 * n, LLONG_MAX));
    vector<tuple<int, int, ll>> e;
    rep(i, 0, m) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        e.push_back({u, v, w});
        dist[u][v] = dist[v][u] = dist[u + n][v + n] = dist[v + n][u + n] = min(dist[u][v], w);
    }
    rep(i, 0, 2 * n) dist[i][i] = 0;
    cin >> q;
    rep(i, 0, q) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        dist[u][v + n] = dist[v][u + n] = min(dist[u][v + n], -w);
    }
    rep(k, 0, 2 * n) {
        rep(i, 0, 2 * n) {
            rep(j, 0, 2 * n) {
                if(dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    int cnt = 0;
    for(auto &ed : e) {
        int u, v; ll w;
        tie(u, v, w) = ed;
        if(dist[u][v + n] <= -w) cnt++;
    }
    cout << cnt << '\n';
}