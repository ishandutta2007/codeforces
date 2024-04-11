//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 1000000007
#define int ll
#define N 2005
#define M 1000ll
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,R,x[N],y[N],b[N];
int al[N],ar[N],bl[N],br[N];
int ans;
int s[N];
int Mp[M+5][M+5];
int Al[3],Ar[3],Bl[3],Br[3];
int fac[N*N],inv[N*N];
bitset<N>bt[N];
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
int sum(int x,int y,int X,int Y)
{
	return Mp[X][Y]-Mp[x-1][Y]-Mp[X][y-1]+Mp[x-1][y-1];
}
void C_init()
{
	int n=1000000;
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=quickPower(fac[n],mod-2);
	for (int i=n;i>=1;i--) inv[i-1]=inv[i]*i%mod;
}
int C(int x,int y)
{
	if (x<y||y<0) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int work(int i)
{
	return (C(n,m)-C(n-s[i],m)+mod)%mod;
}
int work(int i,int j)
{
	int ss=(work(i)+work(j))%mod;
	int lx=s[i]+s[j],anss=1;
	lx-=(bt[i]&bt[j]).count();
	return (ss-(C(n,m)-C(n-lx,m)+mod)%mod+mod)%mod;
}
int calc(int i,int j)
{
	int w=1;
	w=(w+mod)%mod;
	return w*work(i,j)%mod;
}
signed main()
{
	C_init();
	n=read(),m=read(),R=read();
	for (int i=1;i<=n;i++)
	{
		x[i]=read(),y[i]=read(),b[i]=read();
		Mp[x[i]][y[i]]++;
		al[i]=max(1ll,x[i]-R);
		ar[i]=min(M,x[i]+R);
		bl[i]=max(1ll,y[i]-R);
		br[i]=min(M,y[i]+R);
	}
	for (int i=1;i<=M;i++)
		for (int j=1;j<=M;j++)
			Mp[i][j]+=Mp[i-1][j]+Mp[i][j-1]-Mp[i-1][j-1];
	for (int i=1;i<=n;i++)
	{
		s[i]=sum(al[i],bl[i],ar[i],br[i]);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (max(abs(x[i]-x[j]),abs(y[i]-y[j]))<=R) bt[i][j]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			ans=(ans+calc(i,j)*b[i]%mod*b[j]%mod)%mod;
		}
	writeln(ans);
//	writeln(work(2));
//	writeln(work(1,2));
}
/*

*/