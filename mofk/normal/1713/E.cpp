#include<bits/stdc++.h>

using namespace std;

struct dsu {
    int n;
    vector<int> dad;
    vector<int> up;
    dsu(int _n) {
        n = _n;
        up.assign(n, 0);
        dad.assign(n, 0);
        iota(dad.begin(), dad.end(), 0);
    }
    int anc(int u) {
        int v = dad[u];
        if (v == u) return u;
        int p = anc(v);
        dad[u] = p;
        up[u] ^= up[v];
        return p;
    }
    bool join(int u, int v, int w) {
        int pu = anc(u);
        int pv = anc(v);
        if (pu == pv) return false;
        dad[pv] = pu;
        up[pv] = up[u] ^ up[v] ^ w;
        return true;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        dsu d(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i][j] < a[j][i]) d.join(i, j, 0);
                if (a[i][j] > a[j][i]) d.join(i, j, 1);
            }
        }
        for (int i = 0; i < n; ++i) {
            d.anc(i);
            if (d.up[i]) {
                for (int j = 0; j < n; ++j) swap(a[i][j], a[j][i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}