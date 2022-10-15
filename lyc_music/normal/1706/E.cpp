// Lynkcat.
// Problem: E. Qpwoeirut and Vertices
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/E
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
#define N 400005
using namespace std;
int n,m,q;
int stn[N][20],stm[N][20],lca[N][20];
int dfn[N],idfn[N],DFN;
int dep[N],fa[N],val[N];
int lson[N],rson[N];
int ffa[N];
int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
inline int queryn(int l,int r)
{
	int t=log2(r-l+1);
	return min(stn[l][t],stn[r-(1<<t)+1][t]);
}
inline int querym(int l,int r)
{
	int t=log2(r-l+1);
	return max(stm[l][t],stm[r-(1<<t)+1][t]);
}
inline int querylca(int l,int r)
{
	if (l==r) return lca[l][0];
	l++;
	int t=log2(r-l+1);
	int x=lca[l][t],y=lca[r-(1<<t)+1][t];
	// cout<<"?"<<l<<","<<r<<" "<<x<<" "<<y<<" "<<t<<endl;
	if (dep[x]<dep[y]) return ffa[x];
	return ffa[y];
}
void dfs(int k,int fa)
{
	dfn[k]=++DFN;
	dep[k]=dep[fa]+1;
	ffa[k]=fa;
	idfn[DFN]=k;
	// cout<<k<<","<<DFN<<endl;
	if (lson[k]) dfs(lson[k],k);
	if (rson[k]) dfs(rson[k],k);
}
void BellaKira()
{
	cin>>n>>m>>q;
	for (int i=1;i<=n;i++) fa[i]=i,val[i]=0,lson[i]=rson[i]=0;
	int cnt=n;
	int rt=0;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if (gf(x)==gf(y)) continue;
		x=gf(x),y=gf(y);
		++cnt;
		fa[cnt]=cnt;
		val[cnt]=i;
		lson[cnt]=x,rson[cnt]=y;
		// cout<<cnt<<","<<" "<<x<<" "<<y<<endl;
		fa[x]=cnt,fa[y]=cnt;
		rt=cnt;
	}
	DFN=0;
	dfs(rt,0);
	// cout<<"!!"<<cnt<<" "<<DFN<<endl;
	for (int i=1;i<=cnt;i++) stn[i][0]=dfn[i];
	for (int j=1;j<=19;j++)
		for (int i=1;i+(1<<j)-1<=cnt;i++)
			stn[i][j]=min(stn[i][j-1],stn[i+(1<<(j-1))][j-1]);
	for (int i=1;i<=cnt;i++) stm[i][0]=dfn[i];
	for (int j=1;j<=19;j++)
		for (int i=1;i+(1<<j)-1<=n;i++)
			stm[i][j]=max(stm[i][j-1],stm[i+(1<<(j-1))][j-1]);
	for (int i=1;i<=cnt;i++) lca[i][0]=idfn[i];
	for (int j=1;j<=19;j++)
		for (int i=1;i+(1<<j)-1<=cnt;i++)
		{
			int x=lca[i][j-1];
			int y=lca[i+(1<<(j-1))][j-1];
			if (dep[x]<dep[y]) lca[i][j]=x;
			else lca[i][j]=y;
		}
	for (int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		int x=queryn(l,r);
		int y=querym(l,r);
		int u=querylca(x,y);
		// cout<<"?"<<x<<" "<<y<<" "<<l<<" "<<r<<" "<<u<<" "<<lca[x][1]<<" "<<lca[y][0]<<endl;
		cout<<val[u]<<" ";
	}
	cout<<endl;
		
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