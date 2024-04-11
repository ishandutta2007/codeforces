#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, m, u, v, pt = 1, a[N], c[N], ind[N];

long long dec(int &u, int &v)
{
    int get = min(a[u], v);
    v -= get; a[u] -= get;
    // printf("%d %d\n", u, v);
    return 1LL * c[u] * get;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        ind[i] = i;
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", c + i);
    sort(ind + 1, ind + n + 1, [](const int &x, const int &y) {
        return c[x] < c[y] || (c[x] == c[y] && x < y);
    });
    while (m--)
    {
        long long ans = 0;
        scanf("%d%d", &u, &v);
        ans += dec(u, v);
        for (; pt <= n && v > 0;)
        {
            ans += dec(ind[pt], v);
            if (a[ind[pt]] == 0)
                pt++;
        }
        printf("%lld\n", v > 0 ? 0LL : ans);
    }
}