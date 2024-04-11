#include <iostream>
#include <cstdio>
using namespace std;

int n, i, j, p[256][256];
double f[256][256], c[256][256], ans = 0;

double find_ans(const int &i, const int &l, const int &r, const int &w)
{
    if (f[i][w] >= 0.0)
        return f[i][w];
    if (r == l + 1)
        return f[i][w] = c[i][w] = l == w ? p[l][r] / 100.0 : p[r][l] / 100.0;
    int m = (l + r - 1) / 2, pt = (r - l + 1) / 2;
    double maxi = 0.0;
    f[i][w] = w <= m ? find_ans(2 * i, l, m, w) : find_ans(2 * i + 1, m + 1, r, w);
    if (w <= m)
    {
        for (int k = m + 1; k <= r; k++)
        {
            maxi = max(maxi, find_ans(2 * i + 1, m + 1, r, k));
            f[i][w] += c[2 * i][w] * c[2 * i + 1][k] * p[w][k] * pt / 100.0;
            c[i][w] += p[w][k] / 100.0 * c[2 * i + 1][k];
        }
        c[i][w] *= c[2 * i][w];
    }
    else
    {
        for (int k = l; k <= m; k++)
        {
            maxi = max(maxi, find_ans(2 * i, l, m, k));
            f[i][w] += c[2 * i + 1][w] * c[2 * i][k] * p[w][k] * pt / 100.0;
            c[i][w] += p[w][k] / 100.0 * c[2 * i][k];
        }
        c[i][w] *= c[2 * i + 1][w];
    }
    return f[i][w] += maxi;
}

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= (1 << n); i++)
        for (j = 1; j <= (1 << n); j++)
            scanf("%d", &p[i][j]);
    for (i = 0; i < 256; i++)
        for (j = 0; j < 256; j++)
            f[i][j] = -1.0;
    for (i = 1; i <= (1 << n); i++)
        ans = max(ans, find_ans(1, 1, 1 << n, i));
    printf("%.15f", ans);
}