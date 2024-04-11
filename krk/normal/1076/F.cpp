#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const int Inf = 1000000000;

int n, k;
int X[Maxn];
int Y[Maxn];
int dp[Maxn][2];

int getRem(int pref, int x, int y)
{
    x -= (k - pref);
    if (x <= 0) return 0;
    y--;
    if (x <= ll(k) * y) return 0;
    return x - k * y; 
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &X[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &Y[i]);
    fill((int*)dp, (int*)dp + Maxn * 2, Inf);
    int rem1 = getRem(0, X[0], Y[0]);
    int rem2 = getRem(0, Y[0], X[0]);
    if (rem1 > 0) dp[1][0] = rem1;
    else if (rem2 > 0) dp[1][1] = rem2;
    else dp[1][0] = dp[1][1] = 1;
    for (int i = 1; i < n; i++) {
        if (dp[i][0] <= k) {
            int rem1 = getRem(dp[i][0], X[i], Y[i]);
            int rem2 = getRem(0, Y[i], X[i]);
            if (rem1 > 0) dp[i + 1][0] = min(dp[i + 1][0], rem1);
            else if (rem2 > 0) dp[i + 1][1] = min(dp[i + 1][0], rem2);
            else dp[i + 1][0] = dp[i + 1][1] = 1;
        }
        if (dp[i][1] <= k) {
            int rem1 = getRem(0, X[i], Y[i]);
            int rem2 = getRem(dp[i][1], Y[i], X[i]);
            if (rem1 > 0) dp[i + 1][0] = min(dp[i + 1][0], rem1);
            else if (rem2 > 0) dp[i + 1][1] = min(dp[i + 1][1], rem2);
            else dp[i + 1][0] = dp[i + 1][1] = 1;
        }
    }
    printf("%s\n", (dp[n][0] <= k || dp[n][1] <= k)? "YES": "NO");
    return 0;
}