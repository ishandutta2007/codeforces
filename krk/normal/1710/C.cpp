#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 200005;
const int Maxd = 4;
const int Maxk = 3;

char str[Maxn];
int slen;
int dp[Maxn][Maxd][1 << Maxk];

bool Check(int lim, int mask, int a, int b, int c)
{
    if (bool(mask & 1) && a > lim) return false;
    if (bool(mask & 2) && b > lim) return false;
    if (bool(mask & 4) && c > lim) return false;
    return true;
}

int updateMask(int lim, int mask, int a, int b, int c)
{
    int res = mask;
    if (bool(mask & 1) && a < lim) res ^= 1;
    if (bool(mask & 2) && b < lim) res ^= 2;
    if (bool(mask & 4) && c < lim) res ^= 4;
    return res;
}

int Rot(int mask)
{
    int val = bool(mask & 1);
    mask >>= 1;
    mask |= val << 2;
    return mask;
}

int main()
{
    scanf("%s", str);
    slen = strlen(str);
    dp[0][0][7] = 1;
    for (int i = 0; i < slen; i++)
        for (int k = 0; k < 1 << Maxk; k++)
            for (int a = 0; a < 2; a++)
                for (int b = 0; b < 2; b++)
                    for (int c = 0; c < 2; c++) if (Check(str[i] - '0', k, a, b, c)) {
                        int nk = updateMask(str[i] - '0', k, a, b, c);
                        int v1 = (a ^ b);
                        int v2 = (b ^ c);
                        int v3 = (a ^ c);

                        int mem = nk;
                        // 0
                        if (v1 == v2 && v2 == v3) dp[i + 1][0][nk] = (dp[i + 1][0][nk] + dp[i][0][k]) % mod;
                        else if (v1 == 0) dp[i + 1][1][nk] = (dp[i + 1][1][nk] + dp[i][0][k]) % mod;
                        else if (v2 == 0) {
                            nk = Rot(nk);
                            dp[i + 1][1][nk] = (dp[i + 1][1][nk] + dp[i][0][k]) % mod;
                        } else {
                            nk = Rot(Rot(nk));
                            dp[i + 1][1][nk] = (dp[i + 1][1][nk] + dp[i][0][k]) % mod;
                        }
                        nk = mem;

                        // 1
                        if (v2 == v3)
                            dp[i + 1][1][nk] = (dp[i + 1][1][nk] + dp[i][1][k]) % mod;
                        else if (v2 == 0)
                            dp[i + 1][2][nk] = (dp[i + 1][2][nk] + dp[i][1][k]) % mod;
                        else {
                            nk = Rot(Rot(nk));
                            dp[i + 1][2][nk] = (dp[i + 1][2][nk] + dp[i][1][k]) % mod;
                        }
                        nk = mem;

                        // 2
                        if (v1 == 1 && v2 == 1)
                            dp[i + 1][3][nk] = (dp[i + 1][3][nk] + dp[i][2][k]) % mod;
                        else dp[i + 1][2][nk] = (dp[i + 1][2][nk] + dp[i][2][k]) % mod;
                        nk = mem;

                        // 3
                        dp[i + 1][3][nk] = (dp[i + 1][3][nk] + dp[i][3][k]) % mod;
                    }
   /* for (int i = 0; i <= slen; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 1 << Maxk; k++) if (dp[i][j][k])
                printf("dp[%d][%d][%d] = %d\n", i, j, k, dp[i][j][k]);*/
    int res = 0;
    for (int k = 0; k < 1 << Maxk; k++)
        res = (res + dp[slen][3][k]) % mod;
    printf("%d\n", res);
    return 0;
}