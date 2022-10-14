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
#define rd(x) x=read()
#define op(x) printf("%lld",x)
#define ops(x) printf("%lld ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
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
const int maxn=3e6+20;
int fac[maxn],inv[maxn];
int ifac[maxn];
int qpow(int a,int b=mod-2)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int maxm;
int f[maxn],g[maxn],h[maxn];
signed main()
{
	int q;
	n=read(),q=read();
	fac[0]=1;
	maxm=3*n+5;
	up(i,1,maxm)fac[i]=(fac[i-1]*i)%mod;
	inv[0]=1,inv[1]=1;ifac[maxm]=qpow(fac[maxm]);
	up(i,2,maxm)
	{
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	}
	down(i,maxm-1,0)ifac[i]=ifac[i+1]*(i+1)%mod;
	int pp=n*inv[2]%mod;
	f[1]=(3*n-1)*pp%mod;
	g[1]=(3*n+1)*pp%mod;
	h[1]=(3*n+3)*pp%mod;
	up(i,2,maxm)
	{
		int x=i*f[i-1]%mod;
		int y=i*g[i-1]%mod;
		int z=fac[3*n+1]*ifac[3*n-i]%mod*inv[i+1]%mod;
		int qwq=z+mod-(x*2+y)%mod;
		qwq*=inv[3];
		qwq%=mod;
		f[i]=qwq;
		g[i]=(f[i]+x)%mod;
		h[i]=(f[i]+x+y)%mod;
	}
	up(i,1,q)
	{
		int x=read();
		printf("%lld\n",(h[x]*ifac[x])%mod);
	}
}