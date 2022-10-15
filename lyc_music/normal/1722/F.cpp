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
#define N 55
using namespace std;
int vis[N][N],dfn;
int n,m,a[N][N];
vector<pa>g;
void dfs(int x,int y)
{
	if (x<1||x>n||y<1||y>m) return;
	if (!a[x][y]) return;
	if (vis[x][y]) return;
	g.push_back(mp(x,y));
	vis[x][y]=dfn;
	dfs(x-1,y);
	dfs(x+1,y);
	dfs(x,y-1);
	dfs(x,y+1);
	dfs(x-1,y-1);
	dfs(x-1,y+1);
	dfs(x+1,y-1);
	dfs(x+1,y+1);
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			char ch;
			cin>>ch;
			if (ch=='.') a[i][j]=0;
			else a[i][j]=1;
		}
	int ans=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]==1&&!vis[i][j]) 
			{
				vector<pa>().swap(g);
				++dfn;
				dfs(i,j);
				if (g.size()!=3) ans=0;
				else
				{
					// sort(g.begin(),g.end());
					bool bl=1;
					for (auto [x,y]:g)
						for (auto [u,v]:g)
							if (abs(x-u)<=1&&abs(y-v)<=1) bl&=1;
							else bl&=0;	
					ans&=bl;
				}						
			}
	if (ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)	
		vis[i][j]=0;
	dfn=0;
	
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}