#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
namespace zkw
{
	const int N=1e7+5;
	int M;
	pair<int,int> Max[N];
	inline void init(int n)
	{
		register int i;
		for(M=1;M<=n;M<<=1);
		return;
	}
	inline void update(int x,int k)
	{
		Max[M+x]=mp(k,x);
		for(x=(M+x)>>1;x;x>>=1)
			Max[x]=std::max(Max[x<<1],Max[x<<1|1]);
		return;
	}
	inline pair<int,int> query(int l,int r)
	{
		pair<int,int> res=mp(0,0);
		for(l=M+l-1,r=M+r+1;l^r^1;l>>=1,r>>=1)
			res=std::max(res,(l&1)?res:Max[l^1]),res=std::max(res,(r&1)?Max[r^1]:res);
		return res;
	}
}
const int N=1e6+5;
int n,m,q,tot,idx;
int id[N],iid[N],lp[N],rp[N];
int fa[N][25],dis[N],tim[N];
int ch[N][2];
int p[N],u[N],v[N];
int ty[N],x[N],bk[N];
vector<int> V;
inline int find(int x)
{
	return dis[x]==x?x:(dis[x]=find(dis[x]));
}
inline void merge(int x,int y,int t)
{
	x=find(x);y=find(y);
	if(x==y)
		return;
	int z=++tot;
	fa[x][0]=fa[y][0]=dis[x]=dis[y]=dis[z]=z;
	ch[z][0]=x;ch[z][1]=y;tim[z]=t;
	return;
}
void dfs(int x)
{
	register int i;
	for(i=1;fa[x][i-1];i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	if(x<=n)
		id[x]=++idx,iid[idx]=x,lp[x]=rp[x]=idx;
	else
		lp[x]=idx+1,dfs(ch[x][0]),dfs(ch[x][1]),rp[x]=idx;
	return;
}
signed main()
{
	int now;
	register int i,j;
	scanf("%d%d%d",&n,&m,&q);
	tot=n;
	for(i=1;i<=n;i++)
		dis[i]=i,tim[i]=q+1;
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(i=1;i<=m;i++)
		scanf("%d%d",&u[i],&v[i]),bk[i]=q+1;
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&ty[i],&x[i]);
		if(ty[i]==2)
			bk[x[i]]=i,V.push_back(x[i]);
	}
	for(i=1;i<=m;i++)
		if(bk[i]==q+1)
			merge(u[i],v[i],q+1);
	for(i=(int)V.size()-1;i>=0;i--)
		merge(u[V[i]],v[V[i]],bk[V[i]]);
	for(i=1;i<=tot;i++)
		if(dis[i]==i)
			dfs(i);
	zkw::init(n);
	for(i=1;i<=n;i++)
		zkw::update(id[i],p[i]);
	for(i=1;i<=q;i++)
		if(ty[i]==1)
		{
			now=x[i];
			for(j=23;j>=0;j--)
				if(tim[fa[now][j]]>i)
					now=fa[now][j];
			pair<int,int> p=zkw::query(lp[now],rp[now]);
			printf("%d\n",p.fi);zkw::update(p.se,0);
		}
	return 0;
}