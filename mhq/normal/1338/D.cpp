#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 1e5 + 10;
vector < int > g[maxN];
int dp[maxN][2];
void dfs(int v, int p) {
    dp[v][1] = 1;
    dp[v][0] = 0;
    int deg = 0;
    for (int to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
        deg++;
    }
    for (int to : g[v]) {
        if (to == p) continue;
        dp[v][0] = max(dp[v][0], max(dp[to][1], dp[to][0]) + deg - 1);
        dp[v][1] = max(dp[v][1], dp[to][0] + 1);
    }
}
int ans = 0;
void dfs2(int v, int p) {
    ans = max(ans, max(dp[v][1], dp[v][0]));
    int deg = 0;
    for (int to : g[v]) {
        deg++;
        if (to == p) continue;
        dfs2(to, v);
    }
    int c[2] = {0, 0};
    for (int to : g[v]) {
        if (to == p) continue;
        //take
        ans = max(ans, c[0] + dp[to][0] + 1);
        //not
        ans = max(ans, max(c[0], c[1]) + deg - 2 + max(dp[to][0], dp[to][1]));
        c[0] = max(c[0], dp[to][0]);
        c[1] = max(c[1], dp[to][1]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1, -1);
    dfs2(1, -1);
    cout << ans;
    return 0;
}