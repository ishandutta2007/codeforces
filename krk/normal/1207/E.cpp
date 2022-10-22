#include <bits/stdc++.h>
using namespace std;

int main()
{
    printf("?");
    for (int i = 0; i < 100; i++)
        printf(" %d", i);
    printf("\n"); fflush(stdout);
    int r1; scanf("%d", &r1); r1 >>= 7;
    printf("?");
    for (int i = 1; i <= 100; i++)
        printf(" %d", (i << 7));
    printf("\n"); fflush(stdout);
    int r2; scanf("%d", &r2);
    int all = (1 << 7) - 1;
    int res = ((r2 & all) ^ (r1 << 7));
    printf("! %d\n", res); fflush(stdout);
    return 0;
}