#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 5005;

int n, m, mod;
int ways[Maxn][Maxn], waysmult[Maxn][Maxn];
int cur, tot[2], dp[2][Maxn], len[2];

int main()
{
    scanf("%d %d %d", &n, &m, &mod);
    ways[0][0] = waysmult[0][0] = 1;
    for (int i = 0; i + 1 < Maxn; i++)
        for (int j = 0; j <= i; j++) {
            if (j > 0) {
                ways[i + 1][j] = (ways[i + 1][j] + ll(j - 1) * ways[i][j]) % mod;
                waysmult[i + 1][j] = (waysmult[i + 1][j] + ll(j - 1) * waysmult[i][j]) % mod;
            }
            ways[i + 1][j + 1] = (ways[i + 1][j + 1] + ll(j + 1) * ways[i][j]) % mod;
            waysmult[i + 1][j + 1] = (waysmult[i + 1][j + 1] + ll(m - j) * waysmult[i][j]) % mod;
        }
    tot[cur] = 1;
    for (int i = 0; i < n; i++) {
        cur = !cur;
        for (int j = 0; j <= len[cur]; j++)
            dp[cur][j] = 0;
        tot[cur] = 0;
        scanf("%d", &len[cur]);
        for (int j = 0; j <= len[cur]; j++) {
            dp[cur][j] = (ll(tot[!cur]) * waysmult[len[cur]][j] % mod - ll(dp[!cur][j]) * ways[len[cur]][j] % mod + mod) % mod;
            tot[cur] = (tot[cur] + dp[cur][j]) % mod;
        }
    }
    printf("%d\n", tot[cur]);
    return 0;
}