#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 3 * (int)1e5 + 10;
vector < int > g[maxN];
vector < int > tree[maxN];
int h[maxN];
bool used[maxN];
int up[maxN];
bool br[maxN];
void dfs(int v, int p = -1) {
    used[v] = true;
    up[v] = h[v];
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to == p) continue;
        if (used[to]) {
            up[v] = min(up[v], h[to]);
        }
        else {
            h[to] = h[v] + 1;
            tree[v].push_back(to);
            dfs(to, v);
            up[v] = min(up[v], up[to]);
            if (up[to] > h[v]) {
                br[to] = true;
            }
        }
    }
}
int dp[maxN];
int p[maxN];
int ans = 0;
void solve(int v, int p = -1) {
    int mx1 = 0;
    int mx2 = 0;
    used[v] = true;
    for (int i = 0; i < tree[v].size(); i++) {
        int to = tree[v][i];
        if (to == p) continue;
        solve(to, v);
        int val1 = dp[to] + (br[to] == true);
        if (val1 >= mx1) {
            mx2 = mx1;
            mx1 = val1;
        }
        else if (val1 >= mx2) {
            mx2 = val1;
        }
        dp[v] = max(dp[v], val1);
    }
    ans = max(ans, mx1 + mx2);
}
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        up[i] = n + 1000;
    }
    dfs(1, -1);
    memset(used, 0, sizeof used);
    solve(1, -1);
    cout << ans;
    return 0;
}