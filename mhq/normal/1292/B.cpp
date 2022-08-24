#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define y0 gsjdlgskdg
ll x[65], y[65];
ll dist(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}
ll x0, y0, ax, ay, bx, by, xs, ys;
ll t;
ll dp[2][65][65];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> x[0] >> y[0] >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    int lst = -1;
    for (int i = 1; ; i++) {
        x[i] = ax * x[i - 1] + bx;
        y[i] = ay * y[i - 1] + by;
        if (x[i] >= xs && x[i] - xs > t) {
            lst = i - 1;
            break;
        }
        if (y[i] >= ys && y[i] - ys > t) {
            lst = i - 1;
            break;
        }
    }
    int sz = lst + 1;
    bool hs = false;
    const ll INF = 1e18;
    for (int i = 0; i < sz; i++) {
        for (int j = i; j < sz; j++) {
            dp[0][i][j] = dp[1][i][j] = INF;
        }
        dp[0][i][i] = dp[1][i][i] = abs(x[i] - xs) + abs(y[i] - ys);
    }
    int best = 0;
    for (int len = 1; len <= sz; len++) {
        for (int l = 0; l + len - 1 < sz; l++) {
            int r = l + len - 1;
            if (dp[0][l][r] > t && dp[1][l][r] > t) continue;
            best = max(best, r - l + 1);
            dp[1][l][r] = min(dp[1][l][r], dp[0][l][r] + dist(l, r));
            dp[0][l][r] = min(dp[0][l][r], dp[1][l][r] + dist(l, r));
            if (l) {
                dp[0][l - 1][r] = min(dp[0][l - 1][r], dp[0][l][r] + dist(l - 1, l));
            }
            if (r + 1 < sz) {
                dp[1][l][r + 1] = min(dp[1][l][r + 1], dp[1][l][r] + dist(r, r + 1));
            }
        }
    }
    cout << best;
    return 0;
}