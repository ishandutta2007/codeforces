//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int dp[N][55];
int a[N];
int ans[N];
int n,mod;
vector<int>G[N];
void ad(int x,int y)
{
	G[x].push_back(y);
}
void dfs(int k,int fa)
{
	dp[k][0]^=a[k];
	for (int u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		for (int j=0;j<mod;j++)
				dp[k][(j+1)%mod]^=dp[u][(j)%(mod)];
	}
}
void dfs1(int k,int fa)
{
	for (int i=mod/2;i<mod;i++) ans[k]^=dp[k][i];
	if (ans[k]>0) ans[k]/=ans[k];
	for (int u:G[k])
	{
		if (u==fa) continue;
		int g[105];
		for (int i=0;i<mod;i++) g[(i+1)%mod]=dp[k][(i+1)%mod]^dp[u][i];
		for (int i=0;i<mod;i++)
			dp[u][(i+1)%mod]^=g[i];
		dfs1(u,k);
	}
}
signed main()
{
	n=read(),mod=read()*2;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		ad(u,v);
		ad(v,u);
	}
	for (int i=1;i<=n;i++) a[i]=read();
	dfs(1,0);
	dfs1(1,0);
	for (int i=1;i<=n;i++) writeln(ans[i]);
}
/*

*/