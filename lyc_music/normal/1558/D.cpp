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
#define mod 998244353
#define int ll
#define N 400005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int fac[N],inv[N],T,n,m,a[N],b[N],p[N],c[N],ls[N],cnt,le[N],now;
int query(int x)
{
	int now=0;
	for (int i=18;i>=0;i--)
	{
		if (now+(1<<i)>n) continue;
		if (c[now+(1<<i)]<=x)
		{
			now+=(1<<i);
			x-=c[now];
		}
	}
	return now+1;
}
void update(int x,int y)
{
	while (x<=n) c[x]+=y,x+=(x&(-x));
}
ll quickPower(int x,int y)
{
	int res=1;
	while (y>0)
	{
		if (y%2) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int C(int x,int y)
{
	return fac[x]*inv[x-y]%mod*inv[y]%mod;
}
bool cmp(int x,int y)
{
	return p[x]<p[y];
}
signed main()
{
	fac[0]=inv[0]=1;
	n=4e5;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	int i=n;
	inv[i]=quickPower(fac[i],mod-2);
	for (int i=n-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
	for (int i=1;i<=n;i++) update(i,1);
	T=read();
	while (T--)
	{
		n=read(),m=read();cnt=0;
		for (int i=1;i<=m;i++)
		{
			a[i]=read(),b[i]=read();
			p[a[i]]=b[i];
			ls[a[i]]=1;
		}
		now=0;
		for (int i=m;i>=1;i--)
		{
//			if (i!=m) now+=a[i+1]-a[i]-1;
			p[a[i]]=query(b[i]-1);
			update(p[a[i]],-1);
		}
		sort(a+1,a+m+1,cmp);
		cnt=m;
		for (int i=2;i<=m;i++)
		{
			if (p[a[i]]==p[a[i-1]]+1&&a[i]>a[i-1]) cnt--;
		}
		for (int i=m;i>=1;i--)
		{
			update(p[a[i]],1);
		}
		writeln(C(2*n-1-cnt,n));
//		for (int i=1;i<=n;i++) le[i]=p[i]=ls[i]=0;
	}
		
}
/*
1391738132
8 4
3 1
6 1
7 5
8 1
*/