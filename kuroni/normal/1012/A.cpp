#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, a[2 * N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++)
        scanf("%d", a + i);
    sort(a, a + 2 * n);
    long long ans = 1LL * (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
    for (int i = 1; i < n; i++)
        ans = min(ans, 1LL * (a[2 * n - 1] - a[0]) * (a[i + n - 1] - a[i]));
    printf("%lld\n", ans);
}