#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        n /= 2;
        if (n % 2) { printf("NO\n"); continue; }
        printf("YES\n");
        for (int i = 0; i < n / 2; i++)
            printf("%d ", 2 * i + 2);
        for (int i = n / 2; i < n; i++)
            printf("%d ", 2 * i + 4);
        for (int i = 0; i < n; i++)
            printf("%d%c", 2 * i + 3, i + 1 < n? ' ': '\n');
    }
    return 0;
}