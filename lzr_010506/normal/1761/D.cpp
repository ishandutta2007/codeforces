#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 1e6 + 10 , mod = 1e9 + 7;

int n , k , jc[MAX_N] , inv[MAX_N] , pw[MAX_N];

int qpow(int a , int t) 
{
    int s = 1;
    for (; t; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod;
    return s;
}

inline int C(int n , int m) 
{
    if (n < m || m < 0) return 0;
    return (ll)jc[n] * inv[m] % mod * inv[n - m] % mod;
}

int calc(int a , int b) 
{
    int r = C(n - b + a , a);
    r = (ll)r * C(b - a - 1 , a - 1) % mod;
    return r;
}

int calc2(int a , int b)
{
    int r = C(n - b + a - 1 , a - 1);
    r = (ll)r * C(b - a , a - 1) % mod;
    return r;
}

int main() 
{
    scanf("%d %d" , &n , &k);
    if (!k) 
    {
        int r = 1;
        for (; n--;) r = 3ll * r % mod;
        printf("%d\n" , r); return 0;
    }

    jc[0] = 1;
    for (int i = 1; i <= n; i ++) jc[i] = (ll)jc[i - 1] * i % mod;
    inv[n] = qpow(jc[n] , mod - 2);
    for (int i = n - 1; i >= 0; i --) inv[i] = (ll)inv[i + 1] * (i + 1) % mod;
    pw[0] = 1;
    for (int i = 1; i <= n; i ++) pw[i] = (3ll * pw[i - 1]) % mod;


    int res = 0;
    for (int a = 1; a <= n; a ++) 
    {
        int b = k + a , lef = k - a;
        if (b > n || lef < 0) break;

        int tmp = (ll)calc(a , b) * pw[lef + n - b] % mod;
        (res += tmp) %= mod;
    }

    for (int a = 1; a <= n; a ++) {
        int b = k + a - 1 , lef = k - a;
        if (b > n || lef < 0) break;

        int tmp = (ll)calc2(a , b) * pw[lef + n - b] % mod;
        (res += tmp) %= mod;
    }
    printf("%d\n" , res);

    return 0;
}