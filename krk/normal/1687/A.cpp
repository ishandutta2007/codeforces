#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n, k;
ll a[Maxn];

ll Sum(ll a, ll b) { return (a + b) * (b - a + 1) / 2; }

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%I64d", &a[i]);
            a[i] += a[i - 1];
        }
        if (k <= n) {
            ll best = 0;
            for (int i = k; i <= n; i++)
                best = max(best, a[i] - a[i - k]);
            best += Sum(0, k - 1);
            printf("%I64d\n", best);
        } else {
            ll best = a[n];
            best += Sum(k - n, k - 1);
            printf("%I64d\n", best);
        }
    }
    return 0;
}