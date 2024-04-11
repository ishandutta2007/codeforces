#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;
const int Inf = 1000000000;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        int res = -Inf;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            res = max(res, a[i] - a[(i + 1) % n]);
        int mn = Inf;
        for (int i = 0; i + 1 < n; i++)
            mn = min(mn, a[i]);
        res = max(res, a[n - 1] - mn);
        int mx = -Inf;
        for (int i = 1; i < n; i++)
            mx = max(mx, a[i]);
        res = max(res, mx - a[0]);
        printf("%d\n", res);
    }
    return 0;
}