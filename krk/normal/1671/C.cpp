#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n, x;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        ll sum = 0;
        for (int i = 0; i < n; i++)
            sum += a[i];
        ll res = 0, add = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (x >= sum + (i + 1) * add) {
                ll tims = (x - sum - (i + 1) * add) / (i + 1);
                res += (tims + 1ll) * (i + 1);
                add += tims + 1ll;
            }
            sum -= a[i];
        }
        printf("%I64d\n", res);
    }
    return 0;
}