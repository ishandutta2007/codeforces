#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n, w, half = 0, ans[105], i;
struct save
{
    int val, ind;
} a[105];

bool compare(const save &a, const save &b)
{
    return a.val < b.val;
}

int main()
{
    scanf("%d%d", &n, &w);
    for (i = 1; i <= n; i++)
    {
        ans[i] = 0;
        scanf("%d", &a[i].val);
        a[i].ind = i;
        half += (a[i].val + 1) / 2;
    }
    if (half > w)
    {
        printf("-1");
        return 0;
    }
    else
    {
        sort(a + 1, a + n + 1, compare);
        w -= half;
        for (i = 1; i <= n; i++)
            ans[a[i].ind] = (a[i].val + 1) / 2;
        for (i = n; i >= 1; i--)
        {
            if (w <= a[i].val - ans[a[i].ind])
            {
                ans[a[i].ind] += w;
                break;
            }
            else
            {
                w -= a[i].val - ans[a[i].ind];
                ans[a[i].ind] = a[i].val;
            }
        }
        for (i = 1; i <= n; i++)
            printf("%d ", ans[i]);
    }
}