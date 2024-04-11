#include <bits/stdc++.h>

using namespace std;
const int maxN = 4 * (int)1e5 + 10;
int n;
vector < int > g[maxN];
bool used[maxN];
int sz[maxN];
int par[maxN];
void dfs(int v, int p) {
    sz[v] = 1;
    bool ok = true;
    for (int to : g[v]) {
        if (to == p) continue;
        par[to] = v;
        dfs(to, v);
        sz[v] += sz[to];
    }
}
int calc_centroid() {
    dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        bool ok = true;
        if (n - sz[i] > n / 2) ok = false;
        for (int to : g[i]) {
            if (to == par[i]) continue;
            if (sz[to] > n / 2) {
                ok = false;
                break;
            }
        }
        if (ok) return i;
    }
}
bool can[maxN];
vector < int > subtrees[maxN];
multiset < int > all;
void second_dfs(int v, int p, int cur) {
    all.insert(sz[v]);
    subtrees[cur].push_back(v);
    for (int to : g[v]) {
        if (to == p) continue;
        second_dfs(to, v, cur);
    }
}
void last_dfs(int v, int p) {
    if (n - sz[v] <= (n / 2)) {
        can[v] = true;
    }
    for (int to : g[v]) {
        if (to == p) continue;
        last_dfs(to, v);
    }
    auto it = all.lower_bound((n + 1) / 2 - sz[v]);
    if (it != all.end() && (*it <= n / 2)) {
        can[v] = true;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cent = calc_centroid();
    dfs(cent, -1);
    can[cent] = true;
    for (int to : g[cent]) {
        second_dfs(to, cent, to);
    }
    for (int to : g[cent]) {
        for (int v : subtrees[to]) {
            all.erase(all.find(sz[v]));
        }
        all.insert(n - sz[to]);
        last_dfs(to, cent);
        for (int v : subtrees[to]) {
            all.insert(sz[v]);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << can[i] << " ";
    }
    return 0;
}