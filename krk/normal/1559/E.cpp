#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int mod = 998244353;

int res[Maxn];
int n, m;
int l[Maxn], r[Maxn];
int cur, dp[2][Maxn];


int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &l[i], &r[i]);
    for (int i = m; i >= 1; i--) {
        int M = m / i;
        dp[cur][0] = 1;
        dp[cur][1] = mod - 1;
        for (int j = 0; j < n; j++) {
            int ways = 0;
            int lef = (l[j] - 1) / i + 1;
            int rig = r[j] / i;
            for (int z = 0; z <= M; z++) {
                ways = (ways + dp[cur][z]) % mod;
                dp[cur][z] = 0;
                if (lef <= rig) {
                    if (z + lef <= M) dp[!cur][z + lef] = (dp[!cur][z + lef] + ways) % mod;
                    if (z + rig + 1 <= M) dp[!cur][z + rig + 1] = (dp[!cur][z + rig + 1] - ways + mod) % mod;
                }
            }
            cur = !cur;
        }
        int ways = 0;
        for (int j = 0; j <= M; j++) {
            ways = (ways + dp[cur][j]) % mod;
            dp[cur][j] = 0;
            res[i] = (res[i] + ways) % mod;
        }
        for (int j = i + i; j <= m; j += i)
            res[i] = (res[i] - res[j] + mod) % mod;
    }
    printf("%d\n", res[1]);
    return 0;
}