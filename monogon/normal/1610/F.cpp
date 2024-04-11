
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
    int n, m;
    cin >> n >> m;
    vi u(m), v(m), w(m);
    vector<vi> g1(n + 1), g2(n + 1);
    rep(i, 0, m) {
        cin >> u[i] >> v[i] >> w[i];
        (w[i] == 1 ? g1 : g2)[u[i]].push_back(i);
        (w[i] == 1 ? g1 : g2)[v[i]].push_back(i);
    }
    vi dir(m);
    vector<vector<pii>> adj(m);
    rep(i, 1, n + 1) {
        while(sz(g1[i]) >= 2) {
            int j = g1[i].back(); g1[i].pop_back();
            int k = g1[i].back(); g1[i].pop_back();
            adj[j].push_back({k, i});
            adj[k].push_back({j, i});
        }
        while(sz(g2[i]) >= 2) {
            int j = g2[i].back(); g2[i].pop_back();
            int k = g2[i].back(); g2[i].pop_back();
            adj[j].push_back({k, i});
            adj[k].push_back({j, i});
        }
        if(!g1[i].empty() && !g2[i].empty()) {
            int j = g1[i][0], k = g2[i][0];
            adj[j].push_back({k, i});
            adj[k].push_back({j, i});
        }
    }
    vector<bool> vis(m, false);
    auto dfs = [&](auto dfs, int i) -> void {
        vis[i] = true;
        dir[i] = 1;
        for(auto &pa : adj[i]) {
            int j = pa.first;
            int node = pa.second;
            if(!vis[j]) {
                dfs(dfs, j);
                if((u[i] == node) == (u[j] == node)) {
                    dir[i] = 3 ^ dir[j];
                }else {
                    dir[i] = dir[j];
                }
            }
        }
    };
    rep(i, 0, m) {
        if(sz(adj[i]) % 2 == 1 || adj[i].empty()) {
            if(!vis[i]) {
                dfs(dfs, i);
            }
        }
    }
    rep(i, 0, m) {
        if(!vis[i]) {
            dfs(dfs, i);
        }
    }
    vi sum(n + 1, 0);
    rep(i, 0, m) {
        if(dir[i] == 1) {
            sum[u[i]] += w[i];
            sum[v[i]] -= w[i];
        }else {
            sum[u[i]] -= w[i];
            sum[v[i]] += w[i];
        }
    }
    int ans = 0;
    rep(i, 1, n + 1) ans += (abs(sum[i]) == 1);

    cout << ans << '\n';
    rep(i, 0, m) cout << dir[i];
    cout << '\n';
}