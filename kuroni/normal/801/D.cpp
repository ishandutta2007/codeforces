#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int n, i;
long long x[1010], y[1010];
double ans;

double find_ans(int m)
{
    long long tmp = (x[m] - x[m - 1]) * (y[m] + y[m - 1])
                  + (x[m - 1] - x[m + 1]) * (y[m - 1] + y[m + 1])
                  + (x[m + 1] - x[m]) * (y[m + 1] + y[m]);
    if (tmp < 0)
        tmp = -tmp;
    return (double) tmp / sqrt((x[m + 1] - x[m - 1]) * (x[m + 1] - x[m - 1]) + (y[m + 1] - y[m - 1]) * (y[m + 1] - y[m - 1]));
}

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%lld%lld", x + i, y + i);
    x[0] = x[n]; y[0] = y[n];
    x[n + 1] = x[1]; y[n + 1] = y[1];
    ans = find_ans(1);
    for (i = 2; i <= n; i++)
        ans = min(ans, find_ans(i));
    printf("%.16f", ans / 2);
}