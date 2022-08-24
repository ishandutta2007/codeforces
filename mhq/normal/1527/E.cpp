#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define set sgsgsgsg
const int maxN = 35 * 1000 + 10;
ll t[4 * maxN];
ll lazy[4 * maxN];
void upd(int v, ll by) {
    t[v] += by;
    lazy[v] += by;
}
void merge(int v) {
    t[v] = min(t[2 * v], t[2 * v + 1]);
}
void push(int v, int tl, int tr) {
    if (tl != tr && lazy[v]) {
        upd(2 * v, lazy[v]);
        upd(2 * v + 1, lazy[v]);
    }
    lazy[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, ll by) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        upd(v, by);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, l, r, by);
    upd(2 * v + 1, tm + 1, tr, l, r, by);
    merge(v);
}
const ll INF = 1e16;
void set(int v, int tl, int tr, int pos, ll to) {
    if (tl == tr) {
        t[v] = to;
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    if (pos <= tm) set(2 * v, tl, tm, pos, to);
    else set(2 * v + 1, tm + 1, tr, pos, to);
    merge(v);

}
ll dp[maxN];
int lst[maxN];
ll ndp[maxN];
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) dp[i] = INF;
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        for (int i = 0; i < 4 * maxN; i++) {
            t[i] = INF;
            lazy[i] = 0;
        }
        for (int i = 0; i <= n; i++) ndp[i] = INF;
        memset(lst, -1, sizeof lst);
        for (int r = 1; r <= n; r++) {
            set(1, 0, n - 1, r - 1, dp[r - 1]);
            if (lst[a[r]] != -1) {
                upd(1, 0, n - 1, 0, lst[a[r]] - 1, r - lst[a[r]]);
            }
            lst[a[r]] = r;
            ndp[r] = t[1];
        }
        for (int r = 0; r <= n; r++) {
            dp[r] = ndp[r];
        }
    }
    cout << dp[n] << '\n';
    return 0;
}