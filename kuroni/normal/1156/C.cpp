#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200005;

int n, z, ans = 0, a[N];

int main()
{
    scanf("%d%d", &n, &z);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    for (int i = (n + 3) / 2, pt = 1; i <= n; i++)
        if (a[i] - a[pt] >= z)
        {
            ++ans;
            ++pt;
        }
    printf("%d", ans);
}