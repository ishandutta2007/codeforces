#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct TMat
{
    int f[105][105];
} input, fix, base;
int a[105], n, T, i, j, k, ans = 0;

inline TMat operator * (const TMat &a, const TMat &b)
{
    TMat ans;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            ans.f[i][j] = -1e9;
            for (int k = 1; k <= n; k++)
                ans.f[i][j] = max(ans.f[i][j], a.f[i][k] + b.f[k][j]);
        }
    return ans;
}

inline TMat operator ^ (const TMat &a, const int &b)
{
    if (b == 1)
        return a;
    TMat ans = a ^ (b / 2);
    ans = ans * ans;
    if (b & 1)
        ans = ans * a;
    return ans;
}

void init()
{
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            fix.f[i][j] = base.f[i][j] = -1e9;
            if (a[i] <= a[j])
                base.f[i][j] = 1;
        }
    for (k = 1; k <= n; k++)
    {
        fix.f[k][k] = 0;
        for (i = k + 1; i <= n; i++)
            for (j = k; j < i; j++)
                if (a[i] >= a[j] && a[j] >= a[k])
                    fix.f[k][i] = max(fix.f[k][i], fix.f[k][j] + 1);
    }
}

int main()
{
    scanf("%d%d", &n, &T);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        input.f[1][i] = 1;
    }
    init();
    input = input * fix;
    if (T > 1)
        input = input * ((base * fix) ^ (T - 1));
    for (i = 1; i <= n; i++)
        ans = max(ans, input.f[1][i]);
    printf("%d", ans);
    return 0;
}