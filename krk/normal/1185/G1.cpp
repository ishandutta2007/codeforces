#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 52;
const int Maxm = 2505;
const int mod = 1000000007;
const int Maxd = 4;

int n, T;
int t[Maxn], g[Maxn];
int cnt[3];
int my[Maxn][Maxn][Maxn][Maxd];
vector <vector <vector <vector <int> > > > dp;

int main()
{
    scanf("%d %d", &n, &T);
    for (int i = 0; i < Maxd; i++)
        my[0][0][0][i] = 1;
    for (int i = 0; i < Maxn; i++)
        for (int j = 0; j < Maxn; j++)
            for (int k = 0; k < Maxn; k++)
                for (int f = 0; f < Maxd; f++) {
                    if (f != 0 && i > 0)
                        my[i][j][k][f] = (my[i][j][k][f] + ll(my[i - 1][j][k][0]) * i) % mod;
                    if (f != 1 && j > 0)
                        my[i][j][k][f] = (my[i][j][k][f] + ll(my[i][j - 1][k][1]) * j) % mod;
                    if (f != 2 && k > 0)
                        my[i][j][k][f] = (my[i][j][k][f] + ll(my[i][j][k - 1][2]) * k) % mod;
                }
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &t[i], &g[i]);
        cnt[g[i] - 1]++;
    }
    dp.resize(cnt[0] + 1);
    for (int i = 0; i <= cnt[0]; i++) {
        dp[i].resize(cnt[1] + 1);
        for (int j = 0; j <= cnt[1]; j++) {
            dp[i][j].resize(cnt[2] + 1);
            for (int k = 0; k <= cnt[2]; k++)
                dp[i][j][k].resize(Maxm + 1, 0);
        }
    }
    dp[0][0][0][0] = 1;
    for (int z = 0; z < n; z++)
        for (int i = cnt[0]; i >= 0; i--)
            for (int j = cnt[1]; j >= 0; j--)
                for (int k = cnt[2]; k >= 0; k--)
                    for (int l = Maxm - t[z]; l >= 0; l--) if (dp[i][j][k][l]) {
                        int ni = g[z] == 1? i + 1: i;
                        int nj = g[z] == 2? j + 1: j;
                        int nk = g[z] == 3? k + 1: k;
                        int nl = l + t[z];
                        dp[ni][nj][nk][nl] = (dp[ni][nj][nk][nl] + dp[i][j][k][l]) % mod;
                    }
    int res = 0;
    for (int i = 0; i <= cnt[0]; i++)
        for (int j = 0; j <= cnt[1]; j++)
            for (int k = 0; k <= cnt[2]; k++)
                res = (res + ll(dp[i][j][k][T]) * my[i][j][k][Maxd - 1]) % mod;
    printf("%d\n", res);
    return 0;
}