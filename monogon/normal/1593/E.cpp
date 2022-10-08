
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
    int n, k;
    cin >> n >> k;
    vector<set<int>> g(n + 1);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    queue<int> Q;
    vi dist(n + 1);
    vector<bool> vis(n + 1);
    rep(i, 1, n + 1) {
        if(sz(g[i]) <= 1) {
            vis[i] = true;
            Q.push(i);
        }
    }
    int ans = 0;
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        ans += dist[x] >= k;
        for (int y : g[x]) {
            g[y].erase(x);
            if(!vis[y] && sz(g[y]) <= 1) {
                vis[y] = true;
                dist[y] = 1 + dist[x];
                Q.push(y);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}