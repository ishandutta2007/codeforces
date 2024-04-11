#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 300005;

int n, a;
long long cnt[MAX], cof[MAX], f[MAX];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        cnt[a]++;
    }
    for (int i = 1; i < MAX; i++)
    {
        for (int j = 2 * i; j < MAX; j += i)
            cnt[i] += cnt[j];
        cof[i] = 1;
    }
    for (int te = 1; te <= 10; te++)
    {
        for (int i = MAX - 1; i >= 1; i--)
        {
            f[i] = (cof[i] *= cnt[i] - te + 1);
            for (int j = 2 * i; j < MAX; j += i)
                f[i] -= f[j];
        }
        if (f[1] != 0)
        {
            printf("%d", te);
            return 0;
        }
    }
    printf("-1");
}