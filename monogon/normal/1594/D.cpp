
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

// i -> j "crewmate"
// same

// j -> i "impostor"
// opposite

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n + 1);
    rep(i, 0, m) {
        int u, v;
        string s;
        cin >> u >> v >> s;
        if(s[0] == 'c') {
            g[u].push_back({v, 0});
            g[v].push_back({u, 0});
        }else {
            g[u].push_back({v, 1});
            g[v].push_back({u, 1});
        }
    }
    vector<bool> vis(n + 1, false);
    vi col(n + 1);
    bool ok = true;
    auto dfs = [&](auto dfs, int x, int c) -> pii {
        col[x] = c;
        pii pa = {0, 0};
        vis[x] = true;
        (c == 0 ? pa.first : pa.second)++;
        for(auto &p : g[x]) {
            int change, y;
            tie(y, change) = p;
            change ^= c;
            if(vis[y]) {
                if(col[y] != change) ok = false;
            }else {
                pii pb = dfs(dfs, y, change);
                pa.first += pb.first;
                pa.second += pb.second;
            }
        }
        return pa;
    };
    int ans = 0;
    rep(i, 1, n + 1) {
        if(!vis[i]) {
            pii pa = dfs(dfs, i, 0);
            ans += max(pa.first, pa.second);
        }
    }
    if(!ok) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}