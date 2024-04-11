
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

struct scc {
    int n;
    vector<vector<int>> g, gr;
    vector<int> st, comp;
    vector<bool> vis;
    scc(int n) : n(n) {
        g.resize(n);
        gr.resize(n);
        vis.assign(n, false);
        comp.assign(n, -1);
    }
    void add_edge(int u, int v) {
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    void dfs(int x) {
        vis[x] = true;
        for(int y : g[x]) {
            if(!vis[y]) {
                dfs(y);
            }
        }
        st.push_back(x);
    }
    void dfs2(int x, int c) {
        comp[x] = c;
        for(int y : gr[x]) {
            if(comp[y] == -1) {
                dfs2(y, c);
            }
        }
    }
    void solve() {
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i);
            }
        }
        while(!st.empty()) {
            int x = st.back(); st.pop_back();
            if(comp[x] == -1) {
                dfs2(x, x);
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vi a(m);
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, m) cin >> a[i];
    auto encode = [&](int i, int j) {
        return i * m + j;
    };
    scc S(n * m);
    rep(i, 0, n) rep(j, 0, m) {
        if(i < n - 1) {
            S.add_edge(encode(i, j), encode(i + 1, j));
            if(s[i][j] == '#' && s[i + 1][j] == '#') {
                S.add_edge(encode(i + 1, j), encode(i, j));
            }
        }
        if(s[i][j] == '#') {
            if(j > 0) {
                S.add_edge(encode(i, j), encode(i, j - 1));
            }
            if(j < m - 1) {
                S.add_edge(encode(i, j), encode(i, j + 1));
            }
        }
    }
    S.solve();
    vector<bool> sand(n * m, false);
    rep(i, 0, n) rep(j, 0, m) {
        if(s[i][j] == '#') sand[S.comp[encode(i, j)]] = true;
    }
    int cnt = 0;
    vector<bool> vis(n * m);
    fill(all(vis), false);
    vector<bool> seesand(n * m, false);
    vector<vi> grcomp(n * m);
    rep(i, 0, n * m) for(int x : S.gr[i]) {
        if(S.comp[i] != S.comp[x]) grcomp[S.comp[i]].push_back(S.comp[x]);
    }
    function<void(int)> dfs3 = [&](int x) {
        vis[x] = true;
        for(int y : grcomp[x]) {
            if(!vis[y]) dfs3(y);
            if(sand[y] || seesand[y]) seesand[x] = true;
        }
    };

    rep(i, 0, n * m) {
        if(S.comp[i] == i && !vis[i]) dfs3(i);
        if(S.comp[i] == i && sand[i] && !seesand[i]) cnt++;
    }
    cout << cnt << '\n';
}