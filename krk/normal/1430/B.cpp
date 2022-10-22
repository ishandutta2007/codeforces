#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n, k;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        ll res = 0;
        for (int i = 0; i <= k; i++)
            res += a[n - 1 - i];
        printf("%I64d\n", res);
    }
    return 0;
}