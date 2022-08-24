#include <bits/stdc++.h>
using namespace std;
const int maxN = 3 * (int)1e5 + 10;
vector < int > g[maxN];
int sz[maxN];
bool used[maxN];
int par[maxN];
int a, b, n;
void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (used[to]) continue;
        par[to] = v;
        dfs(to);
        sz[v] += sz[to];
    }
    sz[v]++;
}
int main() {
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(a);
    long long ans = 0;
    int st = b;
    while (par[st] != a) {
        st = par[st];
    }
    ans = (1LL * n * (n - 1));
    ans -= (1LL * n - sz[st]) * 1LL * (sz[b]);
    cout << ans;
    return 0;
}