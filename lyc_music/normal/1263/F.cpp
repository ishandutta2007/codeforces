#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
#define N 2005
using namespace std;
int dep[N],Dep[N];
poly W[N],w[N];
int n,a,b;
int dis[N][N],Dis[N][N];
poly G[N],g[N];
int dp[N],f[N],dp1[N],f1[N];
int num[N],Num[N];
inline int diss(int x,int y)
{
	return Dis[x][y];
}
inline int dis1(int x,int y)
{
	return dis[x][y];
}
void dfs(int k,int fa)
{
	Dep[k]=Dep[fa]+1;
	W[k].push_back(k);
	for (auto u:G[k])
	{
		dfs(u,k);
		for (auto x:W[k])
			for (auto y:W[u])
				Dis[x][y]=Dis[y][x]=Dep[x]+Dep[y]-Dep[k]*2;
		for (auto x:W[u]) W[k].push_back(x);
	}
}
void dfs1(int k,int fa)
{
	dep[k]=dep[fa]+1;
	w[k].push_back(k);
	for (auto u:g[k])
	{
		dfs1(u,k);
		for (auto x:w[k])
			for (auto y:w[u])
				dis[x][y]=dis[y][x]=dep[x]+dep[y]-dep[k]*2;
		for (auto x:w[u]) w[k].push_back(x);
	}
}
void BellaKira()
{
	cin>>n;
	cin>>a;
	for (int i=2;i<=a;i++)
	{
		int x;
		cin>>x;
		G[x].push_back(i);
	}
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		Num[i]=x;
	}
	cin>>b;
	for (int i=2;i<=b;i++)
	{
		int x;
		cin>>x;
		g[x].push_back(i);
	}
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		num[i]=x;
	}
	dfs(1,0);
	dfs1(1,0);
	memset(dp,0x3f,sizeof(dp));
	memset(f,0x3f,sizeof(f));
	dp[1]=0;
	f[1]=0;
	num[0]=Num[0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=a;j++)
		{
			dp1[j]=inf;
		}
		for (int j=1;j<=b;j++)
		{
			f1[j]=inf;
		}
		for (int j=1;j<=a;j++)
		{
			dp1[j]=min(dp1[j],dp[j]+dis1(num[i-1],num[i]));
			f1[num[i-1]]=min(f1[num[i-1]],dp[j]+diss(j,Num[i]));
		}
		for (int j=1;j<=b;j++)
		{
			f1[j]=min(f1[j],f[j]+diss(Num[i-1],Num[i]));
			dp1[Num[i-1]]=min(dp1[Num[i-1]],f[j]+dis1(j,num[i]));
		}
		for (int j=1;j<=a;j++)
		{
			dp[j]=dp1[j];
		}
		for (int j=1;j<=b;j++)
		{
			f[j]=f1[j];
		}
	}
	// cout<<"????"<<endl;
	int ans=0;
	for (int j=1;j<=a;j++)
	{
		dp[j]+=diss(j,1)+dis1(num[n],1);
		dp[j]/=2;
		ans=max(ans,a-1+b-1-dp[j]);
	}
	for (int j=1;j<=b;j++)
	{
		f[j]+=dis1(j,1)+diss(Num[n],1);
		// if (j==4)
			// cout<<"???"<<f[j]<<" "<<diss(Num[a],1)<<" "<<dis1(j,1)<<endl;
		f[j]/=2;
		ans=max(ans,a-1+b-1-f[j]);
	}
	// cout<<f[4]<<endl;
	cout<<ans<<'\n';
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}