#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int Maxm = 201;

int n;
int cur, dp[2][2][Maxm];

void Add(int a, int b, int lef, int rig, int ways)
{
    if (rig <= 0 || lef >= Maxm) return;
    dp[a][b][lef] = (dp[a][b][lef] + ways) % mod;
    if (rig + 1 < Maxm)
        dp[a][b][rig + 1] = (dp[a][b][rig + 1] - ways + mod) % mod;
}

int main()
{
    scanf("%d", &n);
    dp[cur][0][0] = 1;
    dp[cur][0][1] = mod - 1;
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        for (int j = 0; j < 2; j++) {
            int my = 0;
            for (int k = 0; k < Maxm; k++) {
                my = (my + dp[cur][j][k]) % mod;
                dp[cur][j][k] = 0;
                if (my == 0) continue;
                if (j == 0) {
                    if (a == -1) {
                        Add(!cur, 1, k, k, my);
                        Add(!cur, 0, k + 1, Maxm - 1, my);
                    } else if (a == k) Add(!cur, 1, a, a, my);
                           else if (a > k) Add(!cur, 0, a, a, my);
                } else {
                    if (a == -1) {
                        Add(!cur, 1, 1, k, my);
                        Add(!cur, 0, k + 1, Maxm - 1, my);
                    } else if (a <= k) Add(!cur, 1, a, a, my);
                           else Add(!cur, 0, a, a, my);
                }
            }
        }
        cur = !cur;
    }
    int res = 0;
    int my = 0;
    for (int i = 0; i < Maxm; i++) {
        my = (my + dp[cur][1][i]) % mod;
        res = (res + my) % mod;
    }
    printf("%d\n", res);
    return 0;
}