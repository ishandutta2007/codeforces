#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ll sum = 0;
        ll res = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        for (int i = 0; i < n; i++) {
            res -= (ll(i) * a[i] - sum);
            sum += a[i];
        }
        res += a[n - 1];
        printf("%I64d\n", res);
    }
    return 0;
}