#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;
struct TPoint
{
    int x, y;
} a[2005];
long long fact[200005], inv[200005], f[2005], g[2005], ans = 0;
int i, j, n, m, k, s;

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

long long C(int m, int n);

void init()
{
    fact[0] = inv[0] = 1;
    for (i = 1; i <= m + n; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    inv[m + n] = pow(fact[m + n], mod - 2);
    for (i = m + n; i > 1; i--)
        inv[i - 1] = (inv[i] * i) % mod;
    for (i = 1; i <= k; i++)
        g[i] = C(a[i].x - 1, a[i].y - 1);
}

long long C(int m, int n)
{
    return ((fact[m + n] * inv[m]) % mod * inv[n]) % mod;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &s); ++k;
    for (i = 1; i < k; i++)
        scanf("%d%d", &a[i].x, &a[i].y);
    a[k].x = n; a[k].y = m;
    sort(a + 1, a + k + 1);
    init();
    while (s != 1)
    {
        for (i = 1; i <= k; i++)
        {
            f[i] = g[i];
            for (j = 1; j < i; j++)
                if (a[j].y <= a[i].y)
                {
                    f[i] -= f[j] * C(a[i].x - a[j].x, a[i].y - a[j].y);
                    f[i] %= mod;
                }
            f[i] = (f[i] + mod) % mod;
            g[i] = ((g[i] - f[i]) % mod + mod) % mod;
        }
        ans = (ans + f[k] * s) % mod;
        s -= (s >> 1);
    }
    ans = (ans + g[k]) % mod;
    ans = (((ans * fact[m - 1]) % mod * fact[n - 1]) % mod * inv[m + n - 2]) % mod;
    printf("%I64d", ans);
}