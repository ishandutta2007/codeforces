#include <iostream>
#include <cstdio>
using namespace std;

int n, mi = 1e9, a[100005], pt = 0, ans = 1e5;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        mi = min(mi, a[i]);
    }
    for (int i = 1; i <= n; i++)
        if (a[i] == mi)
        {
            if (pt != 0)
                ans = min(ans, i - pt);
            pt = i;
        }
    printf("%d", ans);
}