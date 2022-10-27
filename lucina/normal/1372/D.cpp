#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
using ll = long long;
int n;
ll dp[nax][3][2];
int a[nax];
ll const inf = 1e17;


int main () {
    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
    }
    for (int i = 0 ; i <= n ; ++ i) {
        for (int j = 0 ; j < 3 ; ++ j)
        for (int b = 0 ; b < 2 ; ++ b)
            dp[i][j][b] = inf;
    }

    dp[0][0][0] = 0;
    dp[1][0][1] = a[1];
    dp[2][1][0] = a[2];

    for (int i = 3 ; i <= n ; ++ i) {
        for (int b = 0 ; b < 2 ; ++ b) {
            if (b && i == n) continue;
            dp[i][0][b] = min(dp[i][0][b], dp[i - 2][0][b] + a[i]);
            dp[i][1][b] = min(dp[i][1][b], dp[i - 2][1][b] + a[i]);
            dp[i][2][b] = min(dp[i][2][b], dp[i - 2][2][b] + a[i]);

            if (i >= 3) dp[i][1][b] = min(dp[i][1][b], dp[i - 3][0][b] + a[i]);
            if (i >= 4) dp[i][2][b] = min(dp[i][2][b], dp[i - 4][0][b] + a[i]);
            if (i >= 3) dp[i][2][b] = min(dp[i][2][b], dp[i - 3][1][b] + a[i]);

        }
    }

    ll ans = inf;
    for (int l = 0 ; l < 2 ; ++ l)
    ans = min(ans, min({dp[n - 2][0][l], dp[n - 1][1][l], dp[n][2][l], dp[n][1][l]}));

    printf("%lld\n", accumulate(a + 1, a + 1 + n, 0LL) - ans);

}
/*
    Firis is not airhead!
*/