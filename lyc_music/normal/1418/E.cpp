//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define foor(i,a,b) for (int i=(a);i<=(b);i++)
#define door(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define IOS ios::sync_with_stdio(false)
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
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,q,a[N],s[N],x,y;
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int wrk(int x)
{
	return quickPower(x,mod-2);
}
signed main()
{
	n=read();q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i],s[i]%=mod;
	s[n+1]=s[n];
	for (int i=1;i<=q;i++)
	{
		x=read(),y=read();
		int l=lower_bound(a+1,a+n+1,y)-a,c=n-l+1;
		if (c<x) writeln(0);
		else
			writeln((s[l-1]*(c+1-x)%mod*wrk(c+1)%mod+(s[n]-s[l-1]+mod)%mod*(c-x)%mod*wrk(c)%mod)%mod);
	}
}
/*

*/