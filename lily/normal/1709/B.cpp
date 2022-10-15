#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2e5 + 5;

int n, m;
int a[N];
LL f[N], b[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + max(a[i - 1] - a[i], 0);
    for (int i = n; i >= 0; i--) b[i] = b[i + 1] + max(a[i + 1] - a[i], 0);
    for (int i = 1; i <= m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l <= r) printf("%lld\n", f[r] - f[l]);
        else printf("%lld\n", b[r] - b[l]);
    }
}