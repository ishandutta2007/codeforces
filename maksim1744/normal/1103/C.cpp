/*
    22.01.2019 18:17:55
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#include "C:/C++ libs/print.h"
#define show(x) cout << "     " << #x << " = " << to_string(x) << endl;
#else
#define show(x) 42;
#define print(x) 42;
#define printTree(x) 42;
#define printMatrix(x) 42;
#endif

vector< bool > u;
vector< int > p;
vector< vector< int > > g;
vector< bool > leaves;
vector< int > d;

void dfs(int v, int _p = -1) {
    p[v] = _p;
    if (_p == -1) {
        d[v] = 0;
    } else {
        d[v] = d[_p] + 1;
    }
    bool children = false;
    u[v] = true;
    for (auto e : g[v]) {
        if (!u[e]) {
            children = true;
            dfs(e, v);
        }
    }
    if (!children) {
        leaves[v] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    g.resize(n);
    u.assign(n, false);
    leaves.assign(n, false);
    p.assign(n, -1);
    d.assign(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    for (int i = 0; i < n; ++i) {
        if ((long long)(d[i] + 1) * k >= n) {
            cout << "PATH\n";
            cout << d[i] + 1 << '\n';
            int v = i;
            for (int j = 0; j < d[i] + 1; ++j) {
                cout << v + 1 << ' ';
                v = p[v];
            }
            cout << '\n';
            return 0;
        }
    }
    cout << "CYCLES\n";
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!leaves[i]) {
            continue;
        }
        int leaf = i;
        int i1, i2;
        if (p[leaf] == g[leaf][0]) {
            i1 = g[leaf][1];
            i2 = g[leaf][2];
        } else if (p[leaf] == g[leaf][1]) {
            i1 = g[leaf][0];
            i2 = g[leaf][2];
        } else {
            i1 = g[leaf][0];
            i2 = g[leaf][1];
        }
        if ((d[leaf] - d[i1] + 1) % 3 != 0) {
            int v = leaf;
            cout << d[leaf] - d[i1] + 1 << '\n';
            for (int j = 0; j < d[leaf] - d[i1] + 1; ++j) {
                cout << v + 1 << ' ';
                v = p[v];
            }
            cout << '\n';
        } else if ((d[leaf] - d[i2] + 1) % 3 != 0) {
            int v = leaf;
            cout << d[leaf] - d[i2] + 1 << '\n';
            for (int j = 0; j < d[leaf] - d[i2] + 1; ++j) {
                cout << v + 1 << ' ';
                v = p[v];
            }
            cout << '\n';
        } else {
            if (d[i2] < d[i1]) {
                swap(i1, i2);
            }
            cout << d[i2] - d[i1] + 2 << '\n';
            int v = i2;
            for (int j = 0; j < d[i2] - d[i1] + 1; ++j) {
                cout << v + 1 << ' ';
                v = p[v];
            }
            cout << leaf + 1 << ' ';
            cout << '\n';
        }
        ++cnt;
        if (cnt == k) {
            break;
        }
    }
    return 0;
}