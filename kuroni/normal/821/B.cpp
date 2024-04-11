#include <iostream>
#include <cstdio>
using namespace std;

long long m, b, ans = 0, x, y;

int main()
{
    scanf("%I64d%I64d", &m, &b);
    for (y = 0; y <= b; y++)
    {
        x = (b - y) * m;
        ans = max(ans, x * (x + 1) / 2 * (y + 1) + y * (y + 1) / 2 * (x + 1));
    }
    printf("%I64d", ans);
}