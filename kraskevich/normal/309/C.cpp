#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000 * 1000;
int a, b[N], c[31], n, m, res = 0;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        for (int f = 0; f < 31; f++)
            if (a & (1 << f))
                c[f]++;
    }
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    sort(b, b + m);
    for (int i = 0; i < m; i++)
    {
        int l = 31;
        for (int f = 30; f >= b[i]; f--)
            if (c[f])
                l = f;
        if (l == 31)
            break;
        res++;
        c[l]--;
        for (int f = b[i]; f < l; f++)
            c[f]++;
    }
    printf("%d", res);
}