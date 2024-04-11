#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 5005;

int inv[Maxn];
int n;
int a[Maxn];
int freq[Maxn], sum[Maxn];
int dp[Maxn][Maxn];
int res;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

int main()
{
    for (int i = 1; i < Maxn; i++)
        inv[i] = Inv(i);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        freq[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + freq[i];
    dp[1][0] += inv[n]; dp[1][n + 1] = (mod - inv[n]) % mod;
    for (int i = 1; i < n; i++) {
        int cur = 0;
        for (int j = 0; j <= n; j++) {
            cur = (cur + dp[i][j]) % mod;
            int my = ll(freq[j]) * cur % mod;
            if (my == 0) continue;
            int les = sum[j] - i - (freq[j] - 1);
            int eq = freq[j] - 1;
            int mor = sum[n] - sum[j];
            int all = sum[n] - i;
            res = (res + ll(eq) * inv[all] % mod * my) % mod;
            int giv = ll(mor) * inv[all] % mod * my % mod * inv[mor] % mod;
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + giv) % mod;
            dp[i + 1][n + 1] = (dp[i + 1][n + 1] - giv + mod) % mod;
        }
    }
    printf("%d\n", res);
    return 0;
}