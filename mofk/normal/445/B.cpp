#include <cstdio>
using namespace std;
 
int n, m, fa[100], x, y;
 
int gf(int x) {
    if (fa[x] != x) fa[x] = gf(fa[x]);
    return fa[x];
}
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)    fa[i] = i;
    while (m--) {
        scanf("%d%d", &x, &y);
        fa[gf(x)] = gf(y);
    }
    long long ans = (1LL << n);
    for (int i = 1; i <= n; i++)
        if (gf(i) == i) ans /= 2;
    printf("%I64d\n", ans);
}