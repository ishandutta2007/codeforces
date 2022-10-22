#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define sz(a) int((a).size())
#define ll long long
#define db double
#define vi vector<int>
using namespace std;
const int N = 2e5 + 10;
struct unionfind {
    int fa[N];
    void init(int n) {FOR(i, 1, n) fa[i] = i; }
    int gf(int x) {return fa[x] == x ? x : fa[x] = gf(fa[x]); }
    int me(int x, int y) {
        x = gf(x), y = gf(y);
        if(x == y) return 0;
        return fa[x] = y, 1;
    }
}t[2];
int n, m, col[N], vis[N];
vector<pair<int, int> > e[N];
void dfs(int u, int fa, int c) {
    vis[u] = 1;
    for(auto [v, w] : e[u]) {
        if(!vis[v]) {
            col[w] = c;
            dfs(v, u, c ^ 1);
        }
    }
}
void solve() {
    cin >> n >> m;
    FOR(u, 1, n) e[u].clear();
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        e[u].emplace_back(v, i);
        e[v].emplace_back(u, i);
    }
    FOR(i, 1, n) vis[i] = 0;
    FOR(i, 1, m) col[i] = -1;
    dfs(1, 0, 0);
    FOR(o, 0, 1) t[o].init(n);
    FOR(u, 1, n) {
        for(auto [v, w] : e[u]) if(col[w] != -1) {
            t[col[w]].me(u, v);
        }
    }
    FOR(u, 1, n) {
        for(auto [v, w] : e[u]) if(col[w] == -1) {
            if(t[0].me(u, v)) {
                col[w] = 0;
            } else if(t[1].me(u, v)) {
                col[w] = 1;
            } else {
                assert(0);
            }
        }
    }
    FOR(i, 1, m) cout << col[i];
    cout << "\n";
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; solve());
}