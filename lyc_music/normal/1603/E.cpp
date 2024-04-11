//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
//#define mod 998244353
#define int ll
#define N 205
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int mod;
int fac[N],inv[N],f[N][N][N],a1;
int n;
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
void ad(int &x,int y)
{
	x=(x+y)%mod;
}
int dfs(int i,int j,int k)
{
	if (!k)
	{
		if (!j) return fac[n]*inv[i]%mod;
		return 0;
	}
	if (n-i<n+2-(k+1)-a1) return 0;
	int &now=f[i][j][k];
	if (~now) return now;
	now=0;
	for (int x=0;x*k<=j&&x<=i;x++)
		ad(now,inv[x]*dfs(i-x,j-x*k,k-1)%mod);
	return now;
}
void LYC_music()
{
	n=read();mod=read();
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=quickPower(fac[n],mod-2);
	for (int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%mod;
	ans=1;
	for (a1=min(1ll,n-30);a1<=n;a1++)
	{
		memset(f,-1,sizeof(f));
		for (int sm=1;sm<=a1;sm++)
			ad(ans,dfs(n,sm,n+1-a1));
	}
	writeln(ans);
}
signed main()
{
	int T=1;
	while (T--)
	{
		LYC_music();
	}
}
/*

*/