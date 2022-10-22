#include<bits/stdc++.h>
#define int long long
#define maxn (N - 10)
using namespace std;
const int N = 1e5 + 10;
const int mod = 998244353;

int m;
int f[N];
int vis[N], p[N], mu[N], tot = 0;
int pw1[N], pw2[N];
int add(int x) {return x >= mod ? x - mod : x;}
int sub(int x) {return x < 0 ? x + mod : x;}
void Add(int &x, int y){if((x += y) >= mod && (x -= mod));}
void Sub(int &x, int y){if((x -= y) < 0 && (x += mod));}
int qpow(int a, int b)
{
    int res = 1;
    for(; b > 0; b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod;
    return res;
}
void sieve(int n)
{
    mu[1] = vis[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(!vis[i]) mu[i] = -1, p[++tot] = i;
        for(int j = 1; j <= tot && p[j] * i <= n; j++)
        {
            vis[i * p[j]] = 1;
            if(i % p[j] == 0)
            {
                mu[i * p[j]] = 0;
                break;
            }
            mu[i * p[j]] = - mu[i];
        }
    }
    return;
}
int Pro(int n)
{
    if(n <= 0) return 0;
    return 1ll * n % mod * qpow(2, n - 1) % mod;
}
signed main()
{
    scanf("%lld", &m);
    sieve(maxn);
    for(int i = 1; i <= m; i++)
    {
        int x, c;
        scanf("%lld%lld", &x, &c);
        f[x] = c;
    }
    int ans = 0;
    for(int i = 1; i <= maxn; i++)
    {
        int s = 0, t = 0, cnt = 0;
        for(int j = i; j <= maxn; j += i)
        {
            cnt += f[j];
            Add(s, 1ll * f[j] % mod * j % mod);
            Add(t, 1ll * f[j] % mod * j % mod * j % mod);
        }
        int sum = 0;
        Add(sum, 1ll * t * Pro(cnt - 1) % mod);
        s = 1ll * s * s % mod;
        Sub(s, t);
        if(cnt >= 2) Add(sum, 1ll * s * add(Pro(cnt - 2) + qpow(2, cnt - 2)) % mod);
        if(mu[i] == 1) Add(ans, sum);
        if(mu[i] == -1) Sub(ans, sum);
    }
    printf("%lld\n", ans);
    return 0;
}