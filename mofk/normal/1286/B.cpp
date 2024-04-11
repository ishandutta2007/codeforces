#include <bits/stdc++.h>

using namespace std;

int n, r;
vector <int> child[2005];
vector <int> can[2005];
int dad[2005], c[2005], sz[2005];
int ans[2005];

void dfs(int u) {
    sz[u] = 1;
    for (auto v: child[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
}
void dfs2(int u) {
    if (c[u] >= can[u].size()) {
        cout << "NO" << endl;
        exit(0);
    }
    ans[u] = can[u][c[u]];
    int pt = 0;
    for (auto v: child[u]) {
        while (can[v].size() < sz[v]) {
            if (pt != c[u]) can[v].push_back(can[u][pt]);
            ++pt;
        }
        dfs2(v);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> dad[i] >> c[i], child[dad[i]].push_back(i);
    for (int i = 1; i <= n; ++i) if (dad[i] == 0) r = i;
    dfs(r);
    for (int i = 1; i <= n; ++i) can[r].push_back(i);
    dfs2(r);
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}