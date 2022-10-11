#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100005;

int n, p, a[N];
long long ans = 0, pre[N], suf[N];

int main()
{
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        pre[i] = (pre[i - 1] + a[i]) % p;
    }
    for (int i = n; i >= 1; i--)
        suf[i] = (suf[i + 1] + a[i]) % p;
    for (int i = 2; i <= n; i++)
        ans = max(ans, pre[i - 1] + suf[i]);
    printf("%I64d", ans);
}