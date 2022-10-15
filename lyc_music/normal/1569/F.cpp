// Lynkcat.
// Problem: F. Palindromic Hamiltonian Path
// URL: https://codeforces.com/problemset/problem/1569/F
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
// #define int ll
#define N 55
using namespace std;
vector<poly> col[N];
int f[N][N];
vector<poly>Ans[N];
int p[N];
ll C[N][N],fac[N];
int n,m,q;
void dfs(int k,int mx,poly g)
{
	if (k==n/2+1)
	{
		col[mx].push_back(g);
		return;
	}
	for (int i=1;i<=mx+1;i++)
	{
		g.push_back(i),dfs(k+1,max(mx,i),g),g.pop_back();
	}
}
void work(vector<pa>g)
{
	for (int i=0;i<g.size();i++) p[i]=i;
	// vector<pa>g1={{12,8},{11,7},{10,1},{9,6},{5,2},{4,3}};
			// if (g==g1)
			// {
	// for (auto u:g) cout<<u.fi<<" "<<u.se<<endl;
	// cout<<endl;
	// }
	int ans=0;
	int tt=0;
	do
	{
		tt++;
		bool res=0;
		for (int i=0;i+1<g.size();i++)
		{
			int x=p[i],y=p[i+1];
			// if (g[p[0]].fi==10&&g[p[1]].fi==4&&g[p[2]].fi==9&&g[p[3]].fi==5)
				// cout<<"?"<<g[x].fi<<" "<<g[y].fi<<" "<<g[y].se<<" "<<g[x].se<<endl;
			if (f[g[x].fi][g[y].fi]&&f[g[y].se][g[x].se])
				continue;
			if (f[g[x].fi][g[y].se]&&f[g[y].fi][g[x].se])
				continue;
			res=1;
		}
		// if (g[p[0]].fi==10&&g[p[1]].fi==4&&g[p[2]].fi==9&&g[p[3]].fi==5)
			// cout<<endl;
		int x=p[g.size()-1];
		if (!(f[g[x].fi][g[x].se])) res=1;
		if (res) continue;
		ans=1;
		break;
	}while (next_permutation(p,p+g.size()));
	if (!ans) return;
	for (int i=1;i<=n/2;i++)
	{
		for (auto u:col[i])
		{
			poly nowc(n,0);
			for (int j=0;j<n/2;j++)
				nowc[g[j].fi-1]=nowc[g[j].se-1]=u[j];
			Ans[i].push_back(nowc);
		}
	}
}
		
void dfs1(poly g,vector<pa>g1)
{
	if (!g.size())
	{
		work(g1);
		return;
	}
	int x=g.back();
	g.pop_back();
	for (int i=0;i<g.size();i++)
	{
		int now=g[i];
		poly nxt=g;
		nxt.erase(nxt.begin()+i,nxt.begin()+i+1);
		g1.push_back(mp(x,g[i]));
		dfs1(nxt,g1);
		g1.pop_back();
	}
}
void BellaKira()
{
	cin>>n>>m>>q;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		f[x][y]=f[y][x]=1;
	}
	dfs(1,0,poly());
	poly now;
	for (int i=1;i<=n;i++) now.push_back(i);
	dfs1(now,vector<pa>());
	C[0][0]=1;fac[0]=1;
	for (int i=1;i<=q;i++)
	{
		C[i][0]=1;
		fac[i]=fac[i-1]*i;
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1]);
	}
	ll ans=0;
	for (int i=1;i<=n/2;i++)
	{
		sort(Ans[i].begin(),Ans[i].end());
		Ans[i].erase(unique(Ans[i].begin(),Ans[i].end()),Ans[i].end());
		ans+=1ll*(ll)Ans[i].size()*C[q][i]*fac[i];
	}
	cout<<ans<<endl;
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}