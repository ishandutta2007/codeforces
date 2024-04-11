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
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
const int mod = 1e9 + 7;
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
const int maxn = 1e6 + 10;
int y[maxn], ifac[maxn];
int lfac[maxn], rfac[maxn];
signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= m + 2; ++i)
    {
        y[i] = y[i - 1] + qpow(i, m);
        y[i] %= mod;
    }
    m = m + 2;
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= m; ++i)
    {
        ifac[i] = ifac[mod % i] * (mod - mod / i) % mod;
    }
    for (int i = 2; i <= m; ++i)
    {
        ifac[i] = (ifac[i] * ifac[i - 1]) % mod;
    }
    lfac[0] = rfac[m + 1] = 1;
    for (int i = 1; i <= m; ++i)
    {
        lfac[i] = (lfac[i - 1] * (n - i)) % mod;
    }
    for (int i = m; i >= 0; --i)
    {
        rfac[i] = (rfac[i + 1] * (n - i)) % mod;
    }
    int cnt = 0;
    for (int i = 1; i <= m; ++i)
    {
        cnt = (cnt + y[i] * lfac[i - 1] % mod * rfac[i + 1] % mod * ifac[i - 1] % mod * ((m - i) & 1 ? (mod - ifac[m - i]) : ifac[m - i])) % mod;
    }
    cout << (cnt + mod) % mod;
}