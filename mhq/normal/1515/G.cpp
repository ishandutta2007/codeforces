#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;

struct scc {
    //0-,    
    int n;
    vector<vector<int>> g;
    vector<vector<int>> gr;
    vector<int> order;
    vector<bool> used;

    void dfs(int v) {
        used[v] = true;
        for (int to : g[v]) {
            if (!used[to]) {
                dfs(to);
            }
        }
        order.emplace_back(v);
    }

    vector < vector < int > > components;

    void sec_dfs(int v, vector<int>& cmp) {
        cmp.emplace_back(v);
        used[v] = true;
        for (int to : gr[v]) {
            if (!used[to]) {
                sec_dfs(to, cmp);
            }
        }
    }

    scc(vector<vector<int>> &edge) {
        g = edge;
        n = g.size();
        gr.resize(n);
        for (int i = 0; i < n; i++) {
            for (int v : g[i]) {
                gr[v].emplace_back(i);
            }
        }
        used = vector<bool>(n, false);
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                dfs(i);
            }
        }
        reverse(order.begin(), order.end());
        used.assign(n, false);
        for (int v : order) {
            if (!used[v]) {
                vector < int > cmp;
                sec_dfs(v, cmp);
                components.emplace_back(cmp);
            }
        }

    }
};

const int maxN = 2e5 + 10;
vector<pair<int,int>> g[maxN];
int id[maxN];
ll c[maxN];
bool used[maxN];
ll d[maxN];
void dfs(int v) {
    used[v] = true;
    for (auto& it : g[v]) {
        if (id[it.first] != id[v]) continue;
        if (!used[it.first]) {
           d[it.first] = d[v] + it.second;
           dfs(it.first);
        }
        else {
            ll t = abs(d[it.first] - it.second - d[v]);
            if (t != 0) {
                if (c[id[v]] == 0) c[id[v]] = t;
                else {
                    c[id[v]] = __gcd(c[id[v]], t);
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    vector<vector<int>> ed(n);
    vector<vector<pair<pair<int,int>,int>>> all;
    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        --a; --b;
        ed[a].emplace_back(b);
        g[a].emplace_back(b, l);
        g[b].emplace_back(a, -l);
    }
    scc T(ed);
    for (int i = 0; i < T.components.size(); i++) {
        for (int x = 0; x < T.components[i].size(); x++) {
            id[T.components[i][x]] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int v;
        ll s, t;
        cin >> v >> s >> t;
        v--;
        if (s == 0 || (c[id[v]] != 0 && (s % __gcd(t, c[id[v]]) == 0))) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}