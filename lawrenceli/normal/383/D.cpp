#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int MAXN = 1005;
const int MAXA = 10100;
const int MOD = 1e9 + 7;

int n, a[MAXN], dp[2*MAXA][2], ans;

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    dp[MAXA][0] = 1;

    for (int i=0; i<n; i++) {
        for (int j=0; j<2*MAXA; j++) {
            int k = j - a[i];
            if (k >= 0) dp[k][1] = (dp[k][1] + dp[j][0]) % MOD;

            k = j + a[i];
            if (k < 2*MAXA) dp[k][1] = (dp[k][1] + dp[j][0]) % MOD;
        }

        ans = (ans + dp[MAXA][1]) % MOD;

        for (int j=0; j<2*MAXA; j++) {
            dp[j][0] = dp[j][1];
            dp[j][1] = 0;
        }

        dp[MAXA][0] ++;
    }

    cout << ans << '\n';
    return 0;
}