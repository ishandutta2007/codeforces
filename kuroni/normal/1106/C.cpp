#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 300005;

int n, a[N];
long long ans = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        ans += a[i] * a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n / 2; i++)
        ans += 2 * a[i] * a[n - 1 - i];
    printf("%lld", ans);
}