#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 2005;
const int MOD = 1e9 + 7;

int n, a[MAXN], dp[MAXN][2][2], fact[MAXN], num, tot, ret;
bool b[MAXN];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) b[i] = 1;
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
        if (a[i]>=0) b[a[i]] = 0;
    }
    fact[0] = 1;
    for (int i=1; i<=n; i++) fact[i] = ll(fact[i-1]) * i % MOD;
    for (int i=0; i<n; i++) {
        if (a[i]<0 && b[i]) num++;
        if (a[i]<0) tot++;
    }
    dp[0][0][0] = 1;
    for (int i=0; i<num; i++) {
        for (int j=0; j<=num; j++) {
            if (dp[j][0][0] > 0) {
                if (tot-num+i-j > 0) dp[j+1][0][1] = (dp[j+1][0][1] + ll(dp[j][0][0]) * (tot-num+i-j)) % MOD;
                if (num-i-1 > 0) dp[j][1][1] = (dp[j][1][1] + ll(dp[j][0][0]) * (num-i-1)) % MOD;
            }
            if (dp[j][1][0] > 0) {
                if (tot-num+i-j > 0) dp[j+2][0][1] = (dp[j+2][0][1] + ll(dp[j][1][0]) * (tot-num+i-j)) % MOD;
                if (num-i-1 > 0) dp[j+1][1][1] = (dp[j+1][1][1] + ll(dp[j][1][0]) * (num-i-1)) % MOD;
            }
        }
        for (int j=0; j<=num; j++) {
            for (int k=0; k<2; k++) {
                dp[j][k][0] = dp[j][k][1]; dp[j][k][1] = 0;
            }
        }
    }
    ret = ll(dp[num][0][0]) * fact[tot-num] % MOD;
    printf("%d\n", ret);
}