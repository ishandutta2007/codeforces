#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m, k;
const int maxN = 55;
const int maxK = 2 * (int)1e4 + 20;
int cnt[maxN][maxK];
ll dp[maxN][maxK];
const ll INF = 1e18;
ll pref[maxN][maxK];
ll calc[maxN][maxK];
ll lazy[4 * maxK];
ll t[4 * maxK];
void update(int v, ll by) {
    lazy[v] += by;
    t[v] += by;
}
void push(int v, int tl, int tr) {
    if (tl != tr) {
        if (lazy[v]) {
            update(2 * v, lazy[v]);
            update(2 * v + 1, lazy[v]);
        }
        lazy[v] = 0;
    }
}
void upd(int v, int tl, int tr, int l, int r, ll by) {
    if (l > r) return;
    if (l <= tl && tr <= r) {
        update(v, by);
        return;
    }
    if (r < tl || l > tr) return;
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, l, r, by);
    upd(2 * v + 1, tm + 1, tr, l, r, by);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}
ll get(int v, int tl, int tr, int l, int r) {
    if (l > r) return -INF;
    if (l <= tl && tr <= r) {
        return t[v];
    }
    if (r < tl || l > tr) return -INF;
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}
void upd_single(int v, int tl, int tr, int pos, ll val) {
    if (tl == tr) {
        t[v] = val;
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    if (pos <= tm) upd_single(2 * v, tl, tm, pos, val);
    else if (pos > tm) upd_single(2 * v + 1, tm + 1, tr, pos, val);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> cnt[i][j];
            pref[i][j] = pref[i][j - 1] + cnt[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = -INF;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j + k - 1 <= m; j++) {
            calc[i][j] = pref[i][j + k - 1] - pref[i][j - 1];
            if (i + 1 <= n) calc[i][j] += pref[i + 1][j + k - 1] - pref[i + 1][j - 1];
        }
    }
    for (int i = 1; i + k - 1 <= m; i++) dp[1][i] = calc[1][i];
    for (int i = 2; i <= n; i++) {
        ll mx = -INF;
        for (int j = 1; j + k - 1 <= m; j++) {
            if ((j - 1) - (k - 1) >= 1) {
                mx = max(mx, dp[i - 1][(j - 1) - (k - 1)]);
            }
            dp[i][j] = max(dp[i][j], calc[i][j] + mx);
        }
        mx = -INF;
        for (int j = m; j >= 1; j--) {
            if (j + k + (k - 1) <= m) {
                mx = max(mx, dp[i - 1][j + k]);
            }
            dp[i][j] = max(dp[i][j], calc[i][j] + mx);
        }
        for (int it = 1; it <= 4 * m; it++) {
            t[it] = -INF;
        }
        // OH SHIT HERE WE GO AGAIN
        for (int j = 1; j <= k; j++) {
            if (j + k - 1 <= m) {
                upd_single(1, 1, m, j, dp[i - 1][j] - (pref[i][k] - pref[i][j - 1]));
            }
        }
        for (int j = 1; j + k - 1 <= m; j++) {
            dp[i][j] = max(dp[i][j], get(1, 1, m, max(1, j - k + 1), min(m - k + 1, j + k - 1)) + calc[i][j]);
            //delete
            upd(1, 1, m, max(1, j - k + 1), j, +cnt[i][j]);
            // j + k
            if (j + k <= m) {
                upd(1, 1, m, j + 1, j + k, -cnt[i][j + k]);
            }
            if (j - k >= 1) {
                upd_single(1, 1, m, j - k + 1, -INF);
            }
            //add
            if (j + k + (k - 1) <= m) {
                upd_single(1, 1, m, j + k, dp[i - 1][j + k] - cnt[i][j + k]);
            }
        }
    }
    ll mx = -INF;
    for (int i = 1; i + k -  1 <= m; i++) mx = max(mx, dp[n][i]);
    cout << mx;
    return 0;
}