#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxm = 5005;
const int Maxv = 1000005;
const int Inf = 1000000007;

int n, k;
int freq[Maxv];
int play[Maxv];
int h[Maxm];
ll res;
int dp[Maxm];

int Solve(int c, int p)
{
    if (c >= p * k)
        return h[k] * p;
    fill(dp, dp + Maxm, -Inf);
    dp[0] = 0;
    for (int i = 0; i < p; i++)
        for (int j = c; j >= 0; j--) if (dp[j] >= 0)
            for (int z = 1; z <= k && j + z <= c; z++)
                dp[j + z] = max(dp[j + z], dp[j] + h[z]);
    return dp[c];
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n * k; i++) {
        int c; scanf("%d", &c);
        freq[c]++;
    }
    for (int i = 1; i <= n; i++) {
        int f; scanf("%d", &f);
        play[f]++;
    }
    for (int i = 1; i <= k; i++)
        scanf("%d", &h[i]);
    for (int i = 0; i < Maxv; i++)
        res += Solve(freq[i], play[i]);
    printf("%I64d\n", res);
    return 0;
}