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
#define N 100005
using namespace std;
int n,m,qq;
int dis[N],ans[N],nxt[N];
vector<pa>G[N];
struct node
{
	int k,b;
	node(int a=0,int c=0)
	{
		k=a,b=c;
	}
};
struct
{
	node Nod[1500005];
	bool upt[1500005];
	vector<int>rb;
	int calc(node x,int y)
	{
		return -2*y*x.k+x.b;
	}
	void update(int k,int l,int r,node x)
	{
		if (!upt[k]) 
		{
			upt[k]=1,Nod[k]=x;
			rb.emplace_back(k);
			return;
		}
		int mid=l+(r-l)/2;
		if (calc(Nod[k],mid)>calc(x,mid)) swap(x,Nod[k]);
		if (l==r) return;
		if (calc(Nod[k],l)>calc(x,l)) update(k<<1,l,mid,x);
		if (calc(Nod[k],r)>calc(x,r)) update(k<<1|1,mid+1,r,x);
	}
	int query(int k,int l,int r,int x)
	{
		if (!upt[k]) return inf;
		if (l==r) return calc(Nod[k],x);
		if (l>r) puts("wtf");
		int res=calc(Nod[k],x);
		if (x<=l+(r-l)/2) res=min(res,query(k<<1,l,l+(r-l)/2,x));
		else res=min(res,query(k<<1|1,l+(r-l)/2+1,r,x));
		return res;
	}
	void clear()
	{
		for (int u:rb)
		{
			Nod[u].k=Nod[u].b=0;upt[u]=0;
		}
		rb.clear();
	}
}tree;
void dijk()
{
	priority_queue<pa>q;
	for (int i=1;i<=n;i++) q.push(mp(-dis[i],i));
	while (!q.empty())
	{
		int u=q.top().se;
		int w=q.top().fi;
		q.pop();
		if (w!=-dis[u]) continue;
		for (auto U:G[u])
		{
			int v=U.fi,ww=U.se;
			if (dis[v]>dis[u]+ww)
			{
				dis[v]=dis[u]+ww;
				q.push(mp(-dis[v],v));
			}
		}
	}
}
void BellaKira()
{
	cin>>n>>m>>qq;
	for (int i=1;i<=n;i++)
	{
		dis[i]=inf;
		ans[i]=inf;
	}
	dis[1]=0,ans[1]=0;
	for (int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		G[x].push_back(mp(y,w));
		G[y].push_back(mp(x,w));
	}
	while (qq--)
	{
		dijk();
		for (int i=1;i<=n;i++)
		{
			ans[i]=min(ans[i],dis[i]);
		}
		for (int i=1;i<=n;i++)
			nxt[i]=inf;
		tree.clear();
		for (int i=1;i<=n;i++) tree.update(1,1,n,node(i,dis[i]+i*i));
		for (int i=1;i<=n;i++)
		{
			nxt[i]=tree.query(1,1,n,i)+i*i;
			// cout<<i<<" "<<nxt[i]<<" "<<dis[i]<<endl;
		}
		for (int i=1;i<=n;i++) swap(nxt[i],dis[i]);
	}
	dijk();
	for (int i=1;i<=n;i++)
	{
		ans[i]=min(ans[i],dis[i]);
		cout<<ans[i]<<" ";
	}
	cout<<'\n';
	
			
			
		
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