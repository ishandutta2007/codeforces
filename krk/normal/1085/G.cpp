#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 2005;

int n;
int B[Maxn][Maxn];
int dp[Maxn][Maxn];
int pw[Maxn], fac[Maxn];
bool tk[Maxn];
int res;
int BIT1[Maxn], BIT2[Maxn];
int st[Maxn];

void Add(int BIT[], int x, int delt)
{
    for (int i = x; i <= n; i += i & -i)
        BIT[i] += delt;
}

int Get(int BIT[], int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &B[i][j]);
    dp[0][0] = 1;
    for (int l = 1; l <= n; l++)
        for (int i = 0; i <= l; i++) {
            int j = l - i;
            if (i > 0) {
                dp[i][j] = ll(dp[i - 1][j]) * i % mod;
                if (j > 0)
                    dp[i][j] = (dp[i][j] + ll(dp[i][j - 1]) * j) % mod;
            } else if (j >= 2)
                dp[i][j] = ll(dp[1][j - 2]) * (j - 1) % mod;
        }
    pw[0] = fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = ll(pw[i - 1]) * dp[0][n] % mod;
        fac[i] = ll(i) * fac[i - 1] % mod;
    }
    for (int j = 1; j <= n; j++) {
        int cnt = 0;
        for (int k = 1; k < B[1][j]; k++)
            cnt += !tk[k];
        res = (res + ll(cnt) * fac[n - j] % mod * pw[n - 1]) % mod;
        tk[B[1][j]] = true;
    }
    for (int i = 2; i <= n; i++) {
        fill(st + 1, st + n + 1, 2);
        fill(BIT1, BIT1 + n + 1, 0);
        fill(BIT2, BIT2 + n + 1, 0);
        for (int j = 1; j <= n; j++)
            Add(BIT2, j, 1);
        int dif = 0, sam = n;
        for (int j = 1; j <= n; j++) {
            int v = B[i - 1][j], u = B[i][j];
            if (st[v] == 0) {
                if (dif > 0) res = (res + ll(Get(BIT1, u - 1)) * dp[dif - 1][sam] % mod * pw[n - i]) % mod;
                if (sam > 0) res = (res + ll(Get(BIT2, u - 1)) * dp[dif][sam - 1] % mod * pw[n - i]) % mod;
            } else {
                res = (res + ll(Get(BIT1, u - 1)) * dp[dif][sam - 1] % mod * pw[n - i]) % mod;
                if (sam >= 2) res = (res + ll(Get(BIT2, u - 1) - int(v < u)) * dp[dif + 1][sam - 2] % mod * pw[n - i]) % mod;
            }
            int spec = 0;
            if (st[v] == 2) {
                st[v] = 1;
                Add(BIT2, v, -1);
                Add(BIT1, v, 1);
                spec++;
            }
            if (st[u] == 1) {
                st[u] = 0;
                Add(BIT1, u, -1);
            } else if (st[u] == 2) {
                spec++;
                st[u] = 0;
                Add(BIT2, u, -1);
            }
            if (spec == 0) dif--;
            else if (spec == 1) sam--;
            else {
                dif++;
                sam -= 2;
            }
        }
    }
    printf("%d\n", res);
    return 0;
}