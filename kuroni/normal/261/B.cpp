#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 1e9 + 7;

long long f[55][55], C[55][55];
int a[55], n, p, i, sum = 0;
double ans = 0.0;

void init()
{
    for (int i = 0; i <= n; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
}

void solve(int x)
{
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        if (i != x)
            for (int j = p; j >= a[i]; j--)
                for (int k = 1; k <= n - 1; k++)
                    f[j][k] += f[j - a[i]][k - 1];
    for (int i = p; i > max(-1, p - a[x]); i--)
        for (int j = 0; j <= n - 1; j++)
            ans += (double) (f[i][j] * j) / (C[n][j] * (n - j));
}

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        sum += a[i];
    }
    scanf("%d", &p);
    if (sum <= p)
    {
        printf("%d", n);
        return 0;
    }
    init();
    for (i = 1; i <= n; i++)
        solve(i);
    printf("%f", ans);
}