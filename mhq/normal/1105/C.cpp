#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
int cnt[3];
const int maxN = 2 * (int)1e5 + 100;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int n, l, r;
int dp[maxN][3];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> l >> r;
    if (r - l <= 10) {
        for (int j = l; j <= r; j++) {
            cnt[j % 3]++;
        }
    }
    else {
        while (((l % 3) != 0)) {
            cnt[l % 3]++;
            l++;
        }
        while (((r % 3)) != 0) {
            cnt[r % 3]++;
            r--;
        }
        cnt[l % 3]++;
        for (int k = 0; k < 3; k++) {
            cnt[k] += (r - l + 1) / 3;
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i + 1 <= n; i++) {
        for (int res = 0; res < 3; res++) {
            for (int val = 0; val  < 3; val++) {
                dp[i + 1][(res + val) % 3] = sum(dp[i + 1][(res + val) % 3], mult(cnt[val], dp[i][res]));
            }
        }
    }
    cout << dp[n][0];
    return 0;
}