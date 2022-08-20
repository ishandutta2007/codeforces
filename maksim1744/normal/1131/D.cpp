/*
    27.03.2019 18:22:38
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

int n, m;
vector<vector<int>> g;
vector<vector<int>> g1;
vector<int> col;
vector<bool> u;
vector<vector<int>> equals;
int color = 0;
vector<int> topsort;
vector<int> w;

void dfs1(int v) {
    // if (v < n)
    //     equals.back().push_back(v);
    col[v] = color;
    for (auto k : g1[v]) {
        if (col[k] == -1)
            dfs1(k);
    }
}

void dfs2(int v) {
    // show(v);
    u[v] = 1;
    for (auto k : g[v]) {
        if (!u[k]) {
            dfs2(k);
        }
        w[v] = max(w[v], w[k] + 1);
    }
    topsort.push_back(v);
}

int main() {
    cin >> n >> m;
    g.resize(n + m);
    g1.resize(n + m);
    vector<string> f(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        f[i] = s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '=') {
                g1[i].push_back(j + n);
                g1[j + n].push_back(i);
            } else if (s[j] == '>') {
                g[i].push_back(j + n);
            } else if (s[j] == '<') {
                g[j + n].push_back(i);
            }
        }
    }
    show(g);
    // w.assign(n + m, 1);
    col.assign(n + m, -1);
    for (int i = 0; i < n + m; ++i) {
        if (col[i] == -1) {
            equals.emplace_back();
            dfs1(i);
            ++color;
        }
    }
    show(col);
    show(equals);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (col[i] == col[j + n] && f[i][j] != '=') {
                cout << "No\n";
                return 0;
            }
        }
    }
    g.clear();
    g.resize(color);
    vector<set<int>> to(color);
    // for (int i = 0; i < color; ++i) {
    //     for (int j = 0; j < color; ++j) {
    //     }
    // }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (col[i] != col[j + n]) {
                if (f[i][j] == '>')
                    to[col[i]].insert(col[j + n]);
                else if (f[i][j] == '<')
                    to[col[j + n]].insert(col[i]);
            }
        }
    }
    for (int i = 0; i < color; ++i) {
        g[i] = vector<int>(to[i].begin(), to[i].end());
    }
    w.assign(color, 1);
    show(g);
    // col.assign(n + m, 0);
    u.assign(color, false);
    for (int i = 0; i < color; ++i) {
        if (!u[i])
            dfs2(i);
    }
    show(w);
    // return 0;
    vector<int> w1 = w;
    w.assign(n + m, 0);
    for (int i = 0; i < n + m; ++i) {
        w[i] = w1[col[i]];
    }
    // reverse(topsort.begin(), topsort.end());
    // vector<int> w(n + m, -1);
    // int last_w = 1;
    // show(topsort);
    // for (auto k : topsort) {
        // int now_w = 1;
        // for (auto u : g[k]) {
            // if (w[u] == -1) {
            //     cout << "No\n";
            //     return 0;
            // }
            // now_w =  max(now_w, w[u] + 1);
        // }
        // if (k < n) {
        //     for (int i = 0; i < m; ++i) {
        //         if (w[i + n] == -1) continue;
        //         // show(i, w[i+n], f[k][i]);
        //         if (f[k][i] == '=') now_w = w[i + n];
        //         else if (f[k][i] == '>') now_w = max(w[i + n] + 1, now_w);
        //         else now_w = min(w[i + n] - 1, now_w);
        //     }
        // } else {
        //     for (int i = 0; i < n; ++i) {
        //         if (w[i] == -1) continue;
        //         if (f[i][k - n] == '=') now_w = w[i];
        //         else if (f[i][k - n] == '>') now_w = min(w[i] - 1, now_w);
        //         else now_w = max(w[i] + 1, now_w);
        //     }
        // }
        // w[k] = now_w;
        // last_w = now_w;
    // }
    show(w);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (f[i][j] == '=' && w[i] != w[j + n] ||
                f[i][j] == '<' && w[i] >= w[j + n] ||
                f[i][j] == '>' && w[i] <= w[j + n]) {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        cout << w[i] << ' ';
    }
    cout << '\n';
    for (int i = n; i < n + m; ++i) {
        cout << w[i] << ' ';
    }
    cout << '\n';
    // g.resize(color);
    // for (int i = 0; i < color; ++i) {
    //     for (int j = 0; j < color; ++j) {
    //         int v = equals[i][0];
    //         int u = equals[j][0];
    //         if (v < n && u < n) {
    //             if (f[i][j] == '<')
    //                 g[j].push_back(i);
    //             else
    //                 g[i].push_back(j);
    //         } else if (v < n) {
    //         }
    //     }
    // }
    return 0;
}