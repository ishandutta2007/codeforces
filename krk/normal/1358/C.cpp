#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int x1, y1, x2, y2;

ll Sum(ll fir, ll lst) { return (fir + lst) * (lst - fir + 1) / 2ll; }

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int n = x2 - x1 + 1, m = y2 - y1 + 1;
        if (n > m) swap(n, m);
        int rem = (n + m - 1 - 2 * (n - 1));
        ll res = 1ll + 2ll * Sum(0, n - 2) + ll(rem) * (n - 1);
        printf("%I64d\n", res);
    }
    return 0;
}