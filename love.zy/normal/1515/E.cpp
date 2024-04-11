/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-03
File: E.cpp
*****************************************/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")  
#include<bits/stdc++.h>

using namespace std;

const double eps = 1e-10;
const double pi = 3.1415926535897932384626433832795;
const double eln = 2.718281828459045235360287471352;

#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "[%s] " fmt "\n", \
    __func__, ##__VA_ARGS__)
#else
# define _debug(...) ((void) 0)
#endif

#define IN freopen("E.in", "r", stdin)
#define OUT freopen("E.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define prcas printf("Case #%d: ", cas)
#define pncas printf("Case #%d:\n", cas)
#define lowbit(x) ((x) & (-(x)))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

const int maxn = 405;
int c[maxn][maxn], dp[maxn][maxn], na[maxn];
int mod, n;

int combine(int x, int y) 
{
    if(x < 0 || y < 0) return 0;
    return (c[x][y] + c[y][x]) % mod; 
}

int main()
{	
    scanf("%d%d", &n, &mod);
    for(int i = 0; i <= n; ++ i)
        for(int j = 0; j <= n; ++ j)
        {
            if(i * j == 0) 
            { 
                c[i][j] = j == 0 ? 0 : 1; 
                continue; 
            }
            if(j == 1) { c[i][j] = 1; continue; }
            for(int k = 0; k <= i; ++ k)
                (c[i][j] += c[i - k][j - 1]) %= mod;
        }
    for(int i = 1; i <= n; ++ i)
        for(int k = 1; k <= i; ++ k)
            (na[i] += combine(k - 1, i - k)) %= mod;
    na[1] = 1; dp[1][0] = 1; dp[2][0] = 2;
    for(int i = 3; i <= n; ++ i)
    {
        dp[i][0] = na[i];
        for(int j = 1; j <= i - 2; ++ j)
            for(int k = 2; k < i; ++ k)
            {
                int num = dp[k - 1][j - 1];
                num = 1ll * num * na[i - k] % mod;
                num = 1ll * num * combine(k - j, i - k) % mod;
                (dp[i][j] += num) %= mod;
            }
    }
    int ans = 0;
    for(int i = 0; i <= n; ++ i) (ans += dp[n][i]) %= mod;
    printf("%d\n", ans);
    return 0;
}