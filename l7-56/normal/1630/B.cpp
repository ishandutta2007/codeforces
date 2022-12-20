#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n,k,a[maxn],cnt[maxn];

void work() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) cnt[i] = 0;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]), cnt[a[i]]++;
    int ax = 1, ay = n, lim = (k + n + 1) >> 1;
    for (int x = 1, y = 0, sum = 0; x <= n; ) {
        while (y <= n && sum < lim) sum += cnt[++y];
        if (sum < lim || y > n) break;
        if (ay - ax > y - x) ax = x, ay = y;
        sum -= cnt[x++];
    }
    printf("%d %d\n", ax, ay);
    int lst = 0;
    for (int i = 1, tot = 1; i <= n && tot < k; ++i) {
        a[i] = a[i - 1] - 1 + 2 * (ax <= a[i] && a[i] <= ay);
        if (a[i] == tot) printf("%d %d\n", lst + 1, i), ++tot, lst = i;
    }
    printf("%d %d\n", lst + 1, n);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) work();
    return 0;
}