//The Hunting Party - Keys To The Kingdom
//~
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
#define N 2000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,fac[N],inv[N];
int f[N];
int s[N];
int ans;
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
void What_will_Diana_eat_today()
{
	n=read(),m=read();
	fac[0]=1;
	inv[0]=1;
	for (int i=1;i<=n;i++)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=quickPower(fac[i],mod-2);
	}
	f[1]=1;
	for (int i=1;i<n;i++)
	{
		s[i]=(s[i-1]+f[i]*inv[i-1]%mod)%mod;
		int x=i-m;
		if (x<0) x=0;
		f[i+1]=f[i+1]+fac[i-1]*(s[i]-s[x]+mod)%mod;
		f[i+1]=(f[i+1])%mod;
	}
	for (int i=1;i<=n;i++) ans=(ans+f[i]*(fac[n-1]*inv[i-1]%mod)%mod)%mod;
	writeln((fac[n]-ans+mod)%mod);
	
}
signed main()
{
	int T=1;
	while (T--)
	{
	 	  What_will_Diana_eat_today();
	}
}
/*
1000000 500000
*/