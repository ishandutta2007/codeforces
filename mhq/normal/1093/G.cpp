#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 2 * (int)1e5 + 10;
const int maxK = 6;
int n, k;
int a[maxN][maxK];
int t[4 * maxN][1 << maxK];
void build(int v, int tl, int tr, int mask) {
    if (tl == tr) {
        for (int bit = 0; bit < k; bit++) {
            if (mask & (1 << bit)) t[v][mask] += a[tl][bit];
            else t[v][mask] -= a[tl][bit];
        }
        return ;
    }
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm, mask);
    build(v + v + 1, tm + 1, tr, mask);
    t[v][mask] = max(t[v + v][mask], t[v + v + 1][mask]);
}
void upd(int v, int tl, int tr, int pos, int mask) {
    if (tl == tr) {
        t[v][mask] = 0;
        for (int bit = 0; bit < k; bit++) {
            if (mask & (1 << bit)) t[v][mask] += a[tl][bit];
            else t[v][mask] -= a[tl][bit];
        }
        return ;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) upd(v + v, tl, tm, pos, mask);
    else upd(v + v + 1, tm + 1, tr, pos, mask);
    t[v][mask] = max(t[v + v][mask], t[v + v + 1][mask]);
}
int val[1 << maxK];
int get(int v, int tl, int tr, int l, int r, int mask) {
    if (l == tl && r == tr) return t[v][mask];
    int tm = (tl + tr) / 2;
    if (r <= tm) return get(v + v, tl, tm, l, r, mask);
    else if (l > tm) return get(v + v + 1, tm + 1, tr, l, r, mask);
    else return max(get(v + v, tl, tm, l, tm, mask), get(v + v + 1, tm + 1, tr, tm + 1, r, mask));
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
    }
    for (int mask = 0; mask < (1 << k); mask++) {
        build(1, 1, n, mask);
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int ind;
            cin >> ind;
            for (int j = 0; j < k; j++) cin >> a[ind][j];
            for (int mask = 0; mask < (1 << k); mask++) upd(1, 1, n, ind, mask);
        }
        else {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            for (int mask = 0; 2 * mask <= (1 << k); mask++) {
                ans = max(ans, abs(get(1, 1, n, l, r, mask) + get(1, 1, n, l, r, mask ^ ((1 << k) - 1))));
            }
            cout << ans << '\n';
        }
    }
    return 0;
}