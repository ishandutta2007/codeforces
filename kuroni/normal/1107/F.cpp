#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 505;
const long long INF = 1E18 + 7;

int n;
long long ori = 0, ans = -INF, val[N], f[N][N];

struct SCard
{
    int a, b, k;
} a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].k);
    sort(a + 1, a + n + 1, [](const SCard &a, const SCard &b) {
        return a.b > b.b;
    });
    for (int i = 1; i <= n; i++)
        ori += (val[i] = max(0LL, a[i].a - 1LL * a[i].b * a[i].k));
    for (int i = 0; i < N; i++)
        fill(f[i], f[i] + N, -INF);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i; j++)
            ans = max(ans, f[i][j] = (j == 0 ? ori : max(f[i - 1][j - 1] + a[i].a - 1LL * a[i].b * (j - 1) - val[i], f[i - 1][j])));
    printf("%lld", ans);
}