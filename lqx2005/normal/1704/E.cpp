#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define ull unsigned long long
#define db double
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int P = 998244353;
vector<int> g[1010];
int a[1010], b[1010], dp[1010], vis[1010];
int dfs(int u) {
    if(vis[u]) return dp[u];
    if(g[u].empty()) {
        dp[u] = 1;
        vis[u] = 1;
        return 1;
    }
    vis[u] = 1;
    for(auto v : g[u]) (dp[u] += dfs(v)) %= P;
    return dp[u];
}
void solve() {
    int n, m;
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i], g[i].clear(), vis[i] = dp[i] = 0;
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
    }
    int ans = 0;
    FOR(u, 1, n) (ans += (ll)a[u] * dfs(u) % P) %= P;
    int t;
    FOR(u, 1, n) if(g[u].empty()) t = u;
    FOR(r, 1, n) {
        int fg = 0;
        FOR(u, 1, n) if(a[u]) fg = 1;
        if(!fg) break;
        if(!a[t]) (ans += 1) %= P;
        FOR(u, 1, n) {
            b[u] = a[u];
            if(b[u] > 0) b[u]--;
        }
        FOR(u, 1, n) if(a[u] > 0) for(auto v : g[u]) b[v]++;
        FOR(u, 1, n) a[u] = min(b[u], n * 2);
    }
    cout << ans << "\n";
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}