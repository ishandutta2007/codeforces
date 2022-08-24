#include <bits/stdc++.h>
using namespace std;
int n, k, m;
vector < pair < int, int > > g[85];
int dp[85][85][85];
bool used[85][85][85];
const int inf = (int)1e9 + 5;
int solve(int a, int lim, int step) {
    if (dp[a][lim][step] != -1) return dp[a][lim][step];
    if (step == 0) return dp[a][lim][step] = 0;
    int ans = inf;
    if (lim > a) {
        for (int i = 0; i < g[a].size(); i++) {
            int to = g[a][i].first;
            int we = g[a][i].second;
            if (to > a && to < lim) {
                int x = solve(to, lim, step - 1);
                ans = min(ans, x + we);
                int y = solve(to, a, step - 1);
                ans = min(ans, y + we);
            }
        }
    }
    else {
        for (int i = 0; i < g[a].size(); i++) {
            int to = g[a][i].first;
            int we = g[a][i].second;
            if (to < a && to > lim) {
                int x = solve(to, lim, step - 1);
                ans = min(ans, x + we);
                int y = solve(to, a, step - 1);
                ans = min(ans, y + we);
            }
        }
    }
    return dp[a][lim][step] = ans;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> k >> m;
    memset(dp, -1, sizeof dp);
    int a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
    }
    int mi = inf;
    for (int i = 1; i <= n; i++) {
        mi = min(solve(i, n + 1, k - 1), mi);
        mi = min(solve(i, 0, k - 1), mi);
    }
    if (mi == inf) {
        cout << -1;
    }
    else {
        cout << mi;
    }
    return 0;
}