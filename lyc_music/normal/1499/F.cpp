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
#define N 5005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int dp[N][N],dis[N],n,m,ans;
vector<int>G[N];
void ad(int x,int y)
{
	G[x].push_back(y);
}
void addd(int &x,int y)
{
	x=(x+y)%mod;
}
void dfs(int k,int fa)
{
	dp[k][0]=1;dis[k]=0;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		vector<int>g;
		g.resize(max(dis[k],dis[u]+1)+5);
		for (int i=0;i<=dis[k];i++)
		{
			for (int j=0;j<=dis[u];j++)
			{
				if (i+j+1<=m)
					addd(g[max(i,j+1)],dp[k][i]*dp[u][j]%mod);
			}
			for (int j=0;j<=dis[u];j++)
			{
				if (i<=m&&j<=m)
					addd(g[i],dp[k][i]*dp[u][j]%mod);
			}
		}
		dis[k]=max(dis[k],dis[u]+1);
		for (int i=0;i<=dis[k];i++)
			dp[k][i]=g[i];
	}
}					
signed main()
{
	n=read(),m=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		ad(u,v);
		ad(v,u);
	}
	dfs(1,0);
	for (int i=0;i<=m;i++)
		ans=(ans+dp[1][i])%mod;
	writeln(ans);
}
/*

*/