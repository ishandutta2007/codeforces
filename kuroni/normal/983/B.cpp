#include <iostream>
#include <cstdio>
using namespace std;

const int N = 5005;

int n, q, l, r, a[N], f[N][N], g[N][N];

void find_ans(int l, int r)
{
    if (f[l][r] != -1)
        return;
    if (l == r)
    {
        f[l][r] = g[l][r] = a[l];
        return;
    }
    find_ans(l, r - 1);
    find_ans(l + 1, r);
    f[l][r] = f[l][r - 1] ^ f[l + 1][r];
    g[l][r] = max(f[l][r], max(g[l][r - 1], g[l + 1][r]));
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        fill(f[i] + 1, f[i] + n + 1, -1);
    }
    find_ans(1, n);
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", g[l][r]);
    }
}