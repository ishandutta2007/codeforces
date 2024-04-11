#include <bits/stdc++.h>
using namespace std;

int n, s;

int main()
{
    scanf("%d %d", &n, &s);
    if (2 * n <= s) {
        printf("YES\n");
        printf("%d", s - (n - 1));
        for (int i = 0; i < n - 1; i++)
            printf(" 1");
        printf("\n");
        printf("%d\n", n);
    } else printf("NO\n");
    return 0;
}