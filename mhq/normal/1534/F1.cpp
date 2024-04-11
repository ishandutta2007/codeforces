#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 4e5 + 10;
int f[maxN];
int L[maxN], R[maxN];
int mx_far[maxN];
int g[maxN];
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
void dfs(int v, vector<bool>& used, vector<vector<int>>& edge) {
    used[v] = true;
    for (auto& it : edge[v]) {
        if (!used[it]) {
            dfs(it, used, edge);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    bool has = false;
    vector<vector<char>> a(n, vector<char>(m, '.'));
    vector<vector<int>> edge(n * m);
    auto id = [&](int x, int y) {
        return m * x + y;
    };
    vector<int> mn(m, 1e9);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                has = true;
                mn[j] = min(mn[j], i);
            }

        }
    }
    if (!has) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 < n) {
                edge[id(i, j)].emplace_back(id(i + 1, j));
            }
            if (j > 0 && a[i][j - 1] == '#') {
                edge[id(i, j)].emplace_back(id(i, j - 1));
            }
            if (j + 1 < m && a[i][j + 1] == '#') {
                edge[id(i, j)].emplace_back(id(i, j + 1));
            }
            if (i > 0 && a[i - 1][j] == '#') {
                edge[id(i, j)].emplace_back(id(i - 1, j));
            }
        }
    }
    auto T = scc(edge);
    vector<bool> used(n * m, false);
    int C = 0;
    vector<bool> imp(n * m, false);
    for (int j = 0; j < m; j++) {
        if (mn[j] < n) imp[id(mn[j], j)] = true;
    }
    for (auto& it : T.components) {
        for (int v : it) {
            if (imp[v] && !used[v]) {
                dfs(v, used, edge);
                C++;
            }
        }
    }
    cout << C << endl;

    return 0;
}