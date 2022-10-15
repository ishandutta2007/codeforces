//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
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
#define N 2000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int fac[N],inv[N],f[N],ans,n;
inline int quickPower(int x,int y)
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
signed main()
{
	n=1e6+1;
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=quickPower(fac[n],mod-2);
	for (int i=n-1;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%mod;
	n=read();
//	cout<<fac[n]<<endl;
	ans=fac[n]*n%mod*(fac[n]*n%mod+1)%mod*quickPower(2,mod-2)%mod;
//	cout<<ans<<endl;
	f[0]=n; 
	for (int i=1;i<n;i++)
		f[i]=fac[n]*((n-i)*(n-i)%mod+1)%mod*inv[n-i+1]%mod;
	for (int i=n;i<2*n;i++)
		f[i]=(fac[n]-f[i-n]+mod)%mod;
	for (int i=1;i<2*n;i++) ans=(ans-(f[i]*i%mod)+mod)%mod;
	writeln(ans);	
}
/*

*/