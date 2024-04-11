#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 505;

int n, m;
int P[Maxn];
int mn[Maxn][Maxn];
int dp[Maxn][Maxn];

int Get(int l, int r)
{
    return l > r? 1: dp[l][r];
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &P[i]);
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
        mn[i][i] = i;
    }
    for (int l = 1; l <= n; l++)
        for (int i = 1, j = i + l; j <= n; i++, j++) {
            int ind1 = mn[i][j - 1];
            int ind2 = mn[i + 1][j];
            if (P[ind1] > P[ind2]) swap(ind1, ind2);
            mn[i][j] = ind1;
            int L = 0, R = 0;
            for (int k = ind1; k >= i; k--)
                L = (L + ll(Get(i, k - 1)) * Get(k, ind1 - 1)) % mod;
            for (int k = ind1; k <= j; k++)
                R = (R + ll(Get(ind1 + 1, k)) * Get(k + 1, j)) % mod;
            dp[i][j] = ll(L) * R % mod;
        }
    printf("%d\n", dp[1][n]);
    return 0;
}