#include<bits/stdc++.h>
using namespace std;
const int nax = 300000 + 10;
const int INF = 1e9;
int n, m;
array <int, 3> e[nax];
vector <pair <int, int>> g[nax];
bool used[nax];
int dist[512][512];

void solve() {
    cin >> n >> m;
    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 1 ; j <= n ; ++ j) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    for (int i = 1 ; i <= m ; ++ i) {
        auto &[u, v, w] = e[i];
        cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = 1;
    }

    for (int k = 1 ; k <= n ; ++ k) {
        for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= n ; ++ j) {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }


    int64_t ans = 1e15;

    for (int i = 1 ; i <= m ; ++ i) {
        auto [u, v, w] = e[i];
        for (int _ = 0 ; _ < 2 ; ++ _) {
            ans = min(ans, 1ll * w * (dist[1][u] + dist[v][n] + 1));
            for (int x = 1 ; x <= n ; ++ x)
                ans = min(ans, 1ll * w * (dist[u][x] + 2 + dist[1][x] + dist[x][n]));
            swap(u, v);
        }
    }
    cout << ans << '\n';


}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}