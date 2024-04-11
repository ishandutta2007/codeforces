#include <cstdio>

int main()
{
    int n, d, t, a = -2;
    scanf("%d%d", &n, &d); d += 10;
    while (n--)
        scanf("%d", &t), a += 2, d -= t + 10;
    printf("%d", (d >= 0) ? a + d / 5 : -1);
}