#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 105;

int ans = 0, n, k, a[N];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
    {
        int cur = 0;
        for (int j = 1; j <= n; j++)
            if (i % k != j % k)
                cur += a[j];
        ans = max(ans, abs(cur));
    }
    printf("%d", ans);
}