#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, q;
int a[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int cur = 0;
        for (int i = n - 1; i >= 0; i--)
            if (cur >= a[i]) res[i] = 1;
            else if (cur < q) { res[i] = 1; cur++; }
            else res[i] = 0;
        for (int i = 0; i < n; i++)
            printf("%d", res[i]);
        printf("\n");
    }
    return 0;
}