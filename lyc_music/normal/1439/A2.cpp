// Lynkcat.
// Problem: A1. Binary Table (Easy Version)
// URL: https://codeforces.com/contest/1439/problem/A1
// Memory Limit: 256 MB
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
#define mod 998244353
#define int ll
#define N 105
using namespace std;
struct node
{
	int x,y,xx,yy,xxx,yyy;
	node(int a=0,int b=0,int c=0,int aa=0,int bb=0,int  cc=0)
	{
		x=a,y=b,xx=c,yy=aa,xxx=bb,yyy=cc;
	}
};
vector<node>G;
int a[N][N];
int n,m;
void work(int x,int y)
{
	int v=a[x][y]+a[x+1][y]+a[x][y+1]+a[x+1][y+1];
	if (v==0) return;
	vector<pa>g,g1;
	// cout<<"????"<<v<<endl;
	if (v==4)
	{
		g.clear(),g1.clear();
		for (int i=0;i<=1;i++)
			for (int j=0;j<=1;j++)
				if (a[x+i][y+j]==0)
				{
					g.push_back(mp(x+i,y+j));
				} else g1.push_back(mp(x+i,y+j));
		G.push_back(node(g1[0].fi,g1[0].se,g1[1].fi,g1[1].se,g1[2].fi,g1[2].se));
		for (int i=0;i<=2;i++) a[g1[i].fi][g1[i].se]^=1;
		v=1;
	}	
	if (v<=1)
	{
		g.clear(),g1.clear();
		for (int i=0;i<=1;i++)
			for (int j=0;j<=1;j++)
				if (a[x+i][y+j]==0)
				{
					g.push_back(mp(x+i,y+j));
				} else g1.push_back(mp(x+i,y+j));
		G.push_back(node(g1[0].fi,g1[0].se,g[0].fi,g[0].se,g[1].fi,g[1].se));
		for (int i=0;i<=0;i++) a[g1[i].fi][g1[i].se]^=1;
		for (int i=0;i<=1;i++) a[g[i].fi][g[i].se]^=1;
	}
	if (v<=2)
	{
		g.clear(),g1.clear();
		for (int i=0;i<=1;i++)
			for (int j=0;j<=1;j++)
				if (a[x+i][y+j]==0)
				{
					g.push_back(mp(x+i,y+j));
				} else g1.push_back(mp(x+i,y+j));
		G.push_back(node(g1[0].fi,g1[0].se,g[0].fi,g[0].se,g[1].fi,g[1].se));
		for (int i=0;i<=0;i++) a[g1[i].fi][g1[i].se]^=1;
		for (int i=0;i<=1;i++) 
		{
			a[g[i].fi][g[i].se]^=1;
		}
	}
	if (v<=3)
	{
		g.clear(),g1.clear();
		for (int i=0;i<=1;i++)
			for (int j=0;j<=1;j++)
				if (a[x+i][y+j]==0)
				{
					g.push_back(mp(x+i,y+j));
				} else g1.push_back(mp(x+i,y+j));
		// cout<<g.size()<<" "<<g1.size()<<endl;
		G.push_back(node(g1[0].fi,g1[0].se,g1[1].fi,g1[1].se,g1[2].fi,g1[2].se));
		for (int i=0;i<=2;i++) a[g1[i].fi][g1[i].se]^=1;
	}
}
void BellaKira()
{
	G.clear();
	cin>>n>>m;
	// cout<<"!st"<<endl;
	for (int i=1;i<=n;i++)
	{
		string st;
		cin>>st;
		for (int j=1;j<=m;j++)
			a[i][j]=st[j-1]-'0';
	}
	for (int i=1;i+2<=n;i++)
		for (int j=1;j+2<=m;j++)
		{
			if (a[i][j])
			{
				G.push_back(node(i,j,i+1,j,i,j+1));
				a[i][j]^=1,a[i+1][j]^=1,a[i][j+1]^=1;
			}
		}
	for (int i=1;i+2<=n;i++)
	{
		if (a[i][m-1]+a[i][m]==0) continue;
		if (a[i][m-1]+a[i][m]==1)
		{
			if (a[i][m-1]==1)
			{
				G.push_back(node(i,m-1,i+1,m-1,i+1,m));
				a[i][m-1]^=1,a[i+1][m-1]^=1,a[i+1][m]^=1;
			}
			else
			{
				G.push_back(node(i,m,i+1,m-1,i+1,m));
				a[i][m]^=1,a[i+1][m-1]^=1,a[i+1][m]^=1;
			}
		} else
		{
				G.push_back(node(i,m,i,m-1,i+1,m));
				a[i][m]^=1,a[i][m-1]^=1,a[i+1][m]^=1;
		}
	}
	
	for (int i=1;i+2<=m;i++)
	{
		if (a[n-1][i]+a[n][i]==0) continue;
		if (a[n-1][i]+a[n][i]==1)
		{
			if (a[n-1][i]==1)
			{
				G.push_back(node(n-1,i,n-1,i+1,n,i+1));
				a[n-1][i]^=1,a[n-1][i+1]^=1,a[n][i+1]^=1;
			}
			else
			{
				G.push_back(node(n,i,n-1,i+1,n,i+1));
				a[n][i]^=1,a[n-1][i+1]^=1,a[n][i+1]^=1;
			}
		} else
		{
				G.push_back(node(n-1,i,n,i,n,i+1));
				a[n-1][i]^=1,a[n][i]^=1,a[n][i+1]^=1;
			}
	}
	
	work(n-1,m-1);
	// cout<<n<<","<<m<<endl;
			cout<<G.size()<<endl;
				for (auto u:G) cout<<u.x<<" "<<u.y<<" "<<u.xx<<" "<<u.yy<<" "<<u.xxx<<" "<<u.yyy<<endl;
	// for (int i=1;i<=n;i++)
	// {
		// for (int j=1;j<=m;j++)
		 // cout<<a[i][j];
		// cout<<endl;
	// }
	// cout<<"!ed"<<endl;
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