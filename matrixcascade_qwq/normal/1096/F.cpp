#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {//
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
const int mod = 998244353;
int a[201010], tot = 0, t[202020];
int cnt = 0;
int lowbit(int x) { return x & (-x); }
int bit[202011], b[202020];
void upt(int x, int y)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        bit[i] += y;
    }
}
int qry(int x)
{
    int nw = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        nw += bit[i];
    }
    return nw;
}
int qpow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
signed main()
{
    n = read();
    t[0] = 0;
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = n; i >= 1; --i)
    {
        if (a[i] == -1)
        {
            ++tot;
        }
        else
        {
            cnt += qry(a[i]);
            upt(a[i], 1);
            t[a[i]] = 1;
        }
    }
    int T = 0;
    int anss = 0;
    int inv;
    cnt += tot * (tot - 1) % mod * qpow(4, mod - 2) % mod;
    if (tot > 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (!t[i])
                b[++T] = i;
        }
        inv = qpow(T, mod - 2);
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == -1)
                continue;
            a[i] = inv * (lower_bound(b + 1, b + T + 1, a[i]) - b - 1) % mod;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == -1)
                continue;
            anss -= a[i] - 1;
            anss += mod;
            anss %= mod;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == -1)
            {
                cnt += anss;
                cnt %= mod;
            }
            else
            {
                anss += 2 * a[i] - 1;
                anss %= mod;
            }
        }
    }
    cout << cnt % mod << endl;
}