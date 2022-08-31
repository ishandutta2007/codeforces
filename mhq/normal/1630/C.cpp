#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int a[maxN];

int n;
int frst[maxN], lst[maxN];
int dp[maxN];
int t[4 * maxN];
void upd(int v, int tl, int tr, int pos, int by) {
    if (tl == tr) {
        t[v] = by;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) upd(2 * v, tl, tm, pos, by);
    else upd(2 * v + 1, tm + 1, tr, pos, by);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}
const int INF = 1e9;
int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return -INF;
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm +1 , tr, l, r));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= 4 * n; i++) {
        t[i] = -INF;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (frst[a[i]] == 0) {
            frst[a[i]] = i;
        }
        lst[a[i]] = i;
    }
    vector<pair<int,int>> segs;
    int ans = 0;
    int cur_r = 0;
    int nxt_r = 0;
    for (int i = 1; i <= n; i++) {
        if (frst[a[i]] == i && frst[a[i]] != lst[a[i]]) {
            int to = lst[a[i]];
            if (i > cur_r) {
                cur_r = to;
                ans += (to - i + 1) - 2;
            }
            else {
                nxt_r = max(nxt_r, to);

            }
        }
        if (i == cur_r) {
            if (nxt_r > cur_r) {
                ans += nxt_r - cur_r - 1;
                cur_r = nxt_r;
            }
        }
    }
    cout << ans << '\n';
    /*for (int i = 1; i <= n; i++) {
        if (lst[a[i]] != i)  continue;
        int from = frst[a[i]];
        if (from == i) continue;
        dp[i] = -INF;
        dp[i] = i - from + 1 - 2;
        if (i < from) {
            dp[]
        }
    }*/

    return 0;
}