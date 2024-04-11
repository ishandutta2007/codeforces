#include <bits/stdc++.h>
using namespace std;

const int Maxn = 50005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        if (a[1] + a[2] <= a[n])
            printf("1 2 %d\n", n);
        else printf("-1\n");
    }
    return 0;
}