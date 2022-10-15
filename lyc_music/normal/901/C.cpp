// Lynkcat.
// Problem: CF901C Bipartite Segments
// URL: https://www.luogu.com.cn/problem/CF901C
// Memory Limit: 250 MB
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
#define N 300005
using namespace std;
int tr[N<<2],tag[N<<2];
int n,m;
poly G[N];
pa E[N];
int ffa[N],ffe[N];
int dep[N];
vector<pa>g[N];
int ans[N];
int qL[N],qR[N];
int s[N];
int U[N];
int q;
void pushup(int k,int l,int r)
{
	tr[k]=tr[k<<1]+tr[k<<1|1];
}
void pushdown(int k,int l,int r)
{
	if (!tag[k]) return;
	tag[k<<1]+=tag[k];
	tr[k<<1]+=tag[k]*(l+(r-l)/2-l+1);
	tag[k<<1|1]+=tag[k];
	tr[k<<1|1]+=tag[k]*(r-(l+(r-l)/2));
	tag[k]=0;
}
int query(int k,int l,int r,int L,int R)
{
	if (L>R) return 0;
	if (L<=l&&r<=R)
	{
		return tr[k];
	}
	int mid=l+(r-l)/2;
	int res=0;
	pushdown(k,l,r);
	if (L<=mid) 
	{
		res+=query(k<<1,l,mid,L,R);
	}
	// cout<<k<<","<<l<<" "<<r<<" "<<res<<endl;
	if (R>mid)
	{
		res+=query(k<<1|1,mid+1,r,L,R);
	}
	return res;
}
void add(int k,int l,int r,int L,int R,int x)
{
	if (L>R) return;
	if (L<=l&&r<=R)
	{
		tag[k]+=x;
		tr[k]+=x*(r-l+1);
		return;
	}
	pushdown(k,l,r);
	int mid=l+(r-l)/2;
	if (L<=mid) add(k<<1,l,mid,L,R,x);
	if (R>mid) add(k<<1|1,mid+1,r,L,R,x);
	pushup(k,l,r);
}
void dfs(int k,int fa)
{
	ffa[k]=fa;
	dep[k]=dep[fa]+1;
	for (auto u:G[k])
	{
		int to=U[u]^k;
		if (dep[to]) continue;
		dfs(to,k);
		ffe[to]=u;
	}
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		E[i].fi=x,E[i].se=y;
		U[i]=x^y;
		G[x].push_back(i);
		G[y].push_back(i);
	}
	for (int i=1;i<=n;i++)
		if (!dep[i])
			dfs(i,0);
	for (int i=1;i<=n;i++) s[i]=n;
	for (int i=1;i<=m;i++)
	{
		if (ffa[E[i].fi]!=E[i].se&&ffa[E[i].se]!=E[i].fi)
		{
			int x=E[i].fi,y=E[i].se;
			int mn=x,mx=x;
			mn=min(mn,y);
			mx=max(mx,y);
			if (dep[x]<dep[y]) swap(x,y);
			while (dep[x]>dep[y])
			{
				mn=min(mn,ffa[x]);
				mx=max(mx,ffa[x]);
				x=ffa[x];
			}
			while (x!=y)
			{
				mn=min(mn,ffa[x]);
				mx=max(mx,ffa[x]);
				x=ffa[x];
				
				mn=min(mn,ffa[y]);
				mx=max(mx,ffa[y]);
				y=ffa[y];
			}
			s[mn]=min(s[mn],mx-1);
			// cout<<mn<<","<<mx<<endl;
		}
	}
	// return;
	for (int i=n-1;i>=1;i--)
		s[i]=min(s[i],s[i+1]);
	cin>>q;
	for (int i=1;i<=q;i++)
	{
		cin>>qL[i]>>qR[i];
		g[qR[i]].push_back(mp(i,1ll));
		g[qL[i]-1].push_back(mp(i,-1ll));
	}
	for (int i=1;i<=n;i++)
	{
		add(1,1,n,i,s[i],1);
		// cout<<i<<","<<s[i]<<" "<<query(1,1,n,qL[1],qR[1])<<" "<<qL[1]<<" "<<qR[1]<<endl;
		for (auto [u,w]:g[i])
		{
			ans[u]+=w*query(1,1,n,qL[u],qR[u]);
			// cout<<u<<","<<ans[u]<<" "<<query(1,1,n,qL[u],qR[u])<<endl;
		}
	}
	for (int i=1;i<=q;i++) cout<<ans[i]<<endl;
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