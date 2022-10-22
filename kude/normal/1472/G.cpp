#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        VVI to(n);
        rep(i, m) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            to[u].push_back(v);
        }
        VI distance(n, -1);
        queue<int> q;
        distance[0] = 0;
        q.push(0);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            int nd = distance[u] + 1;
            for(int v: to[u]) {
                if (distance[v] == -1) {
                    distance[v] = nd;
                    q.push(v);
                }
            }
        }
        VI dp(n, -1);
        auto dfs = [&](auto&& self, int u) {
            if (dp[u] != -1) return dp[u];
            dp[u] = distance[u];
            for(int v: to[u]) {
                int dv = distance[v];
                if (dv <= distance[u]) {
                    chmin(dp[u], dv);
                } else {
                    int res = self(self, v);
                    chmin(dp[u], res);
                }
            }
            return dp[u];
        };
        dfs(dfs, 0);
        rep(i, n) cout << dp[i] << " \n"[i + 1 == n];
    }
}