/*
    08.03.2019 12:53:27
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
const int mxn = 10;
const int mxd = 10;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
const int mxn = 100005;
const int mxd = 52;
#endif

int n, m, d;
vector< vector< int > > g;
vector< vector< int > > gr;
vector< vector< int > > comps;
vector< string > vs;
vector< bool > u;
vector< int > per;
vector< int > col;
vector< int > col1;
vector< bool > uc;
int color = 0;
int now_c;
array< array< int, mxd >, mxn > mxin, mx, mxout;
vector< int > order, component;
 
void dfs1(int v) {
    u[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i)
        if (!u[g[v][i]])
            dfs1(g[v][i]);
    order.push_back(v);
}
 
void dfs2(int v) {
    u[v] = true;
    component.push_back(v);
    for (size_t i = 0; i < gr[v].size(); ++i)
        if (!u[gr[v][i]])
            dfs2(gr[v][i]);
}

void dfs3(int v, int cc) {
    u[v] = true;
    col1[v] = cc;
    for (auto k : g[v]) {
        if (col[k] != col[v]) continue;
        if (!u[k]) dfs3(k, cc + 1);
        else {
            int t = abs(col1[k] - col1[v] - 1);
            if (t != 0) per[now_c] = __gcd(per[now_c], t);
        }
    }
}

// void dfs(int v) {
//     u[v] = true;
//     for (int i = 0; i < d; ++i) {
//         mx[v][i] = 0;
//     }
//     for (auto k : g[v]) {
//         if (!u[k]) dfs(k);
//         for (int i = 0; i < d; ++i) {
//             mx[v][i] = max(mx[v][i], mx[k][(i + 1) % d]);
//         }
//     }
//     for (int i = 0; i < d; ++i) {
//         mx[v][i] += (vs[v][i] == '1');
//     }
// }

void dfsc(int cl) {
    uc[cl] = true;
    for (auto v : comps[cl]) {
        for (int j = 0; j < d; ++j) {
            mxout[v][j] = 0;
            for (auto k : g[v]) {
                if (col[v] != col[k]) {
                    if (!uc[col[k]]) {
                        dfsc(col[k]);
                    }
                    mxout[v][j] = max(mxout[v][j], mx[k][(j + 1) % d]);
                }
            }
        }
        for (int i = 0; i < per[cl]; ++i) {
            for (int j = 0; j < d / per[cl]; ++j) {
                mxout[v][i] = max(mxout[v][i], mxout[v][i + j * per[cl]]);
            }
            for (int j = 0; j < d / per[cl]; ++j) {
                mxout[v][j * per[cl] + i] = mxout[v][i];
            }
        }
    }
    int v = comps[cl][0];
    for (int j = 0; j < d; ++j) {
        mx[v][j] = 0;
        for (auto v1 : comps[cl]) {
            mx[v][j] = max(mx[v][j], mxout[v1][(j + col1[v1] - col1[v] + d) % d]);
        }
        mx[v][j] += mxin[v][j];
        for (int i = 0; i < per[cl]; ++i) {
            for (int k = 0; k < d / per[cl]; ++k) {
                mx[v][i] = max(mx[v][i], mx[v][i + k * per[cl]]);
            }
            for (int k = 0; k < d / per[cl]; ++k) {
                mx[v][k * per[cl] + i] = mx[v][i];
            }
        }
    }
    for (auto v1 : comps[cl]) {
        for (int j = 0; j < d; ++j) {
            mx[v1][j] = mx[v][(j + col1[v] - col1[v1] + d) % d];
        }
        for (int i = 0; i < per[cl]; ++i) {
            for (int j = 0; j < d / per[cl]; ++j) {
                mx[v1][i] = max(mx[v1][i], mx[v1][i + j * per[cl]]);
            }
            for (int j = 0; j < d / per[cl]; ++j) {
                mx[v1][j * per[cl] + i] = mx[v1][i];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m >> d;
    g.resize(n);
    gr.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    vs.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> vs[i];
    }
    u.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!u[i]) {
            dfs1(i);
        }
    }
    u.assign(n, false);
    col.resize(n);
    for (int i = 0; i < n; ++i) {
        int v = order[n - 1 - i];
        if (!u[v]) {
            dfs2(v);
            for (auto item : component) {
                col[item] = color;
            }
            ++color;
            comps.push_back(component);
            component.clear();
        }
    }
    u.assign(n, false);
    per.assign(color, d);
    col1.assign(n, -1);
    show(comps);
    for (int i = 0; i < color; ++i) {
        now_c = i;
        dfs3(comps[i][0], 0);
    }
    show(per);
    show(col1);
    for (int i = 0; i < n; ++i) {
        int pr = per[col[i]];
        for (int j = 0; j < pr; ++j) {
            for (int k = 0; k < d / pr; ++k) {
                if (vs[i][j] == '1' || vs[i][j + k * pr] == '1') vs[i][j] = '1';
            }
            for (int k = 0; k < d / pr; ++k) {
                vs[i][j + k * pr] = vs[i][j];
            }
        }
    }
    show(vs);
    for (int i = color - 1; i >= 0; --i) {
        int v = comps[i][0];
        for (int j = 0; j < d; ++j) {
            mxin[v][j] = 0;
            for (auto v1 : comps[i]) {
                mxin[v][j] += vs[v1][(col1[v1] - col1[v] + d + j) % d] == '1';
            }
        }
        for (int j = 1; j < comps[i].size(); ++j) {
            int v1 = comps[i][j];
            for (int k = 0; k < d; ++k) {
                mxin[v1][k] = mxin[v][(k + col1[v] - col1[v1] + d) % d];
            }
        }
    }
    uc.assign(color, false);
    for (int i = 0; i < color; ++i) {
        if (!uc[i]) {
            dfsc(i);
        }
    }
    // for (int i = color - 1; i >= 0; --i) {
    //     for (auto v : comps[i]) {
    //         for (int j = 0; j < d; ++j) {
    //             mxout[v][j] = 0;
    //             for (auto k : g[v]) {
    //                 if (col[v] != col[k])
    //                     mxout[v][j] = max(mxout[v][j], mx[k][(j + 1) % d]);
    //             }
    //         }
    //     }
    //     int v = comps[i][0];
    //     for (int j = 0; j < d; ++j) {
    //         mx[v][j] = 0;
    //         for (auto v1 : comps[i]) {
    //             mx[v][j] = max(mx[v][j], mxout[v1][(j + col1[v1] - col1[v] + d) % d]);
    //         }
    //         mx[v][j] += mxin[v][j];
    //     }
    //     for (auto v1 : comps[i]) {
    //         for (int j = 0; j < d; ++j) {
    //             mx[v1][j] = mx[v][(j + col1[v] - col1[v1] + d) % d];
    //         }
    //     }
    // }
    cout << mx[0][0] << '\n';
    // show(mxin);
    // int ans = -1;
    // for (int i = 0; i < n; ++i) {
    //     ans = max(ans, mx[i][0]);
    // }
    // cout << ans << '\n';
    return 0;
}