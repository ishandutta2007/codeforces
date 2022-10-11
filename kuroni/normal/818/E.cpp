#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n, i, k, a[100005], j, cur[35], pr[35], cnt[35], num = 0, mis, tmp;
long long ans = 0;

int main()
{
    scanf("%d%d", &n, &k); j = sqrt(k);
    for (i = 2; i <= j; i++)
        if (k % i == 0)
    {
        pr[++num] = i;
        while (k % i == 0)
        {
            ++cnt[num];
            k /= i;
        }
    }
    if (k > 1)
    {
        pr[++num] = k;
        cnt[num] = 1;
    }
    mis = num; j = 0;
    a[0] = a[n + 1] = 1;
    for (i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (i = 1; i <= n; i++)
    {
        tmp = a[i - 1];
        for (k = 1; k <= num; k++)
            while (tmp % pr[k] == 0)
            {
                tmp /= pr[k];
                if (cur[k] == cnt[k])
                    ++mis;
                --cur[k];
            }
        if (j < i)
        {
            ++j;
            tmp = a[j];
            for (k = 1; k <= num; k++)
                while (tmp % pr[k] == 0)
                {
                    tmp /= pr[k];
                    ++cur[k];
                    if (cur[k] == cnt[k])
                        --mis;
                }
        }
        while (mis > 0 && j <= n)
        {
            ++j;
            tmp = a[j];
            for (k = 1; k <= num; k++)
                while (tmp % pr[k] == 0)
                {
                    tmp /= pr[k];
                    ++cur[k];
                    if (cur[k] == cnt[k])
                        --mis;
                }
        }
        if (mis > 0)
        {
            printf("%I64d", ans);
            return 0;
        }
        ans += n - j + 1;
    }
    printf("%I64d", ans);
}