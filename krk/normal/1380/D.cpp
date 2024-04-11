#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const ll Inf = 1000000000000000000ll;

int n, m;
int x, k, y;
ll best[Maxn], an[Maxn];
int a[Maxn];
int b[Maxn];

ll Solve()
{
    int pnt = 0, mx = 0;
    while (pnt < n && a[pnt] != b[0])
        mx = max(mx, a[pnt++]);
    if (pnt >= n) return Inf;
    ll res = 0;
    if (mx <= b[0]) res += an[pnt];
    else res += best[pnt];
    for (int i = 1; i < m && res < Inf; i++) {
        int oldpnt = pnt;
        mx = 0;
        while (pnt < n && a[pnt] != b[i])
            mx = max(mx, a[pnt++]);
        if (pnt >= n) return Inf;
        if (mx <= max(b[i - 1], b[i])) res += an[pnt - oldpnt - 1];
        else res += best[pnt - oldpnt - 1];
    }
    if (res >= Inf) return Inf;
    mx = 0;
    int oldpnt = pnt;
    while (pnt < n)
        mx = max(mx, a[pnt++]);
    if (mx <= b[m - 1]) res += an[n - oldpnt - 1];
    else res += best[n - oldpnt - 1];
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &x, &k, &y);
    fill(best, best + Maxn, Inf);
    fill(an, an + Maxn, Inf);
    best[0] = an[0] = 0;
    for (int i = 1; i < Maxn; i++) {
        best[i] = i >= k? x + an[i - k]: Inf;
        an[i] = min((i >= k? x + an[i - k]: Inf), y + an[i - 1]);
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int j = 0; j < m; j++)
        scanf("%d", &b[j]);
    auto res = Solve();
    printf("%I64d\n", res >= Inf? -1: res);
    return 0;
}