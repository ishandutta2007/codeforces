#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
vector <int> g[nax];
int c[2];
vector <int> where[2];
void dfs(int node, int parent, int dep) {
    c[dep % 2] += 1;
    where[dep % 2].push_back(node);
    for (int to : g[node]) {
        if (to != parent)
            dfs(to, node, dep + 1);
    }
}
int n;
int ans[nax];
void solve() {
    cin >> n;
    set <int> s;
    for (int i = 1 ; i < n ; ++ i) {
        s.insert(i);
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0 ; i < 2 ; ++ i) where[i].clear();
    s.insert(n);
    memset(c, 0, sizeof(c));
    dfs(1, 0, 0);
    int mx = min(c[0], c[1]);
    int idx = c[0] < c[1] ? 0 : 1;
    int mx_bit = 0;

    for (int j = 18 ; j >= 0 ; -- j) {
        if (mx >> j & 1) {
            for (int i = (1 << j) ; i < (1 << (j + 1)) ; ++ i) {
                assert(s.count(i));
                s.erase(i);
                int f = where[idx].back();
                where[idx].pop_back();
                ans[f] = i;
            }
        }
    }
    for (int i : s) {
        int f = where[idx ^ 1].back();
        where[idx ^ 1].pop_back();
        ans[f] = i;
    }
    for (int i = 1 ; i <= n ; ++ i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ; ) {
        solve();
        for (int i = 1 ; i <= n ; ++ i)
            g[i].clear();
    }
}
/*
    Missing the contest. :3
*/