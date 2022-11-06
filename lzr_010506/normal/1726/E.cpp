#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 998244353;
const int inv2 = (mod + 1) / 2;
int jc[N], ny[N], ny1[N], pw[N], f[N];
int C(int x, int y)
{
    return 1LL * jc[x] * ny[y] % mod * ny[x - y] % mod;
}
int main()
{
    jc[0] = ny[0] = ny[1] = 1;
    pw[0] = 1;
    f[0] = 1;
    for(int i = 1; i <= 600000; i ++)
    {
        pw[i] = 1LL * pw[i - 1] * inv2 % mod;
        jc[i] = 1LL * jc[i - 1] * i % mod;
        if(i > 1) ny[i] = 1LL * (mod - mod / i) * ny[mod % i] % mod;
        f[i] = f[i - 1] + 1LL * f[i - 2] * (i - 1) % mod;
        f[i] %= mod;
    }
    for(int i = 1; i <= 600000; i ++) ny[i] = 1LL * ny[i - 1] * ny[i] % mod;
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n;
        scanf("%d", &n);
        int ans = 0, p = 1;
        for(int i = 0; i * 4 <= n; i ++)
        {
            int nw = f[n - i * 4];
            nw = 1LL * nw * C(n - 2 * i, i * 2) % mod;
            nw = 1LL * nw * p % mod;
            ans = ans + 1LL * nw * jc[i * 2] % mod * pw[i] % mod * ny[i] % mod;
            ans %= mod;
            p = p * 2LL % mod;
        }
        printf("%d\n", ans);
    }
    

}