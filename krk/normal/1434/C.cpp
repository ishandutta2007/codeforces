#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int a, b, c, d;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a > ll(b) * c) printf("-1\n");
        else if (d > c) printf("%d\n", a);
        else {
            int mid = (2ll * ll(a) / (ll(d) * b) - 1) / 2ll;
            ll mx = 0;
            for (int t = mid - 5; t <= mid + 5; t++) if (ll(t) * d <= c && ll(t) >= 0)
                mx = max(mx, ll(t + 1) * a - ll(t) * (t + 1) / 2 * d * b);
            printf("%I64d\n", mx);
        }
    }
    return 0;
}