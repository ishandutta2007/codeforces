#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 105;

int n, d, m, a[MAXN];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &d);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    sort(a, a + n);
    int ans = 0;
    for (int i=0; i<min(n, m); i++) ans += a[i];
    if (m > n) ans -= d * (m - n);
    printf("%d\n", ans);
    return 0;
}