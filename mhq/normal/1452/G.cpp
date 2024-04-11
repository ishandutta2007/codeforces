#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2e5 + 10;
vector<int> g[maxN];
int k;
int dist[maxN];
bool used[maxN];
int sz[maxN];
int sb[maxN];
void dfscen(int v, int p, vector<int>& all) {
    all.emplace_back(v);
    sz[v] = 1;
    sb[v] = 0;
    for (int to : g[v]) {
        if (used[to] || to == p) continue;
        dfscen(to, v, all);
        sb[v] = max(sb[v], sz[to]);
        sz[v] += sz[to];
    }
}
int ans[maxN];
int h[maxN];
int LIM;
int f[maxN];
void dfs(int v, int p) {
    if (dist[v] > 0) {
        int dist_to_cen = dist[v] - 1 - h[v];
        if (dist_to_cen >= 0) {
            dist_to_cen = min(dist_to_cen, LIM);
            f[dist_to_cen] = max(f[dist_to_cen], dist[v]);
        }
    }
    for (int to : g[v]) {
        if (used[to] || to == p) continue;
        h[to] = h[v] + 1;
        dfs(to, v);
    }
}
void go(int v) {
    vector<int> all;
    dfscen(v, -1, all);
    int cen = -1;
    for (int c : all) {
        if (2 * sb[c] <= (int)all.size() && 2 * ((int)all.size() - sz[c]) <= (int)all.size()) {
            cen = c;
            break;
        }
    }
    assert(cen != -1);
    h[cen] = 0;
    LIM = all.size();
    for (int i = 0; i <= LIM; i++) {
        f[i] = -1e9;
    }
    if (dist[cen] > 0) {
        f[min(LIM, dist[cen] - 1)] = dist[cen];
    }
    for (int to : g[cen]) {
        if (used[to]) continue;
        h[to] = 1;
        dfs(to, cen);
    }
    for (int i = LIM; i > 0; i--) {
        f[i - 1] = max(f[i - 1], f[i]);
    }
    for (int c : all) {
        ans[c] = max(ans[c], f[h[c]]);
    }
    used[cen] = true;
    for (int to : g[cen]) {
        if (!used[to]) go(to);
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
    cin >> k;
    memset(dist, -1, sizeof dist);
    queue<int> q;
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        assert(dist[x] == -1);
        dist[x] = 0;
        q.push(x);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
    go(1);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == 0) cout << 0 << " ";
        else cout << ans[i] << " ";
    }
    return 0;
}