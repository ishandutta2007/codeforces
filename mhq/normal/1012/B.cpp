#include <bits/stdc++.h>
using namespace std;
const int maxN = 2 * (int)1e5 + 10;
vector < int > g[2 * maxN];
int n, m, q;
bool used[2 * maxN];
void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (used[to]) continue;
        dfs(to);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y + n);
        g[y + n].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= n + m; i++) {
        if (!used[i]) {
            ans++;
            dfs(i);
        }
    }
    ans--;
    cout << ans;
    return 0;
}