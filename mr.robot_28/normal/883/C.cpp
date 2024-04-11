#include<bits/stdc++.h>

using namespace std;

#define int long long
int inf = 1e18;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int f, T, t0, a1, t1, p1, a2, t2, p2;
    cin >> f >> T >> t0 >> a1 >> t1 >> p1 >> a2 >> t2 >> p2;
    int ans = inf;
    for (int cnt = 0; cnt <= f && cnt * t1 <= T; ++cnt) {
        int cost = (cnt + a1 - 1) / a1 * p1;
        int tt = T - cnt * t1;
        int ff = f - cnt;
        if (t0 <= t2) {
            if (tt / t0 >= ff) ans = min(ans, cost);
        } else {
            int cnt2 = max(0ll, (-tt + ff * t0 + t0 - t2 - 1) / (t0 - t2));
            if (cnt2 > ff) continue;
            ans = min(ans, cost + (cnt2 + a2 - 1) / a2 * p2);
        }
    }
    if (ans > inf / 2) ans = -1;
    cout << ans;
    return 0;
}