// Problem: D. The Beach
// Contest: Codeforces - Codeforces Round #829 (Div. 1)
// URL: https://codeforces.com/contest/1753/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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
#define N 300005
using namespace std;
int n,m,p,q;
vector<vector<char>>a;
vector<poly>id;
int tot;
int dis[N];
void BellaKira()
{
	cin>>n>>m;
	cin>>p>>q;
	a=vector<vector<char>>(n+1,vector<char>(m+1,' '));
	id=vector<poly>(n+1,poly(m+1,0));
	priority_queue<pair<int,pa>>qr;
	tot=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			id[i][j]=++tot;
		}
	for (int i=1;i<=tot;i++) dis[i]=inf;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]=='.')	dis[id[i][j]]=0,qr.push(mp(-0,mp(i,j)));
	while (!qr.empty())
	{
		int w=-qr.top().fi;
		int x=qr.top().se.fi,y=qr.top().se.se;
		qr.pop();
		if (w!=dis[id[x][y]]) continue;
		for (int dx=-1;dx<=1;dx++)
			for (int dy=-1;dy<=1;dy++)
			{
				if (!(dx==0||dy==0)) continue;
				if (!(dx+dy)) continue;
				int nx=x+dx,ny=y+dy;
				// cout<<dx<<" "<<dy<<endl;
				if (!(nx>=1&&nx<=n&&ny>=1&&ny<=m)) continue;
				if (a[nx][ny]=='#'||a[nx][ny]=='.') continue;
				if (a[nx][ny]=='U')
				{
					int V=q;
					if (dx==-1) continue;
					if (!dx) V=p;
					if (dis[id[nx+1][ny]]>dis[id[x][y]]+V)
					{
						dis[id[nx+1][ny]]=dis[id[x][y]]+V;
						qr.push(mp(-dis[id[nx+1][ny]],mp(nx+1,ny)));
					}
				}
				if (a[nx][ny]=='D')
				{
					int V=q;
					if (dx==1) continue;
					if (!dx) V=p;
					if (dis[id[nx-1][ny]]>dis[id[x][y]]+V)
					{
						dis[id[nx-1][ny]]=dis[id[x][y]]+V;
						qr.push(mp(-dis[id[nx-1][ny]],mp(nx-1,ny)));
					}
				}
				if (a[nx][ny]=='L')
				{
					int V=q;
					if (dy==-1) continue;
					if (!dy) V=p;
					if (dis[id[nx][ny+1]]>dis[id[x][y]]+V)
					{
						dis[id[nx][ny+1]]=dis[id[x][y]]+V;
						qr.push(mp(-dis[id[nx][ny+1]],mp(nx,ny+1)));
					}
				}
				if (a[nx][ny]=='R')
				{
					int V=q;
					if (dy==1) continue;
					if (!dy) V=p;
					if (dis[id[nx][ny-1]]>dis[id[x][y]]+V)
					{
						dis[id[nx][ny-1]]=dis[id[x][y]]+V;
						qr.push(mp(-dis[id[nx][ny-1]],mp(nx,ny-1)));
					}
				}
			}
	}
	// cout<<dis[id[2][2]]<<endl;
	int Ans=inf;
	for (int i=1;i<=n;i++)
		for (int j=1;j<m;j++)
			Ans=min(Ans,dis[id[i][j]]+dis[id[i][j+1]]);
	for (int i=1;i<n;i++)
		for (int j=1;j<=m;j++)
			Ans=min(Ans,dis[id[i][j]]+dis[id[i+1][j]]);
	if (Ans==inf) cout<<-1<<'\n';
	else
		cout<<Ans<<'\n';	
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}