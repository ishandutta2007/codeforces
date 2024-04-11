#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, m, q, i, l, r, v;
long long b[100005], sum = 0, cur;

long long ans(long long sum)
{
    int l = 0, r = m - n, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (b[mid] <= sum)
            l = mid + 1;
        else r = mid - 1;
    }
    if (r == -1)
        return abs(sum - b[l]);
    if (l == m - n + 1)
        return abs(sum - b[r]);
    return min(abs(sum - b[l]), abs(sum - b[r]));
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (i = 1; i <= n; i++)
    {
        scanf("%I64d", &cur);
        if (i & 1)
            sum += cur;
        else sum -= cur;
    }
    cur = 0;
    for (i = 1; i < n; i++)
    {
        scanf("%I64d", b + i);
        if (i & 1)
            cur -= b[i];
        else cur += b[i];
    }
    for (i = n; i <= m; i++)
    {
        scanf("%I64d", b + i);
        cur -= b[i - n];
        cur = -cur;
        if (n & 1)
            cur += b[i];
        else cur -= b[i];
        b[i - n] = cur;
    }
    sort(b, b + m - n + 1);
    printf("%I64d\n", ans(sum));
    while (q--)
    {
        scanf("%d%d%d", &l, &r, &v);
        if (((r - l) & 1) == 0)
        {
            if (l & 1)
                sum += v;
            else sum -= v;
        }
        printf("%I64d\n", ans(sum));
    }
}