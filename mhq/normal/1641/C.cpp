#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int n, q;
const int LOG = 20;
int tp[maxN];
int val[maxN];
int l[maxN];
int r[maxN];
int mn[LOG][maxN];
int lg[maxN];
void do_min(int l, int r, int v) {
    int k = lg[r - l + 1];
    mn[k][l] = min(mn[k][l], v);
    mn[k][r - (1 << k) + 1] = min(mn[k][r - (1 << k) + 1], v);
}
pair<int,int> t[4 * maxN];
int when[maxN];
pair<int,int> merge(pair<int,int> a, pair<int,int> b) {
    if (a.first == -1) return b;
    if (b.first == -1) return a;
    if (when[a.first] < when[b.first]) swap(a, b);
    if (a.second == -1 || (when[a.second] < when[b.first])) return {a.first, b.first};
    else return a;
}
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = {tl, -1};
    }
    else {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
}
pair<int,int> get(int v, int tl, int tr, int l, int r) {
    if (tr < l || tl > r) return {-1, -1};
    if (l <=  tl && tr <= r) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return merge(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}
int from[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i - 1];
        if (!(i & (i - 1))) lg[i]++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < LOG; j++) {
            mn[j][i] = q + 5;
        }
    }
    mn[0][n + 1] = q + 5;
    for (int i = 1; i <= q; i++) {
        cin >> tp[i];
        if (tp[i] == 0) {
            cin >> l[i] >> r[i] >> val[i];
        }
        else {
            cin >> val[i];
        }
    }
    for (int i = 1; i <= q; i++) {
        if (tp[i] == 0 && val[i] == 0) {
            do_min(l[i], r[i], i);
        }
    }
    for (int z = LOG - 1; z > 0; z--) {
        for (int i = 1; i + (1 << z) - 1 <= n; i++) {
            mn[z - 1][i] = min(mn[z - 1][i], mn[z][i]);
            mn[z - 1][i + (1 << (z - 1))] = min(mn[z - 1][i + (1 << (z - 1))], mn[z][i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        when[i] = mn[0][i];
        from[i] = q + 5;
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        if (tp[i] == 0 && val[i] == 1) {
            auto it = get(1, 1, n, l[i], r[i]);
            if (it.second == -1) {
                assert(l[i] == r[i]);
                from[l[i]] = min(from[l[i]], i);
            }
            else {
                from[it.first] = min(from[it.first], max(i, when[it.second]));
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        if (tp[i] == 1) {
            if (when[val[i]] <= i) {
                cout << "NO\n";
            }
            else if (from[val[i]] <= i) {
                cout << "YES\n";
            }
            else {
                cout << "N/A" << '\n';
            }
        }
    }
    return 0;
}