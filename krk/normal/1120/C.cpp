#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;
const int Inf = 1000000000;

int n, a, b;
char str[Maxn];
int dp[Maxn];
char tmp[Maxn];
int Z[Maxn];

int getMax(int ind)
{
    int tlen = 0;
    for (int i = ind; i < n; i++)
        tmp[tlen++] = str[i];
    for (int i = 0; i < ind; i++)
        tmp[tlen++] = str[i];
    tmp[tlen] = '\0';
    int l = -1, r = -1;
    Z[0] = 0;
    for (int i = 1; i < tlen; i++) {
        if (i <= r) Z[i] = min(Z[i - l], r - i);
        else Z[i] = 0;
        while (i + Z[i] < tlen && tmp[Z[i]] == tmp[i + Z[i]])
            Z[i]++;
        if (i + Z[i] - 1 > r) {
            l = i; r = i + Z[i] - 1;
        }
    }
    int mx = 0;
    for (int i = n - ind; i < n; i++)
        mx = max(mx, min(Z[i], n - ind));
    return mx;
}

int main()
{
    scanf("%d %d %d", &n, &a, &b);
    scanf("%s", str);
    fill(dp, dp + Maxn, Inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + a);
        int len = getMax(i);
        for (int j = 1; j <= len; j++)
            dp[i + j] = min(dp[i + j], dp[i] + b);
    }
    printf("%d\n", dp[n]);
    return 0;
}