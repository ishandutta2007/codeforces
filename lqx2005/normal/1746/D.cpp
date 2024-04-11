#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define vi vector<int>
using namespace std;
const int N = 2e5 + 10;
int n, k, s[N];
map<int, ll> dp[N];
vector<int> g[N];
ll dfs(int u, int k) {
    if(dp[u].count(k)) return dp[u][k];
    ll &res = dp[u][k];
    res = (ll)s[u] * k;
    if(g[u].empty()) return res;
    if(k % sz(g[u]) == 0) {
        for(auto v : g[u]) res += dfs(v, k / sz(g[u]));
        return res;
    }
    int c = k / sz(g[u]), r = k % sz(g[u]);
    vector<ll> son;
    for(auto v : g[u]) {
        ll t = dfs(v, c);
        res += t;
        son.emplace_back(dfs(v, c + 1) - t);
    }
    sort(son.begin(), son.end(), greater<ll>());
    FOR(i, 0, r - 1) res += son[i];
    return res;
}
void rmain() {
    cin >> n >> k;
    FOR(i, 1, n) dp[i].clear(), g[i].clear();
    FOR(i, 2, n) {
        int fa;
        cin >> fa;
        g[fa].emplace_back(i);
    }
    FOR(i, 1, n) cin >> s[i];
    cout << dfs(1, k) << "\n";
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    for(cin >> T; T--; ) rmain();
}