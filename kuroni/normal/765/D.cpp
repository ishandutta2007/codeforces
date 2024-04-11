#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m1 = 0, m2 = 0, f[100005], h[100005], g[100005], cnt[100005], i;

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", f + i);
        m1 += (cnt[f[i]] == 0);
        m2 += (i == f[i]);
        ++cnt[f[i]];
    }
    if (m1 != m2)
    {
        printf("-1");
        return 0;
    }
    m2 = 0; memset(cnt, 0, sizeof(cnt));
    for (i = 1; i <= n; i++)
        if (i == f[i])
        {
            h[++m2] = i;
            g[i] = m2;
            cnt[i] = m2;
        }
    for (i = 1; i <= n; i++)
        if (i != f[i])
        g[i] = cnt[f[i]];
    printf("%d\n", m1);
    for (i = 1; i <= n; i++)
        printf("%d ", g[i]);
    printf("\n");
    for (i = 1; i <= m1; i++)
        printf("%d ", h[i]);
}