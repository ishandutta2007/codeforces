
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; ll x;
    cin >> n >> m >> x;
    vector<ll> a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    vector<vector<pii>> g(n + 1);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i + 1});
        g[v].push_back({u, i + 1});
    }
    vector<ll> dp(n + 1);
    vector<bool> vis(n + 1, false);
    vector<vector<pii>> omghi(n + 1), omgbye(n + 1);
    function<void(int)> dfs = [&](int u) {
        dp[u] = a[u];
        vis[u] = true;
        for(auto &pa : g[u]) {
            int v, i;
            tie(v, i) = pa;
            if(!vis[v]) {
                dfs(v);
                dp[u] += dp[v] - x;
                if(dp[v] > 0) omghi[u].push_back({v, i});
                else omgbye[u].push_back({v, i});
            }
        }
    };
    dfs(1);
    if(dp[1] < 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    function<void(int)> solve = [&](int u) {
        sort(all(omghi[u]), [&](pii &pa, pii &pb) { return dp[pa.first] > dp[pb.first]; });
        sort(all(omgbye[u]), [&](pii &pa, pii &pb) { return dp[pa.first] > dp[pb.first]; });
        for(auto &pa : omghi[u]) {
            int v, i;
            tie(v, i) = pa;
            solve(v);
        }
        for(auto &pa : omghi[u]) {
            int v, i;
            tie(v, i) = pa;
            cout << i << '\n';
        }
        for(auto &pa : omgbye[u]) {
            int v, i;
            tie(v, i) = pa;
            cout << i << '\n';
        }
        for(auto &pa : omgbye[u]) {
            int v, i;
            tie(v, i) = pa;
            solve(v);
        }
    };
    solve(1);
}