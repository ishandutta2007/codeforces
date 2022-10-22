#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pr pair<int, int>
using namespace std;
const int N = 500 + 10, M = N * N;
ll f[N][N], g[N][N];
void rmain() {
    int n, m;
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, n) f[i][j] = g[i][j] = 1e18;
    FOR(i, 1, n) g[i][i] = 0;
    FOR(i, 1, m) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        f[u][v] = f[v][u] = min(f[u][v], w);
        g[u][v] = g[v][u] = min(g[u][v], 1ll);
    }
    FOR(i, 1, n) FOR(j, 1, n) FOR(k, 1, n) g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
    ll ans = 1e18;
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if(f[i][j] >= 1e18) continue;
            ans = min(ans, f[i][j] * (1 + g[1][i] + g[j][n]));
        }
    }
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if(f[i][j] >= 1e18) continue;
            FOR(k, 1, n) {
                ans = min(ans, f[i][j] * (2 + g[i][k] + g[1][k] + g[k][n]));
            }
        }
    }
    cout << ans << "\n";
    return;
}
int main() {
    // x * x x * x + x * 2
    // 2 * x + 1
    int t;
    for(cin >> t; t--; ) rmain();
    return 0;
}