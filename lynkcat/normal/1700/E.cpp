// Lynkcat.
// Problem: E. Serega the Pirate
// Contest: Codeforces - Codeforces Round #802 (Div. 2)
// URL: https://codeforces.com/contest/1700/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
// #define N 
using namespace std;
int n,m;
map<pa,int>Mp;
vector<pa>G;
bool chk(int i,int j,vector<vector<int>>&a,vector<vector<vector<int>>>&vis)
{
			for (int k=0;k<4;k++) vis[i][j][k]=1;
			if (i>1&&a[i-1][j]<a[i][j]) vis[i][j][0]=0;
			if (j<m&&a[i][j+1]<a[i][j]) vis[i][j][1]=0;
			if (i<n&&a[i+1][j]<a[i][j]) vis[i][j][2]=0;
			if (j>1&&a[i][j-1]<a[i][j]) vis[i][j][3]=0;
			if (vis[i][j][0]==vis[i][j][1]&&vis[i][j][1]==vis[i][j][2]&&vis[i][j][2]==vis[i][j][3]&&vis[i][j][0])
				return 0;
			return 1;
}
bool work(vector<vector<int>>&a,vector<vector<vector<int>>>&vis)
{
	for (auto u:G)
	{
		if (a[u.fi][u.se]==1) continue;
		if (chk(u.fi,u.se,a,vis)==0) return 0;
	}
	return 1;
}
void BellaKira()
{
	cin>>n>>m;
	vector<vector<int>>a(n+1,vector<int>(m+1,0));
	vector<vector<vector<int>>>vis(n+1,vector<vector<int>>(m+1,vector<int>(4,0)));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			for (int k=0;k<4;k++) vis[i][j][k]=1;
			if (i>1&&a[i-1][j]<a[i][j]) vis[i][j][0]=0;
			if (j<m&&a[i][j+1]<a[i][j]) vis[i][j][1]=0;
			if (i<n&&a[i+1][j]<a[i][j]) vis[i][j][2]=0;
			if (j>1&&a[i][j-1]<a[i][j]) vis[i][j][3]=0;
			if (vis[i][j][0]==vis[i][j][1]&&vis[i][j][1]==vis[i][j][2]&&vis[i][j][2]==vis[i][j][3]&&vis[i][j][0])
			{
				G.push_back(mp(i,j));
				if (i>1) G.push_back(mp(i-1,j));
				if (i<n) G.push_back(mp(i+1,j));
				if (j>1) G.push_back(mp(i,j-1));
				if (j<m) G.push_back(mp(i,j+1));
			}
		}
	sort(G.begin(),G.end());
	G.erase(unique(G.begin(),G.end()),G.end());
	if (G.size()>15) return cout<<"2"<<endl,void();
	// cout<<G.size()<<"?"<<endl;
	// for (auto u:G) cout<<u.fi<<" "<<u.se<<endl;
	// return;
	int ans=0;
	for (int p=0;p<G.size();p++)
	{
		auto u=G[p];
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			// if (i<u.fi||i==u.fi&&j<u.se)
			{
				int tt=1;
				G.push_back(mp(i,j));
				if (i>1) G.push_back(mp(i-1,j)),tt++;
				if (i<n) G.push_back(mp(i+1,j)),tt++;
				if (j>1) G.push_back(mp(i,j-1)),tt++;
				if (j<m) G.push_back(mp(i,j+1)),tt++;
				swap(a[i][j],a[u.fi][u.se]);
				// cout<<i<<","<<j<<" "<<u.fi<<" "<<u.se<<" "<<work(a,vis)<<endl;
				if (work(a,vis))
				{
					// cout<<i<<" "<<u.fi<<a" "<<j<<
					if (i==u.fi&&j==u.se) return cout<<0<<endl,void();
					Mp[mp(min(i*m+j,u.fi*m+u.se),max(i*m+j,u.fi*m+u.se))]++;
				}
				while (tt--) G.pop_back();
				swap(a[i][j],a[u.fi][u.se]);
			}
	}
	if (Mp.size()!=0) 
	{
		cout<<1<<" "<<Mp.size()<<endl;
		return;
	}
	cout<<2<<endl;
			
			
			
		
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}