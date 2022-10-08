
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
    vi k(n);
    vector<vi> cl(n);
    vector<vector<pair<int, bool>>> ve(m + 1);
    vector<bool> ans(m + 1);
    rep(i, 0, n) {
        cin >> k[i];
        cl[i].resize(k[i]);
        rep(j, 0, k[i]) {
            cin >> cl[i][j];
            ve[abs(cl[i][j])].push_back({i, cl[i][j] > 0});
        }
    }
    vector<bool> sat(n, false);
    vector<vector<tuple<int, int, bool>>> g(n);
    rep(i, 1, m + 1) {
        if(sz(ve[i]) == 1 || (sz(ve[i]) == 2 && ve[i][0].second == ve[i][1].second)) {
            ans[i] = ve[i][0].second;
            for(auto &pa : ve[i]) {
                sat[pa.first] = true;
            }
        }else if(sz(ve[i]) == 2) {
            if(!ve[i][0].second) swap(ve[i][0], ve[i][1]);
            int u = ve[i][0].first, v = ve[i][1].first;
            g[u].push_back({i, v, true});
            g[v].push_back({i, u, false});
        }
    }
    vector<bool> vis(n, false);
    vector<bool> ass(m + 1, false);
    function<void(int)> dfs = [&](int x) {
        vis[x] = true;
        for(auto &pa : g[x]) {
            int i, y; bool t;
            tie(i, y, t) = pa;
            if(!ass[i]) {
                ass[i] = true;
                ans[i] = !t;
                if(!vis[y]) {
                    dfs(y);
                }
            }
        }
    };
    rep(i, 0, n) {
        if(sat[i] && !vis[i]) {
            dfs(i);
        }
    }
    
    vector<bool> cyc(n, false);
    function<void(int)> dfs2 = [&](int x) {
        vis[x] = true;
        for(auto &pa : g[x]) {
            int i, y; bool t;
            tie(i, y, t) = pa;
            if(!ass[i]) {
                if(!vis[y]) {
                    ass[i] = true;
                    dfs2(y);
                    if(cyc[y]) {
                        cyc[x] = true;
                        ans[i] = t;
                    }else {
                        ans[i] = !t;
                    }
                }else {
                    ass[i] = true;
                    ans[i] = !t;
                    cyc[y] = true;
                }
            }
        }
    };

    rep(i, 0, n) {
        if(!vis[i]) {
            dfs2(i);
        }
    }
    
    bool flag = true;
    rep(i, 0, n) {
        bool s = false;
        for(int y : cl[i]) {
            if(ans[abs(y)] == (y > 0)) {
                s = true;
            }
        }
        flag &= s;
    }
    if(flag) {
        cout << "YES\n";
        rep(i, 1, m + 1) {
            cout << ans[i];
        }
        cout << '\n';
    }else {
        cout << "NO\n";
    }
}