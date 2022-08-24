#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 5;
int n, m;
vector < int > g[maxN];
bool used[maxN];
long long ans;
long long c[maxN];
long long dfs(int v) {
    used[v] = true;
    long long mi = c[v];
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to]) {
            mi = min(mi, dfs(to));
        }
    }
    return mi;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= m; i++) {
        int x; int y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) ans += 1LL * dfs(i);
    }
    cout << ans;
    return 0;
}