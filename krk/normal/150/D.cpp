#include <bits/stdc++.h>
using namespace std;

const int Maxn = 152;
const int Maxm = 78;
const int Inf = 1000000000;

int L;
int val[Maxn];
string s;
int dp[Maxn][Maxn];
int nd[Maxn][Maxn][Maxm];
int all[Maxn][Maxn];

int main()
{
    scanf("%d", &L);
    for (int i = 1; i <= L; i++)
        scanf("%d", &val[i]);
    cin >> s;
    for (int i = 0; i < L; i++) {
        int mn = min(i, L - 1 - i);
        for (int j = 0; j <= mn; j++)
            if (val[2 * j + 1] != -1)
                nd[i][i][j] = val[2 * j + 1];
            else nd[i][i][j] = -Inf;
        all[i][i] = nd[i][i][0];
        dp[i][i] = max(all[i][i], 0);
    }
    for (int l = 1; l <= L; l++)
        for (int i = 0, j = l; j < L; i++, j++) {
            int mn = min(i, L - 1 - j);
            if (s[i] != s[j])
                fill(nd[i][j], nd[i][j] + mn + 1, -Inf);
            else for (int z = 0; z <= mn; z++) {
                    nd[i][j][z] = -Inf;
                    if (val[2 * z + 2] != -1) {
                        int cand = val[2 * z + 2];
                        if (i + 1 < j) cand += all[i + 1][j - 1];
                        nd[i][j][z] = max(nd[i][j][z], cand);
                    }
                    for (int a = i + 1; a < j; a++)
                        for (int b = a; b < j; b++) {
                            int cand = nd[a][b][z + 1];
                            if (cand < 0) continue;
                            if (i + 1 < a) cand += all[i + 1][a - 1];
                            if (cand < 0) continue;
                            if (b + 1 < j) cand += all[b + 1][j - 1];
                            nd[i][j][z] = max(nd[i][j][z], cand);
                        }
                }
            all[i][j] = dp[i][j] = nd[i][j][0];
            for (int k = i; k < j; k++) {
                all[i][j] = max(all[i][j], all[i][k] + all[k + 1][j]);
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            if (i < j)
                dp[i][j] = max(dp[i][j], max(dp[i + 1][j], dp[i][j - 1]));
        }
    printf("%d\n", dp[0][L - 1]);
    return 0;
}