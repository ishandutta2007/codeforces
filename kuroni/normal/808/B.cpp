#include <stdio.h>
#include <iostream>
using namespace std;

long long sum = 0, tmp_sum = 0;
int n, k, i, tmp, a[200005];

int main()
{
    scanf("%d%d", &n, &k);
    a[0] = 0;
    for (i = 1; i <= k - 1; i++)
    {
        scanf("%d", a + i);
        tmp_sum += a[i];
    }
    for (i = k; i <= n; i++)
    {
        scanf("%d", a + i);
        tmp_sum += a[i] - a[i - k];
        sum += tmp_sum;
    }
    printf("%.8f", (double)sum / (n - k + 1));
}