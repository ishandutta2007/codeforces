#include <iostream>
#include <cstdio>
using namespace std;

int t, n, sum[14];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < 7; i++)
        {
            scanf("%d", sum + i);
            sum[i + 7] = sum[i];
        }
        for (int i = 1; i < 14; i++)
            sum[i] += sum[i - 1];
        int ans = n / sum[6] * 7, mi = 7;
        n %= sum[6];
        if (n == 0)
        {
            ans -= 7;
            n = sum[6];
        }
        for (int i = 1; i <= 7; i++)
        {
            for (int j = i - 1; ; j++)
                if (sum[j] - sum[i - 1] == n)
                {
                    mi = min(mi, j - i + 1);
                    break;
                }
        }
        printf("%d\n", ans + mi);
    }
}