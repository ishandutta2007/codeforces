#include <bits/stdc++.h>
using namespace std;

long long a[300010], b1, b2, ans;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long mx = 0;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(a[i], mx);
        }
        b1 = b2 = 0;
        ans = 0;
        for(int i = 0; i < n; i++) {
            b1 += (mx - a[i]) & 1;
            b2 += (mx - a[i]) >> 1;
        }
        if (b1 > b2) {
            ans = b1 * 2 - 1;
            mx++;
            b1 = b2 = 0;
            for(int i = 0; i < n; i++) {
                b1 += (mx - a[i]) & 1;
                b2 += (mx - a[i]) >> 1;
            }
            long long k = (b2 - b1) / 3;
            ans = min(ans, min((b2 - k) * 2, (b1 + 2 * (k + 1)) * 2 - 1));
        }
        else {
            long long k = (b2 - b1) / 3;
            ans = min((b2 - k) * 2, (b1 + 2 * (k + 1)) * 2 - 1);
        }
        cout << ans << endl;
    }
    return 0;
}