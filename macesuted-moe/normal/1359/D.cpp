#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int a[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int ans = 0;
    for (int i = 1; i < 31; i++) {
        int tot = 0;
        for (int j = 1; j <= n; j++) {
            tot += a[j];
            if (a[j] > i) tot = 0;
            tot = max(tot, 0);
            ans = max(ans, tot - i);
        }
    }
    printf("%d\n", ans);
    return 0;
}