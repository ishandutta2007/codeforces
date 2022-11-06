#include<bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 3e5 + 5;

int f, T, t0;
int a1, t1, p1;
int a2, t2, p2;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> f >> T >> t0 >> a1 >> t1 >> p1 >> a2 >> t2 >> p2;
    if (t1 > t2)
        swap(a1, a2), swap(p1, p2), swap(t1, t2);
    int ans = 1e18;
    for (int cnt1 = 0; cnt1 <= 10'000'000; cnt1++) {

        ///is enough
        if (cnt1 * a1 >= f) {
            if (f * t1 <= T)
                ans = min(ans, cnt1 * p1);
            continue;
        }
        int x = f - cnt1 * a1, y = T - cnt1 * a1 * t1;

        if (y <= 0)
            continue;

        if (t2 >= t0) {
            if (x * t0 <= y)
                ans = min(ans, cnt1 * p1);
            continue;
        }

        ///will not finish using t2
        if (x * t2 > y)
            continue;

        ///finish with t0
        if (x * t0 <= y) {
            ans = min(ans, cnt1 * p1);
            continue;
        }


        int cnt2 = (x * t0 - y - 1) / (a2 * (t0 - t2)) + 1;

        int sum = cnt1 * p1 + cnt2 * p2;
        ans = min(ans, sum);
    }
    if (ans == 1e18)
        cout << -1;
    else
        cout << ans;
    return 0;
}