#include <bits/stdc++.h>

using namespace std;

int n;
long long a[1005];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    long long ans = 0;
    for (int i = 1; i < n; i += 2) {
        long long tot = 0, mn = 0;
        for (int j = i + 1; j <= n; ++j) {
            if (j % 2 == 0) {
                long long l = 1, r = a[i];
                l = max(l, 1 - tot);
                l = max(l, -mn);
                r = min(r, a[j] - tot);
                if (l <= r) ans += r - l + 1;
            }

            if (j & 1) tot += a[j]; else tot -= a[j];
            mn = min(mn, tot);
        }
    }
    cout << ans << endl;
    return 0;
}