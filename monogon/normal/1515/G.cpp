
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
    vector<vector<pair<ll, int>>> adj(n + 1), adjr(n + 1);
    rep(i, 0, m) {
        int a, b; ll l;
        cin >> a >> b >> l;
        adj[a].push_back({l, b});
        adjr[b].push_back({l, a});
    }
    vector<bool> vis(n + 1, false);
    vi st, comp(n + 1, -1);
    function<void(int)> dfs = [&](int x) {
        vis[x] = true;
        for(auto &pa : adj[x]) {
            int y = pa.second;
            if(!vis[y]) {
                dfs(y);
            }
        }
        st.push_back(x);
    };
    function<void(int, int)> dfs2 = [&](int x, int c) {
        comp[x] = c;
        for(auto &pa : adjr[x]) {
            int y = pa.second;
            if(comp[y] == -1) {
                dfs2(y, c);
            }
        }
    };
    rep(i, 1, n + 1) {
        if(!vis[i]) dfs(i);
    }
    while(!st.empty()) {
        int x = st.back(); st.pop_back();
        if(comp[x] == -1) dfs2(x, x);
    }

    vector<ll> g(n + 1, 0), d(n + 1, 0), dr(n + 1, 0);
    function<void(int)> dfs3 = [&](int x) {
        vis[x] = true;
        for(auto &pa : adj[x]) {
            ll w; int y;
            tie(w, y) = pa;
            if(!vis[y] && comp[y] == comp[x]) {
                d[y] = d[x] + w;
                dfs3(y);
            }
        }
    };
    function<void(int)> dfs4 = [&](int x) {
        vis[x] = true;
        for(auto &pa : adjr[x]) {
            ll w; int y;
            tie(w, y) = pa;
            if(!vis[y] && comp[y] == comp[x]) {
                dr[y] = dr[x] + w;
                dfs4(y);
            }
        }
    };
    fill(all(vis), false);
    rep(i, 1, n + 1) if(comp[i] == i) dfs3(i);

    fill(all(vis), false);
    rep(i, 1, n + 1) if(comp[i] == i) dfs4(i);

    rep(i, 1, n + 1) {
        for(auto &pa : adj[i]) {
            ll w; int y;
            tie(w, y) = pa;
            if(comp[y] == comp[i]) {
                g[comp[i]] = gcd(g[comp[i]], d[i] + dr[y] + w);
            }
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int v; ll s, t;
        cin >> v >> s >> t;
        // - s = d[v] + g[comp[v]] x + dr[v] (mod t)
        // g[comp[v]] x + t y = -s - d[v] - dr[v]
        // s + d[v] + dr[v] is a multiple of gcd(g[comp[v]], t)
        ll G = gcd(g[comp[v]], t);
        if((s + d[v] + dr[v]) % G == 0) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
}