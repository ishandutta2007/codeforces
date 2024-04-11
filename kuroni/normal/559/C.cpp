#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;
struct TPoint
{
    int x, y;
} a[2005];
long long fact[200005], inv[200005], ans[2005];
int i, j, n, h, w;

inline bool operator < (const TPoint &a, const TPoint &b)
{
    return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

long long pow(long long a, int m)
{
    if (m == 1)
        return a;
    long long tmp = pow(a, m / 2);
    tmp = (tmp * tmp) % mod;
    if (m & 1)
        tmp = (tmp * a) % mod;
    return tmp;
}

void init()
{
    fact[0] = inv[0] = 1;
    for (int i = 1; i <= h + w; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    inv[h + w] = pow(fact[h + w], mod - 2);
    for (i = h + w; i > 1; i--)
        inv[i - 1] = (inv[i] * i) % mod;
}

long long C(int m, int n)
{
    return ((fact[m + n] * inv[m]) % mod * inv[n]) % mod;
}

int main()
{
    scanf("%d%d%d", &h, &w, &n); ++n;
    init();
    for (i = 1; i < n; i++)
        scanf("%d%d", &a[i].x, &a[i].y);
    a[n].x = h; a[n].y = w;
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i++)
    {
        ans[i] = C(a[i].x - 1, a[i].y - 1);
        for (j = 1; j < i; j++)
            if (a[j].y <= a[i].y)
            {
                ans[i] -= ans[j] * C(a[i].x - a[j].x, a[i].y - a[j].y);
                ans[i] %= mod;
            }
        ans[i] = (ans[i] + mod) % mod;
    }
    printf("%I64d", ans[n]);
}