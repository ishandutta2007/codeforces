#include <bits/stdc++.h>
using namespace std;
const int maxN = 2 * (int)1e5 + 4;
long long dp[maxN][2];
int n;
int a[maxN];
vector < int > g[maxN];
bool used[maxN];
int par[maxN];
const long long inf = -1000000000000000;
vector < int > order;
long long sum[maxN];
void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to]) {
            par[to] = v;
            dfs(to);
        }
    }
    order.push_back(v);
}
long long solve(int v, int t) {
    if (dp[v][t] != inf) return dp[v][t];
    if (t == 0) {
        long long ans = sum[v];
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (to != par[v]) {
                ans = max(ans, solve(to, 0));
            }
        }
        dp[v][t] = ans;
        return ans;
    }
    long long ans = inf;
    long long max1 = inf;
    long long max2 = inf;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != par[v]) {
            ans = max(ans, solve(to, 1));
            if (solve(to, 0) > max1) {
                max2 = max1;
                max1 = solve(to, 0);
            }
            else if (solve(to, 0) > max2) {
                max2 = solve(to, 0);
            }
        }
    }
    if (max1 != inf && max2 != inf) {
        ans = max(ans, max1 + max2);
    }
    dp[v][t] = ans;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i][j] = inf;
        }
    }
    int x, y;
    for (int i = 1; i <= n - 1; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    par[1] = -1;
    for (int i = 0; i < order.size(); i++) {
        int v = order[i];
        sum[v] += a[v];
        if (par[v] != -1) {
            sum[par[v]] += sum[v];
        }
    }
    if (solve(1, 1) == inf) {
        cout << "Impossible";
    }
    else {
        cout << solve(1, 1);
    }
    return 0;
}