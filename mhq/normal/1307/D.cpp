#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
vector < int > g[maxN];
int n, m, k;
bool ok[maxN];
int dist[2][maxN];
void bfs(int v, int ind) {
    for (int i = 1; i <= n; i++) {
        dist[ind][i] = -1;
    }
    queue < int > q;
    dist[ind][v] = 0;
    q.push(v);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (dist[ind][to] == -1) {
                dist[ind][to] = dist[ind][v] + 1;
                q.push(to);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        ok[x] = true;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(1, 0);
    bfs(n, 1);
    int ans = -1e9;
    vector < pair < int, int > > all;
    for (int i = 1; i <= n; i++) {
        if (ok[i]) {
            all.emplace_back(dist[1][i] - dist[0][i], i);
        }
    }
    sort(all.begin(), all.end());
    int mx = -1e9;
    for (int i = 0; i < all.size(); i++) {
        ans = max(ans, min(dist[0][n], dist[0][all[i].second] + 1 + mx));
        mx = max(mx, dist[1][all[i].second]);
    }
    cout << ans;
    return 0;
}