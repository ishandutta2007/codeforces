#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 1e9 + 7;

struct TMat
{
    long long a[16][16];
} base, start;
int n, i, c;
long long k, a, b;

void init()
{
    memset(base.a, 0, sizeof(base.a));
    for (int i = 0; i < 16; i++)
        base.a[i][i] = 1;
    start = base;
}

TMat cur(const int &c)
{
    TMat ans;
    memset(ans.a, 0, sizeof(ans.a));
    ans.a[0][0] = ans.a[1][0] = 1;
    if (c == 0)
    {
        ans.a[1][0] = 0;
        return ans;
    }
    ans.a[c - 1][c] = ans.a[c][c] = 1;
    for (int i = 1; i < c; i++)
        ans.a[i - 1][i] = ans.a[i][i] = ans.a[i + 1][i] = 1;
    return ans;
}

TMat operator * (const TMat &a, const TMat &b)
{
    TMat ans;
    memset(ans.a, 0, sizeof(ans.a));
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 16; j++)
            for (int k = 0; k < 16; k++)
            {
                ans.a[i][j] += a.a[i][k] * b.a[k][j];
                ans.a[i][j] %= mod;
            }
    return ans;
}

TMat operator ^ (const TMat &a, const long long &b)
{
    if (b == 0)
        return base;
    TMat ans = a ^ (b / 2);
    ans = ans * ans;
    if (b & 1)
        ans = ans * a;
    return ans;
}

int main()
{
    scanf("%d%I64d", &n, &k);
    init();
    for (i = 1; i <= n; i++)
    {
        scanf("%I64d%I64d%d", &a, &b, &c);
        start = start * (cur(c) ^ (min(b, k) - a));
    }
    printf("%I64d", start.a[0][0]);
}