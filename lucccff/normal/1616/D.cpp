#include <bits/stdc++.h>
using namespace std;

int dp[8], b[8], a[50010];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t, k;
    cin >> t;
    while(t--) {
        cin >> n;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) cin >> a[i];
        cin >> k;
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        else if (n == 2) {
            if (a[0] + a[1] >= 2 * k) {
                cout << 2 << endl;
            }
            else {
                cout << 1 << endl;
            }
            continue;
        }
        for(int i = 0; i < 8; i++) {
            dp[0] = 0;
            dp[1] = dp[2] = dp[4] = 1;
            dp[5] = 2;
            if (a[0] + a[1] >= 2 * k) dp[3] = 2;
            else dp[3] = 0;
            if (a[1] + a[2] >= 2 * k) dp[6] = 2;
            else dp[6] = 0;
            if (a[0] + a[1] >= 2 * k && a[1] + a[2] >= 2 * k && a[0] + a[1] + a[2] >= 3 * k) dp[7] = 3;
            else dp[7] = 0;
        }
        for(int i = 1; i < n - 2; i++) {
            memset(b, 0, sizeof(b));
            for(int j = 0; j < 8; j++) {
                b[j >> 1] = max(b[j >> 1], dp[j]);
            }
            memset(dp, 0, sizeof(dp));
            for(int j = 0; j < 8; j++) {
                if (j == 3 && a[i] + a[i + 1] < 2 * k) dp[j] = 0;
                else if (j == 6 && a[i + 1] + a[i + 2] < 2 * k) dp[j] = 0;
                else if (j == 7 && (a[i] + a[i + 1] < 2 * k || a[i + 1] + a[i + 2] < 2 * k || a[i] + a[i + 1] + a[i + 2] < 3 * k)) dp[j] = 0;
                else dp[j] = b[j & 3] + (j >> 2);
            }
        }
        int mx = 0;
        for(int i = 0; i < 8; i++) {
            mx = max(mx, dp[i]);
        }
        cout << mx << endl;
    }
    return 0;
}