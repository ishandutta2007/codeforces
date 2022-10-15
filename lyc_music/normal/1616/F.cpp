// Lynkcat.
// Problem: CF1616F Tricolor Triangles
// URL: https://www.luogu.com.cn/problem/CF1616F
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// -----------------------------------------------

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
#define mod 3
#define int ll
#define N 65
using namespace std;
int n,m,id[N][N],f[N*N];
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int guass(vector<poly> G)
{
	// for (auto u:G)
	// {
		// for (auto v:u) cout<<v<<" ";
		// cout<<endl;
	// }
	// cout<<endl;
	for (int i=0,nw=1;i<G.size()&&nw<=m;nw++)
	{
		if (!G[i][nw])
		{
			for (int j=i+1;j<G.size();j++)
				if (G[j][nw])
				{
					swap(G[j],G[i]);
					break;
				}
		}
		if (!G[i][nw]) continue;
		int v=quickPower(G[i][nw],mod-2);
		for (int j=nw;j<G[i].size();j++)
			G[i][j]=G[i][j]*v%mod;
		for (int j=0;j<G.size();j++)
			if (G[j][nw]&&j!=i)
			{
				int u=G[j][nw];
				for (int k=0;k<=m+1;k++)
				{
					G[j][k]=(G[j][k]-G[i][k]*u%mod+mod)%mod;
				}
			}
		i++;
	}
	// for (auto u:G)
	// {
		// for (auto v:u) cout<<v<<" ";
		// cout<<endl;
	// }
	// cout<<endl;
	for (int i=0;i<G.size();i++)
	{
		int tt=0;
		for (int j=1;j<=m;j++)
			if (G[i][j])
			{
				tt=j;
				break;
			}
		if (!tt&&G[i][m+1]) return 0;
		if (!tt) continue;
		f[tt]=G[i][m+1];
	}
	return 1;
}
void BellaKira()
{
	cin>>n>>m;
	vector<poly>G;
	for (int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		id[x][y]=id[y][x]=i;
		f[i]=z;
		if (z!=-1)
		{
			poly now(m+2,0);
			now[i]=1;
			now[m+1]=z;
			G.push_back(now);
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			for (int k=j+1;k<=n;k++)
				if (id[i][j]&&id[i][k]&&id[j][k])
				{
					poly now(m+2,0);
					now[id[i][j]]=1;
					now[id[i][k]]=1;
					now[id[j][k]]=1;
					now[m+1]=0;
					G.push_back(now);
				}
	int ans=guass(G);
	if (ans==0) cout<<-1<<endl;
	else
	{
		for (int i=1;i<=m;i++)
			if (f[i]==-1) cout<<3<<" ";
			else cout<<(f[i]-1+3)%3+1<<" ";
		cout<<endl;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			id[i][j]=0;
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}