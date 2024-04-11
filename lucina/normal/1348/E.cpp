#include<bits/stdc++.h>
using namespace std;
int n, k;
bool dp[512][512];

int main () {
    scanf("%d %d", &n, &k);

    dp[0][0] = true;

    /// you don't need to care about blueberry at all

    long long sum = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        int a, b;

        scanf("%d %d", &a, &b);
        sum += a + b;

        const int iter = min(a, k - 1);

        for (int j = 0 ; j < k ; ++ j) {

            dp[i][j] |= dp[i - 1][(j - a % k + k) % k];
            for (int l = 0 ; l <= iter ; ++ l) {

                if ((a - l) % k + b >= k)
                dp[i][j] |= dp[i - 1][(j - l + k) % k];

                /// you can always do this
            }
        }
    }

    for (int i = 0 ; i < k ; ++ i) {
        if (dp[n][i]) {
            return !printf("%lld\n", (sum - i) / k);
        }
    }

    assert(false);
}