#include <iostream>
#include <cstdio>
#include <algorithm>
#define MN 301000

long long a[MN];

int main()
{
    int n, k; scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for(int i = n - 1; i >= 1; i--) a[i] += a[i + 1];
    long long ans = a[1];
    std::sort(a + 2, a + n + 1, std::greater<long long>());
    for(int i = 2; i <= k; i++) ans += a[i];
    printf("%lld\n", ans);
}