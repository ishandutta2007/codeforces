#include <iostream>
#include <cstdio>
#include <algorithm>
#define mod 1000000007
using namespace std;

int n, i;
long long add = 0, mi = 0, m[300005], a[300005];

int main()
{
    scanf("%d", &n);
    m[0] = 1;
    for (i = 1; i < n; i++)
        m[i] = (m[i - 1] * 2) % mod;
    for (i = 0; i < n; i++)
        scanf("%I64d", a + i);
    sort(a, a + n);
    for (i = 0; i < n; i++)
    {
        add += a[i] * (m[i] - 1);
        add %= mod;
        mi += a[i] * (m[n - 1 - i] - 1);
        mi %= mod;
    }
    printf("%I64d", ((add - mi) % mod + mod) % mod);
}