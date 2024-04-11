#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
int n, H;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &H);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int res = H / (a[n - 1] + a[n - 2]);
        H -= res * (a[n - 1] + a[n - 2]);
        res *= 2;
        if (H > 0) { res++; H -= a[n - 1]; }
        if (H > 0) res++;
        printf("%d\n", res);
    }
    return 0;
}