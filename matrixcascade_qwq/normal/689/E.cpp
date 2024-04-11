/*
qwq
*/


//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define edl puts("")
#define mc cerr<<"qwq\n"
#define error goto gg
#define def gg:
#define rd(x) x=read()
#define opl(x) printf("%lld",x)
#define opls(x) printf("%lld ",x)
#define opd(x) printf("%d",x)
#define opds(x) printf("%d ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
using namespace std;
int n, m, k;
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
const int mod=1e9+7;
const int maxn = 500001;
int fac[500005], ifac[500005];
int l[maxn],r[maxn];
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
int inv(int k)
{
    return qpow(k, mod - 2);
}
void pre()
{
    fac[0] = 1;
    for (int i = 1; i <= maxn; ++i)
        fac[i] = fac[i - 1] * i % mod;
    ifac[maxn] = inv(fac[maxn]);
    for (int i = maxn - 1; i >= 0; --i)
        ifac[i] = ifac[i + 1] * (i + 1) % mod;
}
int C(int nn, int mm)
{
    return fac[nn] * ifac[mm] % mod * ifac[nn - mm] % mod;
}
int invC(int nn, int mm)
{
    return ifac[nn] * fac[mm] % mod * fac[nn - mm] % mod;
}
int b[maxn];
signed main()
{
	int T=1;
	while(T--)
	{
		pre();
		n=read(),k=read();
		map<int,int>mp;
		map<int,int>pm;
		up(i,1,n)l[i]=read(),r[i]=read(),++mp[l[i]],--mp[r[i]+1],pm[l[i]]=1,pm[r[i]+1]=1;
		int nw=0;
		int pre=0;
		for(auto to:pm)
		{
			int ww=to.first;
			b[nw]+=ww-pre;
			pre=ww;
			nw+=mp[ww];
		}
		int ans=0;
		up(i,k,n)
		{
			ans+=C(i,k)*b[i]%mod;ans%=mod;
		}cout<<ans;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/