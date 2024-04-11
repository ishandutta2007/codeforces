#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

void solve(int test_num) {
    int n;
    cin >> n;
    vector a(n, vector<int>(n));
    for (auto &v : a) {
        for (auto &x : v) cin >> x;
    }

    struct disjoin_set_union {
        vector<int> par, f;
        vector<bool> fixed;

        disjoin_set_union(int n) : par(n), f(n), fixed(n) {
            iota(all(par), 0);
        }

        int root(int v) {
            if (par[v] == v) return v;
            if (par[par[v]] == par[v]) return par[v];
            int new_root = root(par[v]);
            f[v] ^= f[par[v]];
            par[v] = new_root;
            return par[v];
        }

        int color(int v) {
            root(v);
            return par[v] == v ? f[v] : (f[v] ^ f[par[v]]);
        }

        void set_color(int v, int c) {
            int v_root = root(v);
            assert(!fixed[v_root]);
            f[v_root] ^= c ^ color(v);
            fixed[v_root] = true;
        }

        void unite(int v, int u, int c) {
            int v_root = root(v), u_root = root(u);
            assert(v_root != u_root);
            assert(!fixed[v_root] && !fixed[u_root]);
            c ^= color(v) ^ color(u);
            par[u_root] = v_root;
            f[u_root] ^= c;
        }
    } dsu(n);

    vector<int> know(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << a[i][j];
            } else {
                int i_root = dsu.root(i), j_root = dsu.root(j);
                if (dsu.fixed[i_root] && dsu.fixed[j_root]) {
                    int parity = dsu.color(i) ^ dsu.color(j);
                    cout << (parity ? a[j][i] : a[i][j]);
                } else {
                    if (dsu.root(i) == dsu.root(j)) {
                        int parity = dsu.color(i) ^ dsu.color(j);
                        cout << (parity ? a[j][i] : a[i][j]);
                    } else {
                        cout << min(a[i][j], a[j][i]);
                        if (dsu.fixed[i_root]) {
                            if (a[j][i] < a[i][j]) {
                                dsu.set_color(j, 1 ^ dsu.color(i));
                            } else if (a[i][j] < a[j][i]) {
                                dsu.set_color(j, dsu.color(i));
                            }
                        } else if (dsu.fixed[j_root]) {
                            if (a[j][i] < a[i][j]) {
                                dsu.set_color(i, 1 ^ dsu.color(j));
                            } else if (a[i][j] < a[j][i]) {
                                dsu.set_color(i, dsu.color(j));
                            }
                        } else {
                            if (a[j][i] < a[i][j]) {
                                dsu.unite(i, j, 1);
                            } else if (a[i][j] < a[j][i]) {
                                dsu.unite(i, j, 0);
                            }
                        }
                    }
                }
            }
            cout << " \n"[j == n - 1];
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}