#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int n, fa[N], deg[N], rdeg[N];
vector<int> g[N], e[N];
int dfs(int u, int fa, int dep) {
    ::fa[u] = fa;
    int now = (sz(g[u]) & 1) ^ dep;
    vector<int> son[2];
    for(auto v : g[u]) if(v != fa) {
        int res = dfs(v, u, dep ^ 1);
        if(res == -1) return -1;
        son[res].emplace_back(v);
    }
    int pre = 0;
    while(sz(son[now ^ 1]) > 0) {
        if(pre) e[pre].emplace_back(son[now ^ 1].back());
        pre = son[now ^ 1].back();
        son[now ^ 1].pop_back();
        now ^= 1;
    }
    if(sz(son[now]) > 1) return -1;
    if(fa) {
        if(pre) e[pre].emplace_back(u);
        pre = u;
    }
    if(sz(son[now]) == 1) {
        if(!fa) return -1;
        e[pre].emplace_back(son[now].back());
        return now;
    }
    return now;
}
mt19937 gen(__builtin_ia32_rdtsc());
int rd(int l, int r) {
    uniform_int_distribution<int> rng(l, r);
    return rng(gen);
}
void solve() {
    cin >> n;
    for(int u = 1; u <= n; u++) g[u].clear(), e[u].clear(), deg[u] = 0;
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    int res = dfs(1, 0, 0);
    if(res == -1) cout << "NO" << endl;
    else {
        for(int u = 1; u <= n; u++) rdeg[u] = sz(g[u]);
        cout << "YES" << endl;
        for(int u = 1; u <= n; u++) for(auto v : e[u]) deg[v]++;
        deque<int> q;
        for(int u = 2; u <= n; u++) if(deg[u] == 0) q.emplace_back(u);
        while(!q.empty()) {
            int u = q.front();
            q.pop_front();
            cout << u <<" " << fa[u] << endl;
            if((rdeg[u] + rdeg[fa[u]]) & 1) assert(0);
            rdeg[u]--, rdeg[fa[u]]--;
            for(auto v : e[u]) {
                deg[v]--;
                if(deg[v] == 0) q.emplace_back(v);
            }
        }
    }
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}