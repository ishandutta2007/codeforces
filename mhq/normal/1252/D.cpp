#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
vector < int > g[maxN];
int sz[maxN];
int h[maxN];
void dfs(int v, int p) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to == p) continue;
        h[to] = h[v] + 1;
        dfs(to, v);
        sz[v] += sz[to];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1, -1);
    vector < int > all;
    for (int i = 1; i <= n; i++) {
        all.emplace_back(sz[i] - h[i] - 1);
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    ll ans = 0;
    k = n - k;
    for (int i = 0; i < k; i++) ans += all[i];
    cout << ans;
    return 0;
}