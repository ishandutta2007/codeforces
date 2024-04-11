#include<bits/stdc++.h>
using namespace std;
int const nax = 128;
const int mod = 998244353;

int add (int a, int b) {
    return ((a += b) >= mod) ? a -= mod : a;
}

int sub (int a, int b) {
    return ((a -= b) < 0) ? a + mod : a;
}
int mul (int a, int b) {
    return 1LL * a * b % mod;
}

int power (int a, long long b) {
    int res = 1;
    for (; b > 0 ; b >>= 1, a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res;
}

int a[nax];
int b[nax];
int n;
int dp[nax][nax];
int com[nax];
int topCom;
int s[nax];
int e[nax]; /// start and ends
int inv[nax];
int tot = 1;

/**
    little modification from boat.cpp
*/

int main () {
    scanf("%d", &n);

    for (int i = n ; i >= 1 ; -- i) {
        scanf("%d %d", a + i, b + i);
        ++ b[i];
        com[++topCom] = a[i];
        com[++topCom] = b[i];

        tot = mul(tot, b[i] - a[i]);
    }

    sort(com + 1, com + topCom + 1);
    int m = unique(com + 1, com + topCom + 1) - com - 1;


    for (int i = 1 ; i <= n ; ++ i) {
        s[i] = lower_bound(com + 1, com + m + 1, a[i]) - com;
        e[i] = lower_bound(com + 1, com + m + 1, b[i]) - com;
     //   printf("%d %d\n", s[i], e[i]);
    }

    for (int i = 1 ; i < nax ; ++ i)
        inv[i] = power(i, mod - 2);

    dp[0][0] = 1;

    for (int i = 1 ; i < m ; ++ i) {
        dp[i][0] = 1;
        for (int t = 1 ; t <= n ; ++ t) {

            dp[i][t] = dp[i - 1][t];
            int k = 1;
            /**
            w + k choose k;
            */

            if (!(s[t] <= i && e[t] > i)) continue;
            int cur = com[i + 1] - com[i];
            int w = cur;

            for (int from = t - 1 ; from >= 0 ; -- from) {
                dp[i][t] = add(dp[i][t], mul(cur, dp[i - 1][from]));
                if (s[from] <= i && e[from] > i) {
                    cur = mul(cur, (w + k) % mod);
                    cur = mul(cur, inv[k + 1]);
                    ++ k;
                } else break;
            }
        }
    }
/*
    for (int i = 1 ; i < m ; ++ i, puts(""))
    for (int j = 1 ; j <= n ; ++ j)
        printf("%d ", dp[i][j]);
    wonder whoever in the world would define inversion like this...
*/
    printf("%d\n", mul(power(tot, mod - 2),dp[m - 1][n]));
}
/*
    Good Luck
        -Lucina
*/