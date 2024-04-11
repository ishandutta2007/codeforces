#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n, p;
vector <int> g[nax];
array <int, 2> e[nax];
int a_node[nax];
int a_edge[nax];
int t;
/**
    answer is 2^n obviously
*/

inline int get_other(int id, int v) {
    return e[id][0] ^ e[id][1] ^ v;
}

void dfs(int node, int par, int cur) {
    for (int e_id : g[node]) {
        int to = get_other(e_id, node);
        if (to == par) continue;

        a_edge[e_id] = cur + t;
        a_node[to] = n - cur + t;
        t += 1;
        dfs(to, node, cur ^ n);
    }
}

void solve() {
    cin >> p;
    n = 1 << p;
    for (int i = 1 ; i < n ; ++ i) {
        auto &[u, v] = e[i];
        cin >> u >> v;
        g[u].push_back(i);
        g[v].push_back(i);
    }
    a_node[1] = n;
    t = 1;
    dfs(1, 0, n);
    cout << 1 << '\n';
    for (int i = 1 ; i <= n ; ++ i) {
        cout << a_node[i] << ' ';
    }
    cout << '\n';
    for (int i = 1 ; i < n ; ++ i)
        cout << a_edge[i] << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ; ) {
        solve();
        for (int i = 1 ; i <= n ; ++ i) {
            g[i].clear();
        }
    }
}