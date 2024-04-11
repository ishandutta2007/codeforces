
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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vi> adj(n + 1);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    queue<int> Q;
    vector<bool> vis(n + 1, false);
    vi d(n + 1, 0), dp(n + 1, 0);
    vis[1] = true;
    Q.push(1);
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int y : adj[x]) {
            if(!vis[y]) {
                vis[y] = true;
                d[y] = 1 + d[x];
                Q.push(y);
            }
        }
    }
    fill(all(vis), false);
    function<void(int)> dfs = [&](int x) {
        dp[x] = d[x];
        vis[x] = true;
        for(int y : adj[x]) {
            if(!vis[y] && d[y] > d[x]) {
                dfs(y);
            }
            if(d[y] > d[x]) {
                dp[x] = min(dp[x], dp[y]);
            }else {
                dp[x] = min(dp[x], d[y]);
            }
        }
    };
    dfs(1);
    rep(i, 1, n + 1) cout << dp[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}