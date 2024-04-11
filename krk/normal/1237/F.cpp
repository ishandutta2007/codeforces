#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 3700;
const int mod = 998244353;

int C[Maxn][Maxn], fac[Maxn];
int h, w, n;
bool was1[Maxn], was2[Maxn];
int dp1[Maxn], dp2[Maxn];
int tot1, tot2;
int res;

void Prec(int n, bool was[], int dp[], int &tot)
{
    dp[0] = 1;
    int i = 1;
    while (i <= n)
        if (was[i]) i++;
        else {
            int j = i;
            while (j <= n && !was[j]) j++;
            tot += j - i;
            for (int a = n; a >= 0; a--) if (dp[a]) {
                int ways = dp[a]; dp[a] = 0;
                for (int b = 0; 2 * b <= j - i; b++)
                    dp[a + b] = (dp[a + b] + ll(C[j - i - b][b]) * ways) % mod;
            }
            i = j;
        }
}

int main()
{
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    fac[0] = 1;
    for (int i = 1; i < Maxn; i++)
        fac[i] = ll(i) * fac[i - 1] % mod;
    scanf("%d %d %d", &h, &w, &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++) {
            int r, c; scanf("%d %d", &r, &c);
            was1[r] = was2[c] = true;
        }
    Prec(h, was1, dp1, tot1);
    Prec(w, was2, dp2, tot2);
    for (int a = 0; a <= tot1 && 2 * a <= tot2; a++)
        for (int b = 0; a + 2 * b <= tot1 && 2 * a + b <= tot2; b++) {
            int ways = ll(dp1[b]) * dp2[a] % mod *
                       C[tot1 - 2 * b][a] % mod * C[tot2 - 2 * a][b] % mod *
                       fac[a] % mod * fac[b] % mod;
            res = (res + ways) % mod;
        }
    printf("%d\n", res);
    return 0;
}