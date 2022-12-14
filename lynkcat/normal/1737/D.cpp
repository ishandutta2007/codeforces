// Problem: D. Ela and the Wiring Wizard
// Contest: Codeforces - Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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
#define N 250005
using namespace std;
int n,m,dis[N],vis[N],s[N],t[N],w[N];
int f[505][505],g[505][505];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) dis[i]=inf,vis[i]=0;
	dis[1]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			f[i][j]=inf,g[i][j]=(i==j)?0:inf;
	for (int i=1;i<=m;i++)
	{
		cin>>s[i]>>t[i]>>w[i];
		f[s[i]][t[i]]=min(f[s[i]][t[i]],w[i]);
		f[t[i]][s[i]]=min(f[s[i]][t[i]],w[i]);
		g[s[i]][t[i]]=1;
		g[t[i]][s[i]]=1;
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	int mn=inf;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
		{
			// cout<<i<<" "<<j<<" "<<w[i]*(min(g[t[j]][j],g[s[i]][j])+g[1][j]+g[j][n]+1)<<endl;
			mn=min(mn,w[i]*(g[t[i]][j]+min({g[1][s[i]]+g[j][n],g[1][j]+g[s[i]][n],g[1][j]+g[j][n]+1})+1));
			mn=min(mn,w[i]*(g[s[i]][j]+min({g[1][t[i]]+g[j][n],g[1][j]+g[t[i]][n],g[1][j]+g[j][n]+1})+1));
		}
	cout<<mn<<'\n';
			
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}