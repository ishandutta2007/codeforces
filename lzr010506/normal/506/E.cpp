#include <bits/stdc++.h>
using namespace std;
#define N 410
#define mod 10007
typedef int ll;
struct marix
{
    int r,c;ll a[N][N];
    inline void init(int x)
    {
    	r = c = x;
    	for (int i = 1; i <= x; i ++) 
    		a[i][i] = 1;
    }
}x,y;
int n, m;
inline void muti(marix &ans,const marix x,const marix y)
{
    ans.r=ans.c=x.r;
    for (int i = 1; i <= x.r; i ++) 
        for (int j = i; j <= y.c; j ++) 
        {
            int tmp = 0;
            for (int k = i; k <= j; k ++) 
                (tmp += x.a[i][k] * y.a[k][j]) %= mod;
            ans.a[i][j] = tmp;
        }
}
inline void power(marix &ans,marix x,int y) 
{
    ans.init(x.r);
    for (; y; y >>= 1) 
    {
        if (y & 1) muti(ans,ans,x);
        muti(x,x,x);
    }
}
ll f[210][210][210];
char s[N];
inline ll calc(int l,int r,int x) 
{
    ll &u = f[x][l][r];
    if (u != -1) return u;
    u = 0;
    if (l == r) return u = x == 0;
    if (s[l] == s[r]) 
    {
        if (l + 1 == r) return u = x == 0;
        return u = calc(l + 1, r - 1, x);
    }
    if (x > 0) return u = (calc(l + 1, r, x - 1) + calc(l, r - 1, x - 1)) % mod;
    return u;
}
int main()
{
    memset(f, -1 ,sizeof(f));
    scanf("%s", s + 1);
    scanf("%d", &n);
    m = strlen(s + 1);
    n += m;
    int l = (n + 1) / 2, n24 = m - 1, n25 = (m + 1) / 2, n26 = n25;
    x.r = x.c = n24 + n25 + n26;
    for (int i = 1; i <= n24; i ++) 
    	x.a[i][i] = 24, x.a[i][i + 1] = 1;
    for (int i = n24 + 1; i <= n25 + n24; i ++) x.a[i][i] = 25, x.a[i][i + n25] = 1;
    for (int i = n24 + n25 + 1; i <= n25 + n24 + n26; i ++) x.a[i][i] = 26;
    for (int i = n24 + 1; i < n25 + n24; i ++) x.a[i][i + 1] = 1;
    marix y;
    power(y, x, l - 1);
    muti(x, y, x);
    ll ans;
    for (int i = 0; i <= n24; i ++) 
    {
        int j = (m - i + 1) / 2, k = l - i - j;
        if (k < 0) continue;
        ll sum = calc(1, m, i);
        (ans += sum * x.a[n24 - i + 1][n24 + j + n25] % mod) %= mod;
        if ((n & 1) && (m - i & 1 ^ 1))  
            (ans = ans - sum*y.a[n24 - i + 1][n24 + j] % mod + mod) %= mod;
    }
    printf("%d\n",ans);
    return 0;
}