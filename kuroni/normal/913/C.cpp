#include <iostream>
#include <cstdio>
using namespace std;

int n, L;
long long a[32], cur = 0, ans = 1E18;

int main()
{
    scanf("%d%d", &n, &L);
    for (int i = 0; i < n; i++)
    {
        scanf("%I64d", a + i);
        if (i)
            a[i] = min(a[i], a[i - 1] << 1);
    }
    for (int i = n; i < 32; i++)
        a[i] = a[i - 1] << 1;
    for (int i = 31; i >= 0; i--)
        if (L >> i & 1)
            cur += a[i];
        else
            ans = min(ans, cur + a[i]);
    printf("%I64d", min(ans, cur));
}