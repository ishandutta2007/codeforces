#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const ll Inf = 9000000000000000000ll;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        ll A = 0, B = 0;
        for (int i = 0; i + 1 < n; i++) {
            A += ll(a[i]) * a[n - 1];
            B += (a[i] + a[n - 1]);
        }
        if (B < 0) { printf("INF\n"); continue; }
        ll res = A + ll(-a[n - 1]) * B;
        for (int i = n - 2; i >= 0; i--) {
            res = max(res, A + ll(-a[i + 1]) * B);
            res = max(res, A + ll(-a[i]) * B);
            if (i) {
                A -= ll(a[i]) * a[n - 1];
                B -= (a[i] + a[n - 1]);
                A += ll(a[i]) * a[0];
                B += (a[i] + a[0]);
            }
        }
        if (B > 0) { printf("INF\n"); continue; }
        res = max(res, A + ll(-a[0]) * B);
        printf("%I64d\n", res);
    }
    return 0;
}