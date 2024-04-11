#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 505;
const int Inf = 2000000000;

int n, m;
int B[Maxn][Maxn];
int sum[Maxn][Maxn];
int f[Maxn][Maxn];
int best = -Inf;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &B[i][j]);
            sum[i][j] += B[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            f[i][j] = B[i][j];
        }
    for (int l = 3; l <= n && l <= m; l += 2)
        for (int i = 1; i + l - 1 <= n; i++)
            for (int j = 1; j + l - 1 <= m; j++) {
                f[i][j] = sum[i + l - 1][j + l - 1] - sum[i + l - 1][j - 1] - sum[i - 1][j + l - 1] +
                          sum[i - 1][j - 1] - B[i + 1][j] - f[i + 1][j + 1];
                best = max(best, f[i][j]);
            }
    printf("%d\n", best);
    return 0;
}