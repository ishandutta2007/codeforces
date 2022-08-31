#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 5e5 + 10;
vector<pair<int, int> > g[maxN];
vector<pair<int, int> > gr[maxN];
int n, m;
int dp[maxN];
int ans[maxN];
int dist[maxN][2];
const int INF = (int) 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dp[i] = INF;
        dist[i][0] = dist[i][1] = INF;
    }
    memset(ans, -1, sizeof ans);
    for (int i = 1; i <= m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        if (u == v) continue;
        g[u].emplace_back(v, t);
        gr[v].emplace_back(u, t);
    }
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, n));
    dp[n] = 0;
    ans[n] = 0;
    dist[n][0] = dist[n][1] = 0;
    while (!q.empty()) {
        auto it = q.top();
        int v = it.second;
        int val = -it.first;
        if (dp[v] != val) continue;
        q.pop();
        for (auto &it : gr[v]) {
            dist[it.first][it.second] = min(dist[it.first][it.second], dp[v] + 1);
            if (dp[it.first] > max(dist[it.first][0], dist[it.first][1])) {
                dp[it.first] = max(dist[it.first][0], dist[it.first][1]);
                if (dist[it.first][0] < dist[it.first][1]) ans[it.first] = 1;
                else ans[it.first] = 0;
                if (dp[it.first] <= n + 1) {
                    q.push(make_pair(-dp[it.first], it.first));
                }
            }
        }
    }
    if (dp[1] > n + 5) {
        cout << -1 << '\n';
        for (int i = 1; i <= n; i++) {
            if (ans[i] != -1) cout << ans[i];
            else {
                if (dist[i][0] >= n + 5) cout << 0;
                else cout << 1;
            }
        }
    } else {
        cout << dp[1] << '\n';
        for (int i = 1; i <= n; i++) {
            if (ans[i] == -1) {
                if (dist[i][0] < dist[i][1]) cout << 1;
                else {
                    cout << 0;
                }
            }
            else {
                cout << ans[i];
            }
        }
    }
    return 0;
}