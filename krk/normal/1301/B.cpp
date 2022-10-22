#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000007;
const int Maxn = 100005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int mn = Inf, mx = -Inf;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) if (a[i] == -1) {
            if (i > 0 && a[i - 1] != -1) {
                mn = min(mn, a[i - 1]);
                mx = max(mx, a[i - 1]);
            }
            if (i + 1 < n && a[i + 1] != -1) {
                mn = min(mn, a[i + 1]);
                mx = max(mx, a[i + 1]);
            }
        }
        if (mn == Inf) mn = mx = 0;
        int res = (mx - mn + 1) / 2;
        for (int i = 0; i + 1 < n; i++) if (a[i] != -1 && a[i + 1] != -1)
            res = max(res, abs(a[i + 1] - a[i]));
        printf("%d %d\n", res, (mn + mx) / 2);
    }
    return 0;
}