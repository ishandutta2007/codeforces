#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 205;

int n, l, k;
double p[Maxn];
int a[Maxn];
double prob[Maxn][Maxn][Maxn];
double res;

int main()
{
    scanf("%d %d %d", &n, &l, &k);
    for (int i = 0; i < n; i++) {
        int pi; scanf("%d", &pi);
        p[i] = pi / 100.0;
    }
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    prob[0][0][min(n, k)] = 1.0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            for (int l = min(n, k); l <= n; l++) {
                prob[i + 1][j][l] += prob[i][j][l] * (1.0 - p[i]);
                if (a[i] == -1) prob[i + 1][j + 1][l] += prob[i][j][l] * p[i];
                else prob[i + 1][j + 1][min(n, l + a[i] + 1)] += prob[i][j][l] * p[i];
            }
    for (int j = l; j <= n; j++)
        for (int l = min(n, k); l <= n; l++) if (j <= l) res += prob[n][j][l];
    printf("%.12lf\n", res);
    return 0;
}