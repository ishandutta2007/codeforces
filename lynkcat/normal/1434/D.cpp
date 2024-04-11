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
// #define int ll
#define N 500005 
using namespace std;
int a[3*N],cnt;
struct node 
{
	int ans[2],l10[2],l11[2],r01[2],r11[2],sm10,sm11,sm01;
	node()
	{
		ans[0]=ans[1]=l10[0]=l10[1]=l11[0]=l11[1]=r01[0]=r01[1]=r11[0]=r11[1]=sm10=sm11=sm01=0;
	}
}tr[(3*N)<<2];
int vw[N];
int tag[(3*N)<<2];
int m;
pa E[N];
int col[N];
int dfn[N],rdfn[N];
int dep[N];
vector<pa>G[N];
int n;
void dfs(int k,int fa)
{
	dep[k]=dep[fa]+1;
	++cnt,a[++cnt]=k;
	dfn[k]=cnt;
	for (auto [u,v]:G[k])
	{
		if (u==fa) continue;
		col[u]=col[k]^v;
		dfs(u,k);
	}
	a[++cnt]=-1;
	rdfn[k]=cnt;
}
inline void work(int k)
{
	swap(tr[k].ans[0],tr[k].ans[1]);
	swap(tr[k].l10[0],tr[k].l10[1]);
	swap(tr[k].l11[0],tr[k].l11[1]);
	swap(tr[k].r01[0],tr[k].r01[1]);
	swap(tr[k].r11[0],tr[k].r11[1]);
	tag[k]^=1;
}	
inline void pushdown(int k)
{
	if (!tag[k]) return;
	work(k<<1);
	work(k<<1|1);
	tag[k]=0;
}
inline void pushup(int k)
{
	for (int i=0;i<2;i++)
	{
		tr[k].ans[i]=max(tr[k<<1].ans[i],tr[k<<1|1].ans[i]);
		tr[k].l10[i]=max(tr[k<<1|1].l10[i],tr[k<<1].l10[i]+tr[k<<1|1].sm10);
		tr[k].l11[i]=max(tr[k<<1|1].l11[i],max(tr[k<<1].l11[i]+tr[k<<1|1].sm01,tr[k<<1].l10[i]+tr[k<<1|1].sm11));
		tr[k].r01[i]=max(tr[k<<1].r01[i],tr[k<<1|1].r01[i]+tr[k<<1].sm01);
		tr[k].r11[i]=max(tr[k<<1].r11[i],max(tr[k<<1|1].r11[i]+tr[k<<1].sm10,tr[k<<1|1].r01[i]+tr[k<<1].sm11));
		tr[k].ans[i]=max({tr[k].ans[i],tr[k<<1].l10[i]+tr[k<<1|1].r11[i],tr[k<<1].l11[i]+tr[k<<1|1].r01[i]});
	}
	tr[k].sm10=tr[k<<1].sm10+tr[k<<1|1].sm10;
	tr[k].sm11=max(tr[k<<1].sm11+tr[k<<1|1].sm01,tr[k<<1].sm10+tr[k<<1|1].sm11);
	tr[k].sm01=tr[k<<1].sm01+tr[k<<1|1].sm01;
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		if (a[l]==0)
		{
			for (int i=0;i<2;i++)
			{
				tr[k].ans[i]=-inf;
				tr[k].l10[i]=-inf;
				tr[k].l11[i]=-inf;
				tr[k].r01[i]=-inf;
				tr[k].r11[i]=-inf;
			}
			tr[k].sm10=-1;
			tr[k].sm11=1;
			tr[k].sm01=1;
		} else
		if (a[l]==-1)
		{
			for (int i=0;i<2;i++)
			{
				tr[k].ans[i]=-inf;
				tr[k].l10[i]=-inf;
				tr[k].l11[i]=-inf;
				tr[k].r01[i]=-inf;
				tr[k].r11[i]=-inf;
			}
			tr[k].sm10=1;
			tr[k].sm11=1;
			tr[k].sm01=-1;
		} else
		{
			int i=col[a[l]]^1;
			tr[k].ans[i]=-inf;
			tr[k].l10[i]=-inf;
			tr[k].l11[i]=-inf;
			tr[k].r01[i]=-inf;
			tr[k].r11[i]=-inf;
		}
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}
void update(int k,int l,int r,int L,int R)
{
	if (L<=l&&r<=R)
	{
		work(k);
		return;
	}
	int mid=l+(r-l)/2;
	pushdown(k);
	if (L<=mid)
		update(k<<1,l,mid,L,R);
	if (R>mid)
		update(k<<1|1,mid+1,r,L,R);
	pushup(k);
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		G[x].push_back({y,w});
		G[y].push_back({x,w});
		E[i]=mp(x,y);
		vw[i]=w;
	}
	dfs(1,0);
	build(1,1,3*n);
	cin>>m;
	while (m--)
	{
		int x;
		cin>>x;
		vw[x]^=1;
		if (dep[E[x].fi]>dep[E[x].se]) swap(E[x].fi,E[x].se);
		update(1,1,3*n,dfn[E[x].se],rdfn[E[x].se]);
		cout<<max(tr[1].ans[0],tr[1].ans[1])<<'\n';
	}
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}