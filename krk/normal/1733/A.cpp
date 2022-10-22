#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 105;

int T;
int n, k;
ll a[Maxn];
ll mx[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < k; i++)
            mx[i] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%I64d", &a[i]);
            mx[i % k] = max(mx[i % k], a[i]);
        }
        ll res = 0;
        for (int i = 0; i < k; i++)
            res += mx[i];
        printf("%I64d\n", res);
    }
    return 0;
}