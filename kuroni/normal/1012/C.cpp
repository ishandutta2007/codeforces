#include <iostream>
#include <cstdio>
using namespace std;

const int N = 5005;
const long long INF = 1E18 + 7;

int n, a[N];
long long f[N][N][2];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            f[i][j][0] = f[i][j][1] = INF;
    f[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        for (int j = 0; j <= (i + 1) / 2; j++)
        {
            // f[0]
            if (a[i - 1] > a[i])
                f[i][j][0] = min(f[i - 1][j][0], f[i - 1][j][1]);
            else
                f[i][j][0] = min(f[i - 1][j][1] + a[i] - a[i - 1] + 1, f[i - 1][j][0]);
            
            // f[1]
            if (j > 0)
            {
                if (a[i - 1] < a[i])
                    f[i][j][1] = f[i - 1][j - 1][0];
                else
                {
                    if (a[i] <= a[i - 2])
                        f[i][j][1] = min(f[i - 2][j - 1][0], f[i - 2][j - 1][1]) + a[i - 1] - a[i] + 1;
                    else
                        f[i][j][1] = min(f[i - 2][j - 1][0] + a[i - 1] - a[i] + 1, f[i - 2][j - 1][1] + a[i - 1] - a[i - 2] + 1);
                }
            }
            // printf("%d %d : %lld %lld\n", i, j, f[i][j][0], f[i][j][1]);
        }
    }
    for (int i = 1; i <= (n + 1) / 2; i++)
        printf("%lld ", min(f[n][i][0], f[n][i][1]));
}