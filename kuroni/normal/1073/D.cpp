#include <iostream>
#include <cstdio>
using namespace std;

const int N = 200005;

int n, a[N];
long long t, ans = 0, sum[N];

void upd(int u, int v)
{
    for (; u <= n; u += u & -u)
        sum[u] += v;
}

long long que(int u)
{
    long long ret = 0;
    for (; u > 0; u -= u & -u)
        ret += sum[u];
    return ret;
}

int BS(int l)
{
    int r = n;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (que(m) > t)
            r = m - 1;
        else
            l = m + 1;
    }
    return l;
}

int main()
{
    scanf("%d%lld", &n, &t);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        upd(i, a[i]);
    }
    int cnt = n;
    while (cnt > 0)
    {
        ans += t / que(n) * cnt;
        t %= que(n);
        for (int pt = BS(1); pt <= n; pt = BS(pt))
        {
            --cnt;
            upd(pt, -a[pt]);
        }
    }
    printf("%lld", ans);
}