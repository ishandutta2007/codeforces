//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 1000000007
#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int fac[N],inv[N],n,T,l,r;
int C(int x,int y)
{
    if (x<y||x<0||y<0) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int quickPower(int x,int y)
{
	int res=1;
	x%=mod;
	while (y>0)
	{
		if (y%2==1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int work(int x)
{
	if (x<=0) return 0;
	int a=x+l-1,b=max(n-r+x,0ll);a=max(a,0ll);
	if (a+b>n) return 0;
	if(n%2==1) return (C(n-a-b,n/2-a)+C(n-a-b,n/2-a+1))%mod;
	return C(n-a-b,n/2-a)%mod;
}
signed main()
{
	n=200000;
	fac[0]=inv[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod,inv[i]=quickPower(fac[i],mod-2);
	T=read();
	while (T--)
	{
		n=read(),l=read(),r=read();
		int ans=0;
		for (int i=min(-l,r-n);i<=min(n-l,r);i++) ans=(ans+work(i))%mod;
		int x=C(n,n/2);
        if (n%2==1) x+=C(n,n/2+1),x%=mod;
		ans=(ans+max(min(-l,r-n)-1,0ll)*x%mod)%mod;
		writeln(ans);
	}	
}
/*

*/