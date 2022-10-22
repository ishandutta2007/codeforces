#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int res = 100000;
        for (int i = 0; i + 1 < n; i++)
            res = min(res, a[i + 1] - a[i]);
        printf("%d\n", res);
    }
    return 0;
}