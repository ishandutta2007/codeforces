
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
    int n;
    cin >> n;
    vector<string> a(n), b(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, n) {
        cin >> b[i];
    }
    vector<vector<pair<bool, int>>> adj(2 * n);
    rep(i, 0, n) rep(j, 0, n) {
        adj[i].push_back({a[i][j] != b[i][j], n + j});
        adj[n + j].push_back({a[i][j] != b[i][j], i});
    }
    bool ok = true;
    vector<bool> vis(2 * n, false), col(2 * n, false);
    function<void(int)> dfs = [&](int x) {
        vis[x] = true;
        for(auto &pa : adj[x]) {
            bool b = pa.first;
            int y = pa.second;
            if(!vis[y]) {
                col[y] = col[x] ^ b;
                dfs(y);
            }else if((col[x] ^ b) != col[y]) {
                ok = false;
            }
        }
    };
    rep(i, 0, 2 * n) {
        if(!vis[i]) dfs(i);
    }
    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}