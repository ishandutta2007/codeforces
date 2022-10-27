#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, m;
int Col;
array <int, 3> edges[nax];
vector <int> g[nax];
int link[nax];
int s[nax];
int pcnt_par(int x) {
    return __builtin_popcount(x) % 2;
}
int get_other(int node, int e_id) {
    return node ^ edges[e_id][0] ^ edges[e_id][1];
}

void dfs(int node, int parent, int sum, int link_to) {
    link[node] = link_to;
    s[node] = sum;
    for (int id : g[node]) {
        int to = get_other(node, id);
        if (to == parent) continue;
        int w = edges[id][2];
        if (w == -1) {
            dfs(to, node, sum, id);
        } else {
            dfs(to, node, sum ^ pcnt_par(w), link_to);
        }
    }
}

int par[nax];
int sx[nax];
int sz[nax];
int ans[nax];

int find(int x) {
    int res = 0;
    while (x != par[x]) {
        res ^= sx[x];
        x = par[x];
    }
    return res ^ sx[x];
}
int find_par(int x) {
    while (x != par[x]) x = par[x];
    return x;
}

void dfs_ans(int node, int parent, int fuck) {
    for (int id : g[node]) {
        int to = get_other(node, id);
        if (to == parent) continue;
        if (edges[id][2] == -1) {
            ans[id] ^= fuck;
            dfs_ans(to, node, fuck ^ ans[id]);
        } else dfs_ans(to, node, fuck);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1 ; i < n ; ++ i) {
        auto &[u, v, w] = edges[i];
        cin >> u >> v >> w;
        g[u].push_back(i);
        g[v].push_back(i);
    }
    dfs(1, 0, 0, 0);
    iota(par, par + 1 + n, 0);
    fill(sx, sx + n + 1, 0);
    fill(sz, sz + n + 1, 1);

    for (int i = 1 ; i <= m ; ++ i) {
        int a, b, parity;
        cin >> a >> b >> parity;
        int cur_par = s[a] ^ s[b] ^ parity;
        int sa = find(link[a]), sb = find(link[b]);
        int pa = find_par(link[a]), pb = find_par(link[b]);
     //   cout << link[a] << " ^ " << link[b] << " = " << cur_par << '\n';
        if (pa == pb) {
            if ((sa ^ sb) != cur_par) {
                cout << "NO\n";
                for (int j = i + 1 ; j <= m ; ++ j)
                    cin >> a >> b >> parity;
                return;
            }
        } else {
            if (sz[pa] < sz[pb]) {
                swap(sa, sb); swap(pa, pb);
            }
            sz[pa] += sz[pb];
            par[pb] = pa;
            sx[pb] ^= sa ^ sb ^ cur_par;
        }
    }

    for (int i = 0 ; i < n ; ++ i)
        ans[i] = find(i);

    if (ans[0] == 1) {
        for (int i = 0 ; i < n ; ++ i)
            if (find_par(i) == find_par(0)) ans[i] ^= 1;
    }
//    }    cout <<"ANS: ";
//    for (int i = 0 ; i < n ; ++ i) {
//        cout << ans[i] << ' ';
//    }
//    cout << '\n';
    dfs_ans(1, 0, 0);

    cout << "YES\n";
    for (int i = 1 ; i < n ; ++ i) {
        auto &[u, v, w] = edges[i];
        cout << u << ' ' << v << ' ';
        if (w == -1) w = ans[i];
        cout << w << '\n';
    }
}
/**
1
5 6
3 2 0
2 4 -1
5 4 -1
2 1 -1
2 4 1
5 2 0
4 5 1
5 2 0
5 4 1
4 1 0
*/

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ; ) {
        solve();
        for (int i = 1 ; i <= n ; ++ i)
            g[i].clear();
    }
}
/**
    Ugly quote of the day.
    "Well, what's good problem?
    Many types of problem can be classified as good.
    But one of such types is the one that can make you smile or laugh even in the worst day of your life."
*/