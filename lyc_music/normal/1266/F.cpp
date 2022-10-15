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
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int dis[N],dis1[N],U[N],mx[N],dp[N][2],s[N],f[N];
int n;
vector<int>G[N],G1[N];
void ad(int x,int y)
{
	G[x].push_back(y);
}
void dfs(int k,int fa)
{
	f[k]=fa;
	dp[0][0]=max(dp[0][0],(int)G[k].size()+1);
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		if (dis[u]+1>dis[k]) dis1[k]=dis[k],dis[k]=dis[u]+1;
		else if (dis[u]+1>dis1[k])
			dis1[k]=dis[u]+1;
	}
}
void dfs1(int k,int fa)
{
	if (k!=1) G1[U[k]].push_back(k);
	for (auto u:G[k])
	{
		if (u==fa) continue;
		G1[dis[u]+1].push_back(k);
	}
	for (auto u:G[k])
	{
		if (u==fa) continue;
		if (dis[k]-1==dis[u])
			U[u]=dis1[k]+1;
		else U[u]=dis[k]+1;
		U[u]=max(U[u],U[k]+1);
		dfs1(u,k);
	}
}
signed main()
{
	n=read();
//	for (int i=1;i<n;i++)
	memset(mx,0xc0,sizeof(mx));
	dp[n][0]=dp[n][1]=1;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		ad(u,v);
		ad(v,u);
	}
	dfs(1,0);
	dfs1(1,0);
	for (int i=n;i>=1;i--)
	{
		int x=0;
		for (auto u:G1[i])
		{
			s[u]++;
			mx[f[u]]=max(mx[f[u]],s[u]);
			dp[i][1]=max(dp[i][1],s[u]+mx[u]-2);
			dp[i][1]=max(dp[i][1],s[u]+s[f[u]]-2);
			dp[i][1]=max(dp[i][1],s[u]);
			dp[i-1][0]=max(dp[i-1][0],s[u]);
			if (x!=u) dp[i][0]=max(dp[i][0],s[u]);
			x=u;
		}
	}
	for (int i=n;i>=0;i--) dp[i][0]=max(dp[i][0],dp[i+1][0]),dp[i][1]=max(dp[i][1],dp[i+1][1]);
//	cout<<dp[0][0]<<endl;
	for (int i=1;i<=n;i++)
		if (i%2==0)
			writesp(dp[i/2][1]);
		else writesp(dp[i/2][0]);
}
/*

*/