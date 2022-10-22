#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n == 3) { printf("-1\n"); continue; }
        printf("%d %d", n, n - 1);
        for (int i = 1; i < n - 1; i++)
            printf(" %d", i);
        printf("\n");
    }
    return 0;
}