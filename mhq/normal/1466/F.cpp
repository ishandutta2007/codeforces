#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 5e5 + 10;
const int mod = (int) 1e9 + 7;

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

struct dsu {
    vector<int> p;
    vector<int> sz;
    vector<bool> hs;

    dsu(int n) {
        p.resize(n);
        sz.resize(n, 1);
        hs.resize(n, false);
        iota(p.begin(), p.end(), 0);
    }

    int find(int a) {
        if (a == p[a]) return a;
        return p[a] = find(p[a]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        p[b] = a;
        if (hs[b]) hs[a] = true;
        return true;
    }

    bool are_connected(int a, int b) {
        return find(a) == find(b);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    vector<int> ans;
    int n, m;
    cin >> n >> m;
    int coef = 1;
    dsu ds(m);
    int lst_single = -1;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        if (k == 1) {
            int c;
            cin >> c;
            c--;
            if (ds.hs[ds.find(c)]) {
                continue;
            }
            ds.hs[ds.find(c)] = true;
            if (lst_single != -1) {
                ds.unite(lst_single, c);
            }
            lst_single = c;
            ans.emplace_back(i);
            coef = mult(coef, 2);
        } else {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            if (ds.are_connected(u, v)) continue;
            ds.unite(u, v);
            ans.emplace_back(i);
            coef = mult(coef, 2);
        }
    }
    cout << coef << " " << ans.size() << '\n';
    for (int v : ans) cout << v << " ";
    cout << '\n';
    return 0;
}