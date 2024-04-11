#include <iostream>
#include <cstdio>
using namespace std;

const int N = 55, M = 55;
int n, m;
long long a[N], b[M], ans = 2E18;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", a + i);
    for (int i = 1; i <= m; i++)
        scanf("%I64d", b + i);
    for (int i = 1; i <= n; i++)
    {
        long long cur = -2E18;
        for (int j = 1; j <= n; j++)
            if (i != j)
                for (int k = 1; k <= m; k++)
                    cur = max(cur, a[j] * b[k]);
        ans = min(ans, cur);
    }
    printf("%I64d", ans);
}