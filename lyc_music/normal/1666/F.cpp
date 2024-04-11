//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 5005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N];
int dp[2][N][N];
int inv[N];
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if(y&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return res;
}
void ad(int &x,int y)
{
	x=(x+y)%mod;
}
void BellaKira()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=0;
	for (int i=1;i<=n;i++) a[read()]++;
	int res=1;
	for (int i=1;i<=n;i++) res=1ll*res*inv[a[i]]%mod;
	for (int i=0;i<=n+1;i++)
		for (int j=0;j<=n+1;j++)
			dp[0][i][j]=dp[1][i][j]=0;
	dp[0][1][0]=1;
	int lst=n;
	while (a[lst]==0) lst--;
	for (int i=1;i<lst;i++)
	{
		for (int j=0;j<=n-a[i];j++)
		{
			ad(dp[0][i+1][j+a[i]],dp[0][i][j]);
			ad(dp[1][i+1][j+a[i]],dp[1][i][j]);
			if (a[i]>0)
				ad(dp[1][i+1][j+a[i]-1],1ll*a[i]*dp[0][i][j]%mod);
			if (j>0&&a[i]>0)
				dp[1][i+1][j+a[i]-2]=(1ll*dp[1][i][j]*j%mod*a[i]%mod+dp[1][i+1][j+a[i]-2])%mod;
		}
	}
	res=1ll*res*dp[1][lst][0]%mod;
	if (a[lst]>=2) return puts("0"),void();
	writeln(res);
}
signed main()
{
	inv[0]=1;
	for (int i=1;i<=5001;i++) inv[i]=1ll*inv[i-1]*quickPower(i,mod-2)%mod;
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}
/*

*/