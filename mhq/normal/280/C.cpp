#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const int maxN = (int)1e5 + 10;
vector < int > g[maxN];
ld ans;
int h[maxN];
void dfs(int v, int p) {
    ans += (1.0 / h[v]);
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to == p) continue;
        h[to] = h[v] + 1;
        dfs(to, v);
    }
}
int n;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    h[1] = 1;
    dfs(1, -1);
    cout << fixed << setprecision(10) << ans;
    return 0;
}