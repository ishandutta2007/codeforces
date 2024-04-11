#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

struct trash
{
    double gt;
    int vt;
}   tmpb[100005];

double a[100005], b[100005], t[100005], sum = 0, ans = 1e18, tmpa[100005];
long long ax, ay, bx, by, tx, ty, n, i, x, y;

bool compare(trash a, trash b)
{
    return a.gt < b.gt;
}

int main()
{
    scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &ax, &ay, &bx, &by, &tx, &ty);
    scanf("%I64d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%I64d%I64d", &x, &y);
        a[i] = sqrt((x - ax) * (x - ax) + (y - ay) * (y - ay));
        b[i] = sqrt((x - bx) * (x - bx) + (y - by) * (y - by));
        t[i] = sqrt((x - tx) * (x - tx) + (y - ty) * (y - ty));
        sum += 2 * t[i];
    }
    for (i = 1; i <= n; i++)
    {
        tmpa[i] = a[i] - t[i];
        tmpb[i].gt = b[i] - t[i];
        tmpb[i].vt = i;
    }
    sort(tmpb + 1, tmpb + 1 + n, compare);
    ans = tmpb[1].gt;
    double tmp;
    for (i = 1; i <= n; i++)
    {
        tmp = tmpa[i];
        if (tmp < ans)
            ans = tmp;
    }
    for (i = 1; i <= n; i++)
    {
        if (tmpb[1].vt == i) tmp = tmpa[i] + tmpb[2].gt;
        else tmp = tmpa[i] + tmpb[1].gt;
        if (tmp < ans) ans = tmp;
    }
    printf("%.12f", ans + sum);
	return 0;
}