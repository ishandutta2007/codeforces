#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxk = 13;
const int Maxm = 1 << 4;
const int mod = 1000000007;

int bits[Maxm];
int n, k, m;
int dp[Maxn][Maxk][Maxm];
int res;

int main()
{
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i < 1 << m; i++)
        bits[i] = __builtin_popcount(i);
    dp[1][1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++)
            for (int z = 0; z < 1 << m; z++) if (dp[i][j][z]) {
                int nz = (z << 1);
                if (nz & (1 << m)) nz ^= 1 << m;
                dp[i + 1][j][nz] = (dp[i + 1][j][nz] + dp[i][j][z]) % mod;
                dp[i + 1][j + 1][nz | 1] = (dp[i + 1][j + 1][nz | 1] + ll(dp[i][j][z]) * (bits[z] + 1)) % mod;
            }
        int add = 0;
        for (int z = 0; z < 1 << m; z++)
            add = (add + dp[i][k][z]) % mod;
        res = (res + ll(add) * (n - i + 1)) % mod;
    }
    printf("%d\n", res);
    return 0;
}