//The Hunting Party - Keys To The Kingdom
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
#define N 205
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int siz[N],f[N][N][N],g[N][N];
int dp[N];
vector<int>G[N];
int fac[N],Inv[N];
int n;
int inv[N];
void ade(int x,int y)
{
	G[x].push_back(y);
}
int C(int x,int y)
{
	if (x<y||y<0) return 0;
	return fac[x]*Inv[y]%mod*Inv[x-y]%mod;
}
int quickPower(int x,int y)
{
	int res=1;
	for (;y;y>>=1)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
	}
	return res;
}
void ad(int &x,int y)
{
	y=(y+mod)%mod;
	x=(x+y)%mod;
}
void dfs(int k,int fa)
{
	siz[k]=1;
	f[k][0][1]=n;
//	cout<<"?"<<k<<" "<<fa<<endl;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		for (int i=0;i<=siz[k]+siz[u];i++)
			for (int j=0;j<=siz[k]+siz[u];j++)
				g[i][j]=0;
		for (int i=0;i<=siz[k];i++)
			for (int j=0;j<=siz[u];j++)
			{
				for (int x=1;x<=siz[k];x++)
					for (int y=1;y<=siz[u];y++)
					{
						ad(g[i+j+1][x+y],f[u][j][y]*f[k][i][x]%mod*inv[n]%mod),
						ad(g[i+j][x],f[u][j][y]*f[k][i][x]%mod*y%mod);
					}
			}			
		siz[k]+=siz[u];
		for (int i=0;i<=siz[k];i++)
			for (int j=0;j<=siz[k];j++)
				f[k][i][j]=g[i][j];
	}
}
void LYC_music()
{
	n=read();
	fac[0]=1;Inv[0]=1;inv[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod,inv[i]=quickPower(i,mod-2),Inv[i]=quickPower(fac[i],mod-2);
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		ade(x,y);
		ade(y,x);
	}
	dfs(1,0);
//	return;
//	int ans=0;/
//	cout<<"?"<<C(2,1)<<endl;
	for (int i=0;i<=n-2;i++)
		for (int j=1;j<=n;j++)
			ad(dp[i],f[1][i][j]*j%mod*inv[n]%mod*inv[n]%mod);
	dp[n-1]=1;
//	for (int i=0;i<n;i++) writesp(dp[i]);
//	puts(""); 
	for (int i=n-1;i>=0;i--)
	{
		for (int j=i+1;j<=n-1;j++)
			dp[i]=(dp[i]-dp[j]*C(j,i)%mod+mod)%mod;
	}
	for (int i=0;i<n;i++) writesp(dp[i]);	
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