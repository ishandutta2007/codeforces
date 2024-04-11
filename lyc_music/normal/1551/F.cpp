//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define y1 nmsl
#define il inline
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
#define mod 1000000007
#define Endl endl
#define int ll
#define N 105
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int ans,T,n,C[1005][1005],dp[N][N],beibao[N][N][N],K,dep[N],root;
vector<int>G[N];
void ad(int x,int y)
{
	G[x].push_back(y);
}
void dfs(int k,int fa)
{
	dep[k]=dep[fa]+1;
	dp[k][1]=1;
	for (int i=1;i<=n;i++) beibao[k][i][0]=1;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		for (int i=1;i<=n;i++)
		{
			if (k==root){
			for (int j=n;j>=1;j--)
				beibao[k][i][j]=(beibao[k][i][j]+beibao[k][i][j-1]*dp[u][i]%mod)%mod;  }
			dp[k][i+1]=(dp[k][i+1]+dp[u][i])%mod;	
//			cout<<i<<" "<<k<<" "<<u<<" "<<dp[k][i+1]<<" "<<dp[u][i]<<endl;	
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (k==root) ans=(ans+beibao[k][i][K])%mod;
	}
}
signed main()
{
	T=read();
	for (int i=1;i<=1000;i++) C[i][0]=C[i][i]=1;
	for (int i=1;i<=1000;i++)
		for (int j=1;j<i;j++)
				C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	while (T--)
	{
		n=read(),K=read();ans=0;
		for (int i=1;i<=n;i++) G[i].clear();
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			ad(u,v);
			ad(v,u);
		}
		for (root=1;root<=n;root++)
		{
		for (int i=1;i<=n;i++) memset(dp[i],0,sizeof(dp[i]));
			dfs(root,0);
			int i=root;
				for (int j=1;j<=n;j++)	
				memset(beibao[i][j],0,sizeof(beibao[i][j]));
		}
		if (K==2) writeln(C[n][2]); else writeln(ans);
	}
}
/*
1
8 3
1 2
5 8
5 4
2 7
7 6
8 7
3 2
*/