
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
    int n;
    cin >> n;
    vi ty(n + 1);
    vector<vi> g(n + 1), g2(n + 1);
    vi tin(n + 1), tout(n + 1), tin2(n + 1), tout2(n + 1), dep(n + 1);
    vector<array<int, 20>> par(n + 1), arrow(n + 1);

    rep(i, 1, n + 1) {
        cin >> par[i][0] >> ty[i];
        if(par[i][0] != -1) {
            dep[i] = 1 + dep[par[i][0]];
            g2[par[i][0]].push_back(i);
            if(ty[i] == 0) {
                g[par[i][0]].push_back(i);
                arrow[i][0] = 1;
            }else {
                arrow[i][0] = 0;
            }
        }else {
            par[i][0] = i;
        }
    }
    rep(l, 1, 20) {
        rep(i, 1, n + 1) {
            par[i][l] = par[par[i][l - 1]][l - 1];
            arrow[i][l] = arrow[i][l - 1] + arrow[par[i][l - 1]][l - 1];
        }
    }
    int ti = 0;
    vector<bool> vis(n + 1, false);
    function<void(int)> dfs = [&](int x) {
        tin[x] = ti++;
        vis[x] = true;
        for(int y : g[x]) {
            dfs(y);
        }
        tout[x] = ti++;
    };
    function<void(int)> dfs2 = [&](int x) {
        tin2[x] = ti++;
        vis[x] = true;
        for(int y : g2[x]) {
            dfs2(y);
        }
        tout2[x] = ti++;
    };
    rep(i, 1, n + 1) {
        if(!vis[i] && (par[i][0] == i || ty[i] == 1)) {
            dfs(i);
        }
    }
    fill(all(vis), false);
    rep(i, 1, n + 1) {
        if(!vis[i] && par[i][0] == i) {
            dfs2(i);
        }
    }
    auto anc = [&](int x, int y) {
        return tin2[x] <= tin2[y] && tout2[y] <= tout2[x];
    };
    auto lca = [&](int x, int y) {
        if(anc(x, y)) return x;
        for(int l = 19; l >= 0; l--) {
            if(!anc(par[x][l], y)) x = par[x][l];
        }
        return par[x][0];
    };
    auto get = [&](int x, int d) {
        int ans = 0;
        rep(l, 0, 20) {
            if(d >> l & 1) {
                ans += arrow[x][l];
                x = par[x][l];
            }
        }
        return ans;
    };

    int q;
    cin >> q;
    while(q--) {
        int ty, u, v;
        cin >> ty >> u >> v;
        ty--;
        if(ty == 0) {
            if(tin[u] < tin[v] && tout[v] < tout[u]) {
                cout << "YES\n";
            }else {
                cout << "NO\n";
            }
        }else {
            if(anc(v, u) || par[u][19] != par[v][19]) {
                cout << "NO\n";
            }else {
                int c = lca(u, v);
                if(get(u, dep[u] - dep[c]) == dep[u] - dep[c] && get(v, dep[v] - dep[c]) == 0) {
                    cout << "YES\n";
                }else {
                    cout << "NO\n";
                }
            }
            // cout << (u != v && D1.trace(u) == D2.trace(v) && D1.trace(u) != v ? "YES" : "NO") << '\n';
        }
    }
}