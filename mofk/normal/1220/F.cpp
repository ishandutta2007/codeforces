#include <bits/stdc++.h>
 
using namespace std;
 
int n;
int p[200005];
int q[200005];
int mn[200005][20];
int lg[200005];
 
int rmq(int l, int r) {
    int k = lg[r - l + 1];
    int x = mn[l][k], y = mn[r - (1<<k) + 1][k];
    if (q[x] < q[y]) return x;
    return y;
}
 
int cal(int l, int r) {
    if (l > r) return 0;
    int k = rmq(l, r);
    return max(cal(l, k - 1), cal(k + 1, r)) + 1;
}
 
int eval(int x) {
    return 1 + max(cal(2, x + 1), cal(x + 2, n));
}
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    int piv;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        if (p[i] == 1) piv = i;
    }
    for (int i = 2; i <= n; ++i) lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= n; ++i) q[i] = p[(i + piv - 2 + n) % n + 1];
    for (int i = 1; i <= n; ++i) mn[i][0] = i;
    for (int j = 1; j < 20; ++j) for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
        int x = mn[i][j-1], y = mn[i + (1<<j-1)][j-1];
        if (q[x] < q[y]) mn[i][j] = x; else mn[i][j] = y;
    }
    int l = 0, r = n - 1;
    while (l < r) {
        int m = l + r >> 1;
        int le = cal(2, m + 1), ri = cal(m + 2, n);
        if (le < ri) l = m + 1; else r = m;
    }
    int ans = eval(l), best = l;
    if (l > 0) {
        int ans2 = eval(l - 1);
        if (ans > ans2) ans = ans2, best = l - 1;
    }
    best = (best + piv) % n;
    cout << ans << ' ' << best << endl;
    return 0;
}