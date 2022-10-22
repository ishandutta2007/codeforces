#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 51;

int inv[Maxn + 2];
int dp[Maxn][Maxn];
int cur[Maxn];
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

int Inv(int x) { return toPower(x, mod - 2); }

void Traverse(int a, int b, int ways)
{
    cur[1] = ways;
    int hm = min((Maxn - 1) / a, (Maxn - 1) / b);
    for (int i = 2; i <= hm; i++)
        cur[i] = ll(cur[i - 1]) * (ways + i - 1) % mod * inv[i] % mod;
    for (int i = Maxn - 1 - a; i >= 0; i--)
        for (int j = 0; j <= i && j + b < Maxn; j++) if (dp[i][j])
            for (int a2 = a, b2 = b, z = 1; i + a2 < Maxn && j + b2 < Maxn; a2 += a, b2 += b, z++)
                dp[i + a2][j + b2] = (dp[i + a2][j + b2] + ll(dp[i][j]) * cur[z]) % mod;
}

int main()
{
    for (int i = 1; i < Maxn; i++)
        inv[i] = Inv(i);
    dp[0][0] = 1;
    for (int i = 0; i < Maxn; i++)
        for (int j = 0; j <= i; j++) {
            for (int i2 = 0; i2 < i; i2++) {
                int add1 = i + i2 + 1;
                if (add1 >= Maxn) break;
                for (int j2 = 0; j2 <= i2; j2++) {
                    int add2 = min(j, j2) + 1;
                    if (add2 >= Maxn) break;
                    int ways = ll(dp[i][j]) * dp[i2][j2] % mod;
                    Traverse(add1, add2, ways);
                    Traverse(add1, add2, ways);
                }
            }
            int add1 = i + i + 1;
            if (add1 < Maxn) {
                for (int j2 = 0; j2 < j; j2++) {
                    int add2 = min(j, j2) + 1;
                    if (add2 >= Maxn) break;
                    int ways = ll(dp[i][j]) * dp[i][j2] % mod;
                    Traverse(add1, add2, ways);
                    Traverse(add1, add2, ways);
                }
                int add2 = j + 1;
                if (add2 < Maxn)
                    Traverse(add1, add2, ll(dp[i][j]) * dp[i][j] % mod);
            }
        }
    int n, m; scanf("%d %d", &n, &m);
    cout << dp[n][m - 1] << endl;
    return 0;
}