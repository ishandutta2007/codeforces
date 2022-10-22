#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, x;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        int sav = sum;
        int pnt = n;
        while (pnt > 0 && sum % x == 0)
            sum -= a[--pnt];
        int res = pnt;
        sum = sav;
        pnt = 0;
        while (pnt < n && sum % x == 0)
            sum -= a[pnt++];
        res = max(res, n - pnt);
        if (!res) res = -1;
        printf("%d\n", res);
    }
    return 0;
}