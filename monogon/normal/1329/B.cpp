
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// 1 <= a1 < a2 < a3 < ... < an <= d
// 1 <= a1 < (a1 ^ a2) < (a1 ^ a2 ^ a3) < ... < (a1 ^ ... ^ an)
// <=> each ai has a higher MSB than the previous
// For example:

//position:
// 4 3 2 1 0

// 1 x x x x 
// . . 1 x x
// . . . . 1

// Let dp[n][k] = answer for n, if d = 2^k ?
// dp[n][k] = (min(d, 2^{k+1}) - 2^k) dp[n - 1][k - 1] + dp[n][k - 1]
// answer is sum_n dp[n][log2(d)]
// dp[0][x] = 1
// for n > k + 1, dp = 0

// n, k <= log2(d) <= 30

// d = 3:
// [1], [2], [3], []

const int K = 40;
int t;
ll d, m, pow2[K], dp[K][K];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> d >> m;
        pow2[0] = 1;
        for(int i = 1; i < K; i++) {
            pow2[i] = (2 * pow2[i - 1]) % m;
        }
        int kk = floor(log2(d));
        ll ans = -1;
        for(int n = 0; n <= kk + 1; n++) {
            for(int k = 0; k <= kk; k++) {
                if(n > k + 1) dp[n][k] = 0;
                else if(n == 0 || k == 0) dp[n][k] = 1;
                else {
                    dp[n][k] = (k == kk ? d - pow2[k] + 1 : pow2[k]) * dp[n - 1][k - 1] + dp[n][k - 1];
                    dp[n][k] = ((dp[n][k] % m) + m) % m;
                }
            }
            ans = (ans + dp[n][kk]) % m;
        }
        cout << ans << '\n';
    }
}