//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m;
int ans;
int fac[N],inv[N];
int s[N];
int C(int x,int y)
{
	if (x<y||y<0) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;y>>=1;
	}
	return res;
}
signed main()
{
	n=read();m=read();
	if (m>=n) return puts("0"),0;
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=quickPower(fac[n],mod-2)%mod;
	for (int i=n;i>=1;i--) inv[i-1]=inv[i]*i%mod;
	int nowfh=1;
	for (int i=0;i<n-m;i++)
		ans=(ans+((nowfh*C(n-m,i)%mod+mod)%mod*quickPower(n-m-i,n)%mod)%mod*C(n,n-m)%mod)%mod,nowfh*=-1;
	if (m>0) ans=ans*2%mod;
	writeln(ans);
}
/*

*/