#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxN = 3 * (int)1e5 + 10;
vector < int > order;
vector < int > g[maxN];
int color[maxN];
int dp[maxN][26];
string s;
void dfs(int v) {
    color[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (color[to] == 1) {
            cout << -1;
            exit(0);
        }
        if (color[to] == 0) dfs(to);
    }
    color[v] = 2;
    order.push_back(v);
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) dfs(i);
    }
    reverse(order.begin(), order.end());
    for (int i = 0; i < order.size(); i++) {
        int v = order[i];
        dp[v][s[v - 1] - 'a'] = 1;
    }
    for (int i = 0; i < order.size(); i++) {
        int v = order[i];
        for (int j = 0; j < g[v].size(); j++) {
            int to = g[v][j];
            for (int k = 0; k < 26; k++) {
                dp[to][k] = max(dp[to][k], dp[v][k] + ((s[to - 1] - 'a') == k));
            }
        }
    }
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < 26; k++) {
            mx = max(dp[i][k], mx);
        }
    }
    cout << mx;
    return 0;
}