#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 200005;

int n, s, a[N];
long long ans = 0;

int main()
{
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n / 2; i++)
        ans += max(0, a[i] - s);
    ans += abs(a[n / 2 + 1] - s);
    for (int i = n / 2 + 2; i <= n; i++)
        ans += max(0, s - a[i]);
    printf("%lld", ans);
}