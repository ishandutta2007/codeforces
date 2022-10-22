#include <cstdio>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 55;

int n, m;
int a[Maxn];
ld f[Maxn][Maxn][Maxn], prob[Maxn][Maxn][Maxn];
ld ex;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
        for (int j = 0; j <= n; j++) {
            f[i][j][0] = j? ld(i - 1) / ld(i) * f[i][j - 1][0]: 1.0L;
            for (int k = 1; k <= j; k++)
                f[i][j][k] = f[i][j - 1][k - 1] / ld(i) + ld(i - 1) / ld(i) * f[i][j - 1][k];
        }
    prob[0][0][0] = 1.0L;
    for (int i = 0; i < m; i++)
        for (int j = 0; j <= n; j++)
            for (int l = 0; l <= n; l++)
                for (int k = 0; j + k <= n; k++) {
                    int q = k / a[i] + (k % a[i] > 0);
                    prob[i + 1][j + k][max(l, q)] += prob[i][j][l] * f[m - i][n - j][k];
                }
    for (int i = 0; i <= n; i++) ex += prob[m][n][i] * ld(i);
    printf("%.23lf\n", double(ex));
    return 0;
}