#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
//  i  0- 2 * i  true, 2 * i + 1  false
//..     x5 || x7
//add_edge(10, 14)
//   !x5 || x7
//add_edge(11, 14)
struct twosat {
    int n;
    vector<vector<int> > gr;
    vector<bool> used;
    vector<int> order, comp;
    vector < vector < int > > g;
    void add_edge(int x, int y) {
        for (int c = 0; c < 2; c++) {
            gr[y].emplace_back(x ^ 1);
            g[x ^ 1].emplace_back(y);
            swap(x, y);
        }
    }

    twosat(int x) {
        n = 2 * x;
        gr.resize(n);
        g.resize(n);
        used.resize(n);
        comp.resize(n, -1);
    }

    void dfs_first(int v) {
        used[v] = true;
        for (int to : g[v]) {
            if (!used[to]) {
                dfs_first(to);
            }
        }
        order.emplace_back(v);
    }

    void dfs_second(int v, int val) {
        comp[v] = val;
        for (int to : gr[v]) {
            if (comp[to] == -1) {
                dfs_second(to, val);
            }
        }
    }

    pair<vector<bool>, bool> solve() {
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                dfs_first(i);
            }
        }
        int sz = 0;
        reverse(order.begin(), order.end());
        for (int v : order) {
            if (comp[v] == -1) {
                dfs_second(v, sz);
                sz++;
            }
        }
        vector<bool> ans(n / 2);
        for (int i = 0; i < n; i += 2) {
            if (comp[i] == comp[i ^ 1]) {
                return make_pair(vector<bool>(), false);
            } else {
                ans[i / 2] = (comp[i] > comp[i ^ 1]);
            }
        }
        return make_pair(ans, true);
    }
};
int n, q;
const int maxN = 4e5 + 10;
bool hv[maxN][26];
vector<int> g[maxN];
int par[maxN];
int tin[maxN];
int timer = 0;
int tout[maxN];
void dfs(int v, int p) {
    tin[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        par[to] = v;
        dfs(to, v);
    }
    tout[v] = timer++;
}
int x[maxN], y[maxN];
string s[maxN];
bool is_anc(int a, int b) {
    return (tin[a] <= tin[b] && tout[b] <= tout[a]);
}
vector<int> path[maxN];
vector<int> let[maxN];
int id[maxN][26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(0, -1);
    for (int i = 0; i < q; i++) {
        cin >> x[i] >> y[i];
        --x[i]; --y[i];
        cin >> s[i];
        vector<int> p1;
        int c1 = x[i];
        while (!is_anc(c1, y[i])) {
            p1.emplace_back(c1);
            c1 = par[c1];
        }
        p1.emplace_back(c1);
        vector<int> p2;
        int c2 = y[i];
        while (!is_anc(c2, x[i])) {
            p2.emplace_back(c2);
            c2 = par[c2];
        }
        reverse(p2.begin(), p2.end());
        for (int v : p2) p1.emplace_back(v);
        assert(p1.size() == s[i].size());
        for (int z = 0; z < p1.size(); z++) {
            hv[p1[z]][s[i][z] - 'a'] = true;
            hv[p1[p1.size() - 1 - z]][s[i][z] - 'a'] = true;
        }
        path[i] = p1;
    }
    int T = 0;
    for (int i = 0; i < n; i++) {
        for (int z = 0; z < 26; z++) {
            if (hv[i][z]) {
                let[i].emplace_back(z);
                id[i][z] = T;
                T += 2;
            }
        }
    }
    twosat ts(T + q);
    for (int i = 0; i < n; i++) {
        if (!let[i].empty()) {
            for (int c : let[i]) {
                ts.add_edge(2 * id[i][c] + 1, 2 * id[i][c] + 2);
            }
            for (int z = 0; z + 1 < let[i].size(); z++) {
                int f1 = let[i][z];
                int f2 = let[i][z + 1];
                ts.add_edge(2 * id[i][f1] + 3, 2 * id[i][f2] + 2);
                ts.add_edge(2 * id[i][f1] + 3, 2 * id[i][f2] + 1);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        for (int z = 0; z < path[i].size(); z++) {
            ts.add_edge(2 * id[path[i][z]][s[i][z] - 'a'], 2 * (T + i) + 1);
            ts.add_edge(2 * id[path[i][path[i].size() - 1 - z]][s[i][z] - 'a'], 2 * (T + i));
        }
    }
    auto res = ts.solve();
    if (res.second == false) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            if (let[i].empty()) cout << "a";
            else {
                for (int v : let[i]) {
                    if (res.first[id[i][v]]) {
                        cout << (char)('a' + v);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}