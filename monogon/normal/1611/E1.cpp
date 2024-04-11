
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
    vector<bool> f(n + 1);
    rep(i, 0, k) {
        int x;
        cin >> x;
        f[x] = true;
    }
    vector<vi> g(n + 1);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi dist(n + 1), dep(n + 1);
    auto dfs = [&](auto dfs, int x, int p) -> void {
        dist[x] = INT_MAX;
        for(int y : g[x]) {
            if(y != p) {
                dep[y] = 1 + dep[x];
                dfs(dfs, y, x);
                if(dist[y] != INT_MAX) {
                    dist[x] = min(dist[x], 1 + dist[y]);
                }
            }
        }
        if(f[x]) dist[x] = 0;
    };
    dfs(dfs, 1, 1);
    auto dfs2 = [&](auto dfs2, int x, int p) -> bool {
        int c = 0;
        if(dep[x] >= dist[x]) return false;
        for(int y : g[x]) {
            if(y != p) {
                c++;
                if(dfs2(dfs2, y, x)) {
                    return true;
                }
            }
        }
        if(c == 0) return true;
        return false;
    };
    cout << (dfs2(dfs2, 1, 1) ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}