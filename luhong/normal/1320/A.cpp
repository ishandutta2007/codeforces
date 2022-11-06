#include <iostream>
#include <cstdio>
#include <algorithm>
#define MN 1001000

int a[MN];
long long sum[2 * MN];

int main()
{
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), sum[a[i] - i + MN] += a[i];
    long long ans = 0;
    for(int i = 0; i < 2 * MN; i++) ans = std::max(ans, sum[i]);
    printf("%lld\n", ans);
}