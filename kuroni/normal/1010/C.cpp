#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, a, ans = 0;

int main()
{
    scanf("%d%d", &n, &k);
    while (n--)
    {
        scanf("%d", &a);
        ans = __gcd(ans, __gcd(a, k));
    }
    printf("%d\n", k / ans);
    for (int i = 0; i < k; i += ans)
        printf("%d ", i);
}