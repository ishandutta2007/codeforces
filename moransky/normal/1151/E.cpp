#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 100005;
int n, a[N];
LL ans = 0;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 2; i <= n; i++) {
        if(a[i - 1] < a[i]) ans += (LL)(a[i] - a[i - 1]) * (n - a[i] + 1);
        else ans += (LL)a[i] * (a[i - 1] - a[i]);
    }
    ans += (LL)a[1] * (n - a[1] + 1);
    printf("%lld\n", ans);
    return 0;
}