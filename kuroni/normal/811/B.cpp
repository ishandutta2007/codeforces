#include <cstdio>
using namespace std;

int n, m, i, p[10005], cnt, l, r, x;

int main()
{
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
        scanf("%d", p + i);
    while (m--)
    {
        scanf("%d%d%d", &l, &r, &x);
        cnt = 0;
        for (i = l; i <= r; i++)
            cnt += (p[i] < p[x]);
        if (l + cnt == x)
            printf("Yes\n");
        else printf("No\n");
    }
}