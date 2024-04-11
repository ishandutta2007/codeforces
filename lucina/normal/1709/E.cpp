#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
int offset[nax];
set <int> setik[nax];
vector <int> g[nax];
int ans = 0;

void dfs(int v, int parent) {
    if (parent > 0) g[v].erase(find(g[v].begin(), g[v].end(), parent));
    for (int to : g[v]) {
        dfs(to, v);
    }
    sort(g[v].begin(), g[v].end(), [&](int u, int v) -> bool {
            return setik[u].size() > setik[v].size();
    });
    if (g[v].empty()) {
        setik[v].insert(a[v]);
        offset[v] = 0;
        return;
    }

    int r = g[v][0];
    if (setik[r].count(a[v] ^ offset[r])) {
        ans += 1;
        return;
    } else {
        offset[v] = offset[r] ^ a[v];
        setik[v].swap(setik[r]);
        setik[v].insert(a[v] ^ offset[v]);
    }

    for (int i = 1 ; i < g[v].size() ; ++ i) {
        int k = g[v][i];

        for (int u : setik[k]) {
            int in = offset[k] ^ u ^ offset[v];
            if (setik[v].count(in)) {
                ans += 1;
                setik[v].clear();
                return;
            }
        }

        for (int u : setik[k]) {
            int in = offset[k] ^ u ^ offset[v];
            setik[v].insert(in ^ a[v]);
        }
        setik[k].clear();
    }
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);

    cout << ans << '\n';

}
/*
    Eduroundd
*/