#include <iostream>
#include <cstdio>
using namespace std;

const int MX = 840, W = 7000;

long long w, cur = 0, a[10];
bool f[10][W];

int main()
{
    scanf("%lld", &w);
    for (int i = 1; i <= 8; i++)
    {
        scanf("%lld", a + i);
        cur += a[i] * i;
    }
    if (cur <= w)
        return printf("%lld", cur), 0;
    cur = 0;
    for (int i = 8; i >= 1; i--)
    {
        long long tmp = min(a[i] * i, w);
        tmp = tmp / MX * MX / i;
        w -= tmp * i;
        cur += tmp * i;
        a[i] -= tmp;
        a[i] = min(a[i], 1LL * MX / i);
    }
    f[0][0] = true;
    for (int i = 1; i <= 8; i++)
        for (int j = 0; j <= a[i]; j++)
            for (int k = i * j; k <= w; k++)
                f[i][k] |= f[i - 1][k - i * j];
    for (int i = w; i >= 0; i--)
        if (f[8][i])
            return printf("%lld", cur + i), 0;
}