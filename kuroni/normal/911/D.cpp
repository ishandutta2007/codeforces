#include <iostream>
#include <cstdio>
using namespace std;

int cur = 0, n, m, l, r, a[1505];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            cur ^= (a[i] > a[j]);
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d%d", &l, &r);
        cur ^= (((r - l) * (r - l + 1)) >> 1) & 1;
        printf("%s\n", cur ? "odd" : "even");
    }
}