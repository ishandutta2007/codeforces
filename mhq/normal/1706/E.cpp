#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, m, q;
const int maxN = 2e5 + 10;
int u[maxN], v[maxN];
int l[maxN], r[maxN];
int le[maxN];
int ri[maxN];
vector<int> ask[maxN];
vector<int> vals[maxN];
int when[maxN];
int id[maxN];
const int LOG = 20;
int up[LOG][maxN];
int lg[maxN];
int get_min(int l, int r) {
    if (l > r) return 0;
    int k = lg[r - l + 1];
    return max(up[k][l], up[k][r - (1 << k) + 1]);
}
void solve() {
    cin >> n >> m >> q;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i - 1];
        if (!(i & (i - 1))) lg[i]++;
    }
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) vals[i].clear();
    for (int i = 1; i <= n; i++) {
        vals[i].emplace_back(i);
        id[i] = i;
    }
    for (int i = 1; i < n; i++) {
        when[i] = m + 1;
    }
    for (int i = 1; i <= m; i++) {
        int x = id[u[i]];
        int y = id[v[i]];
        if (x == y) continue;
        if (vals[x].size() > vals[y].size()) swap(x, y);
        for (int p : vals[x]) {
            vals[y].emplace_back(p);
            id[p] = y;
            if (p > 1 && id[p] == id[p - 1]) {
                when[p - 1] = min(when[p - 1], i);
            }
            if (p + 1 <= n && id[p] == id[p + 1]) {
                when[p] = min(when[p], i);
            }
        }
        vals[x].clear();
    }
    for (int i = 1; i < n; i++) {
        up[0][i] = when[i];
    }
    for (int k = 0; k + 1 < LOG; k++) {
        for (int i = 1; i + (1 << (k + 1)) - 1 <= n; i++) {
            up[k + 1][i] = max(up[k][i], up[k][i + (1 << k)]);
        }
    }
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        cout << get_min(l, r - 1) << " ";
    }
    cout << '\n';

//    for (int i = 1; i <= q; i++) {
//        cin >> l[i] >> r[i];
//        le[i] = 0;
//        ri[i] = m;
//    }
//    for (int iter = 0; iter < 20; iter++) {
//        for (int i = 1; i <= m; i++) {
//            ask[i].clear();
//        }
//        for (int i = 1; i <= q; i++) {
//            if (ri[i] - le[i] > 1) {
//                int f = (le[i] + ri[i]) / 2;
//                ask[f].emplace_back(i);
//            }
//        }
//    }



}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}