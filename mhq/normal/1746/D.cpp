#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const int maxN =  2e5 + 10;
ll k;
int p[maxN];
ll dp[maxN][2];
vector<int> g[maxN];
ll f[maxN];
ll s[maxN];
void dfs(int v, int p) {
    for (int to : g[v]) {
        f[to] = f[v] / g[v].size();
        dfs(to, v);
    }
    for (int z = 0; z < 2; z++) {
        ll val = f[v] + z;
        ll his_s = 0;
        vector<ll> extra;
        for (int to : g[v]) {
            his_s += f[to];
            extra.emplace_back(dp[to][1] - dp[to][0]);
            dp[v][z] += dp[to][0];
        }
        sort(extra.begin(), extra.end());
        assert(his_s <= val);
        while (his_s < val && !extra.empty()) {
            dp[v][z] += extra.back();
            his_s++;
            extra.pop_back();
        }
    }
    dp[v][0] += s[v] * f[v];
    dp[v][1] += s[v] * (f[v] + 1);
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        dp[i][0] = dp[i][1] = 0;
    }
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        g[p[i]].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) cin >> s[i];
    f[1] = k;
    dfs(1, -1);
    cout << dp[1][0] << '\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}