// Lynkcat.
// Problem: CF325D Reclamation
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF325D?contestId=73867
// Memory Limit: 500 MB
// Time Limit: 5000 ms

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
// #define int ll
#define N 20000005
using namespace std;
int n,m,q,id[3005][6005],fa[N];
bool vis[3005][6005];
int ans;
int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
void merge(int x,int y)
{
	x=gf(x),y=gf(y);
	if (x==y) return;
	fa[x]=y;
}
void BellaKira()
{
	cin>>n>>m>>q;
	if (m==1)
	{
		cout<<0<<endl;
		return;
	}
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=2*m;j++)
			id[i][j]=++cnt,fa[cnt]=cnt;
	}
	for (int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		map<int,int>Mp;
		bool bl=0;
		for (int i=-1;i<=1;i++)
			for (int j=-1;j<=1;j++)
			{
				if (i==0&&j==0) continue;
				int nx=x+i,ny=y+j;
				if (ny>2*m) ny-=2*m;
				else if (ny<=0) ny+=2*m;
				if (!(nx>=1&&nx<=n)) continue;
				if (!vis[nx][ny]) continue;
				// cout<<"?"<<nx<<" "<<ny<<" "<<id[nx][ny]<<endl;
				Mp[gf(id[nx][ny])]++;
			}
		// cout<<"--"<<endl;
		for (int i=-1;i<=1;i++)
			for (int j=-1;j<=1;j++)
			{
				if (i==0&&j==0) continue;
				int nx=x+i,ny=y+j+m;
				if (ny>2*m) ny-=2*m;
				else if (ny<=0) ny+=2*m;
				if (!(nx>=1&&nx<=n)) continue;
				if (!vis[nx][ny]) continue;
				// cout<<"?"<<nx<<" "<<ny<<" "<<gf(id[nx][ny])<<endl;
				if (Mp.count(gf(id[nx][ny])))
				{
					bl=1;
					break;
				}
			}
		// cout<<endl;
		if (bl) continue;
		ans++;
		vis[x][y]=vis[x][y+m]=1;
		Mp.clear();
		for (int i=-1;i<=1;i++)
			for (int j=-1;j<=1;j++)
			{
				if (i==0&&j==0) continue;
				int nx=x+i,ny=y+j;
				if (ny>2*m) ny-=2*m;
				else if (ny<=0) ny+=2*m;
				if (!(nx>=1&&nx<=n)) continue;
				if (!vis[nx][ny]) continue;
				Mp[gf(id[nx][ny])]++;
			}
		for (auto u:Mp) merge(u.fi,id[x][y]);
		Mp.clear();
		// cout<<"--"<<endl;
		for (int i=-1;i<=1;i++)
			for (int j=-1;j<=1;j++)
			{
				if (i==0&&j==0) continue;
				int nx=x+i,ny=y+j+m;
				if (ny>2*m) ny-=2*m;
				else if (ny<=0) ny+=2*m;
				if (!(nx>=1&&nx<=n)) continue;
				if (!vis[nx][ny]) continue;
				Mp[gf(id[nx][ny])]++;
			}
		for (auto u:Mp) merge(u.fi,id[x][y+m]);
		// cout<<i<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
}
signed main()
{
	IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}