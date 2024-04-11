#include <cstdio>
#include <algorithm>
using namespace std;
int n, x, a[100010], b[100010], ans, l, r;
int main() {
    scanf("%d %d", &n, &x);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=0; i<n; i++) scanf("%d", &b[i]);
    sort(a, a+n); reverse(a, a+n); sort(b, b+n);
    while (r<n) {
        if (a[l]+b[r]>=x) ans++, l++, r++;
        else r++;
    }
    printf("1 %d\n", ans);
}