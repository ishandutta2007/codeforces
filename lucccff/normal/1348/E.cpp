#include <bits/stdc++.h>
using namespace std;

int a[510], b[510];
int n, k, f;
long long s, s1, s2;
int dp[510], dp1[510];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] >= k && b[i] >= k) f = 1;
        s1 += a[i];
        s2 += b[i];
    }
    s = s1 + s2;
    if (s1 / k + s2 / k == s / k || f) {
        cout << s / k;
        return 0;
    }
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        if (a[i] >= k) {
            for(int l = 0; l < k; l++) dp1[l] = dp[l];
            for(int j = 1; j <= b[i]; j++) {
                for(int l = 0; l < j; l++) {
                    dp1[l - j + k] |= dp[l];
                }
                for(int l = j; l < k; l++) {
                    dp1[l - j] |= dp[l];
                }
            }
            for(int l = 0; l < k; l++) dp[l] = dp1[l];
        }
        else if (b[i] >= k) {
            for(int l = 0; l < k; l++) dp1[l] = dp[l];
            for(int j = 1; j <= a[i]; j++) {
                for(int l = 0; l < k - j; l++) {
                    dp1[l + j] |= dp[l];
                }
                for(int l = k - j; l < k; l++) {
                    dp1[l + j - k] |= dp[l];
                }
            }
            for(int l = 0; l < k; l++) dp[l] = dp1[l];
        }
        else {
            for(int l = 0; l < k; l++) dp1[l] = dp[l];
            for(int j = k - a[i]; j <= b[i]; j++) {
                for(int l = 0; l < j; l++) {
                    dp1[l - j + k] |= dp[l];
                }
                for(int l = j; l < k; l++) {
                    dp1[l - j] |= dp[l];
                }
            }
            for(int l = 0; l < k; l++) dp[l] = dp1[l];
        }
    }
    s1 %= k;
    s2 %= k;
    for(int j = k - s2; j <= s1; j++) {
        if (dp[j]) {
            cout << s / k;
            return 0;
        }
    }
    cout << s / k - 1;
    return 0;
}