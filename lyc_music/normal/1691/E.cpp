// Lynkcat.
// Problem: E. Number of Groups
// URL: https://codeforces.com/contest/1691/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define mod 998244353
#define int ll
#define N 500005
using namespace std;
int n,col[N],l[N],r[N];
poly G[N][2];
int red[N],blue[N];
int vis[N];
set<int>S[2];
void BellaKira()
{
	int tot=0;
	poly g;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>col[i]>>l[i]>>r[i];
		g.push_back(l[i]);
		g.push_back(r[i]+1);
		vis[i]=1;
	}
	sort(g.begin(),g.end());
	g.erase(unique(g.begin(),g.end()),g.end());
	for (int i=1;i<=n;i++)
		l[i]=lower_bound(g.begin(),g.end(),l[i])-g.begin()+1,
		r[i]=lower_bound(g.begin(),g.end(),r[i]+1)-g.begin()+1;
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		G[l[i]][col[i]].push_back(i);
		red[i]=blue[i]=-inf;
		if (col[i]==0) red[i]=r[i];
		else blue[i]=r[i];
	}
	int m=(int)g.size();
	for (int i=1;i<=m;i++)
	{
		for (int j=0;j<=1;j++)
		{
			for (auto u:G[i][j])
			{
				if (!vis[u]) continue;
				if (S[j^1].empty()) continue;
				int bl=1;
				for (auto v:S[j^1])
				{
					if (j==1&&red[v]<=i||j==0&&blue[v]<=i)
						continue;
					bl=0;
				}
				if (bl) 
				{
					S[j^1].clear();
					continue;
				}
				for (auto v:S[j^1])
				{
					if (j==1&&red[v]<=i||j==0&&blue[v]<=i)
						continue;
					red[u]=max(red[v],red[u]);
					blue[u]=max(blue[u],blue[v]);
					if (S[j].count(v))
					{
						S[j].erase(v);
					}
					tot--;
				}
				S[j^1].clear();
				tot++;
				S[0].insert(u);
				S[1].insert(u);
				vis[u]=0;
			}
		}
		for (int j=1;j>=0;j--)
		{
			for (auto u:G[i][j])
			{
				if (!vis[u]) continue;
				for (auto v:S[j^1])
				{
					if (j==1&&red[v]<=i||j==0&&blue[v]<=i)
						continue;
					red[u]=max(red[v],red[u]);
					blue[u]=max(blue[u],blue[v]);
					if (S[j].count(v))
					{
						S[j].erase(v);
					}
					tot--;
				}
				S[j^1].clear();
				tot++;
				S[0].insert(u);
				S[1].insert(u);
				vis[u]=0;
			}
		}
		// cout<<g[i-1]<<" "<<tot<<endl;
		G[i][0].clear(),G[i][1].clear();
	}
	cout<<tot<<endl;
	S[0].clear(),S[1].clear();
		
					
					
				
		
		
		
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