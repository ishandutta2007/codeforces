#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxN = (int)1e6 + 10;
vector < int > g[maxN];
int deg[maxN];
int rdeg[maxN];
bool used[maxN];
int comp;
bool odd[maxN];
void dfs(int v) {
    if (deg[v] % 2 != 0) odd[comp] = true;
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to]) dfs(to);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        if (x != y) g[x].push_back(y);
        if (x != y) g[y].push_back(x);
        if (x == y) {
            rdeg[x]++;
        }
        if (x != y) {
            rdeg[x]++;
            rdeg[y]++;
            deg[x]++;
            deg[y]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i] && ((rdeg[i] > 0) || (i == 1))) {
            dfs(i);
            comp++;
        }
    }
    int nume = 0;
    for (int i = 0; i < comp; i++) {
        if (!odd[i]) nume++;
    }
    int t = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2 != 0) t++;
    }
    if (comp == 1) cout << (t / 2);
    else cout << (nume + (t / 2));
    return 0;
}