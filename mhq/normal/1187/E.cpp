#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
vector < int > g[maxN];
ll dp[maxN];
int n;
int sz[maxN];
void dfs(int v, int p) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
        sz[v] += sz[to];
        dp[v] += dp[to];
    }
    dp[v] += sz[v];
}

ll up[maxN];

void UpDfs(int v, int p) {
    for (int to : g[v]) {
        if (to == p) continue;
        up[to] = up[v] + (dp[v] - sz[v] - dp[to]) + (n - sz[to]);
        UpDfs(to, v);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  //  freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    UpDfs(1, -1);
    ll best = 0;
    for (int i = 1; i <= n; i++) {
        best = max(best, dp[i] + up[i] - sz[i] + n);
    }
    cout << best;
    return 0;
}