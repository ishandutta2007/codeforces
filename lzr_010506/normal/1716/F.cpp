#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2010;
const int mod = 998244353;
int qpow(int x, int times)
{
    int res = 1;
    while(times)
    {
        if(times & 1) res = 1LL * res * x % mod;
        times >>= 1;
        x = 1LL * x * x % mod;
    }
    return res;
}
int s[N][N];
int main()
{
    s[0][0] = 1;
    for(int i = 1; i <= N - 5; i ++)
        for(int j = 1; j <= i; j ++)
            s[i][j] = (1LL * j * s[i - 1][j] + s[i - 1][j - 1]) % mod;
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        ll ans = 0, a = (m + 1) / 2, pw_a, pw_m, inv_m, fact;
        pw_a = 1; pw_m = qpow(m, n);
        inv_m = qpow(m, mod- 2);
        fact = 1;
        for(int i = 1; i <= k; i ++)
        {
            ll t = 1;
            pw_a = pw_a * a % mod;
            pw_m = pw_m * inv_m % mod;
            fact = fact * (n - i + 1) % mod;
            t = 1LL * fact * pw_a % mod * pw_m % mod;
            t = t * s[k][i] % mod;
            ans = (ans + t) % mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}