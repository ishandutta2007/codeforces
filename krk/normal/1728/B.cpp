#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n % 2) printf("%d %d", n - 3, n - 2);
        else printf("%d %d", n - 2, n - 3);
        for (int i = n - 4; i > 0; i--)
            printf(" %d", i);
        printf(" %d %d\n", n - 1, n);
    }
    return 0;
}