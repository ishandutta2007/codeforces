#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 5005;
const short Inf = 32000;

int n, q;
ii seq[Maxn];
short dp[Maxn][Maxn][3];

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < q; i++)
        scanf("%d %d", &seq[i].first, &seq[i].second);
    sort(seq, seq + q);
    fill((short*)dp, (short*)dp + Maxn * Maxn * 3, -Inf);
    dp[1][0][0] = 0;
    for (int i = 1; i <= n + 1; i++)
        for (int j = 0; j < q; j++)
            for (int f = 0; f < 3; f++) {
                int ni = max(i, seq[j].second + 1);
                int add = ni - max(i, seq[j].first);
                dp[ni][j + 1][f] = max(dp[ni][j + 1][f], short(dp[i][j][f] + add));
                if (f < 2)
                    dp[i][j + 1][f + 1] = max(dp[i][j + 1][f + 1], dp[i][j][f]);
            }
    int res = 0;
    for (int i = 1; i <= n + 1; i++)
        res = max(res, int(dp[i][q][2]));
    printf("%d\n", res);
    return 0;
}