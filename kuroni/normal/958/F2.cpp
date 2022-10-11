#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N], c[N], ans, n, m, k = 1, j = 1, ok, sum;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &b[i]);
        if (!b[i])
            ++ok;
        sum += b[i];
    }
    for (; ok < m && k <= n; ++k)
        if ((++c[a[k]]) == b[a[k]])
            ++ok;
    if (ok < m && k > n) {
        puts("-1");
        return 0;
    }
    ans = (--k) - sum;
    for (int i = k + 1; i <= (n + 1); ++i) {
        while (k > sum && (c[a[j]] - 1) >= b[a[j]]) {
            --c[a[j++]];
            --k;
        }
        ans = min(ans, k - sum);
        ++c[a[i]];
        ++k;
    }
    printf("%d", ans);
    return 0;
}