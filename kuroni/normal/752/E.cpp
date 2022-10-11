#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 1E7 + 5;

int n, k, a;
long long cur = 0, cnt[MAX], rem[MAX];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        cnt[a]++;
    }
    for (int i = MAX - 1; i >= 1; i--)
    {
        cur += cnt[i] - rem[i];
        if (cur >= k)
        {
            printf("%d", i);
            return 0;
        }
        else
        {
            rem[(i + 1) / 2] += cnt[i];
            cnt[i / 2] += cnt[i];
            cnt[(i + 1) / 2] += cnt[i];
        }
    }
    printf("-1");
}