#include <cstdio>

int main()
{
    int n, k, i;
    scanf("%d%d", &n, &k);
    printf("%d\n", 2 * ((n - 3) / k + 1) + ((n - 2) % k == 0));
    for (i = 2; i <= n; i++)
        printf("%d %d\n", ((i - k <= 0) ? 1 : i - k), i);
}