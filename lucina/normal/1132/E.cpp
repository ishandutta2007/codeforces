#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void upd_max (ll &x, ll y) {
    x = max(x, y);
}
const int L = 840;
ll dp[10][L * 8];
ll w;
/**
    maximum number of bag of size 840
    and the rest sum up equal to j
*/

int main () {
    scanf("%lld", &w);

    for (int i = 0 ; i <= 8 ; ++ i)
    for (int j = 0 ; j < L * 8 ; ++ j)
        dp[i][j] = -1;
    dp[0][0] = 0;

    /**
        for each weight
        you have no need to put more than L / i into trash can
        and the sum of all trash is at most 840 * 8 = 6720
    */
    for (int i = 0 ; i < 8 ; ++ i) {
        ll cnt;
        scanf("%lld", &cnt);
        for (int j = 0 ; j < L * 8 ; ++ j) {
            if (dp[i][j] == -1) continue;
            int has = L / (i + 1); 
            if (has > cnt) has = cnt;

            for (int k = 0 ; k <= has ; ++ k) {
                upd_max(dp[i + 1][j + k * (i + 1)], dp[i][j] + (cnt - k) * (i + 1) / L);
            }
        }
    }

    ll ans = 0;

    for (int i = 0 ; i < L * 8 ; ++ i) {
        if (dp[8][i] == -1 || i > w) continue;
        upd_max(ans, i + min((w - i) / L, dp[8][i]) * L); /// cannot be more than (w - i) / L bags
    }

    printf("%lld\n", ans);
}