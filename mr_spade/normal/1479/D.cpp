#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using std::swap;
using std::vector;
typedef unsigned long long ull;
inline int Randint(int l,int r)
{
	return (rand()<<16|rand()<<1|rand()>>14)%(r-l+1)+l;
}
inline ull Rand()
{
	return (ull)rand()<<60^(ull)rand()<<45^(ull)rand()<<30^(ull)rand()<<15^(ull)rand();
}
const int N=3e5+5;
int n,q,idx;
int a[N];
int deep[N],p[N][25];
int id[N],size[N];
int u[N],v[N],lc[N];
int ans[N];
ull val[N],cans[N];
vector<int> e[N];
int bit[N];
vector<int> dd[N<<2];
struct cell
{
	int opt,x;
};
vector<cell> Q[N<<2];
bool bk[N];
void go(int x,int lp,int rp,int l,int r,int id)
{
	if(lp==l&&rp==r)
		return dd[x].push_back(id),void();
	int mid=(lp+rp)>>1;
	if(r<=mid)
		go(x<<1,lp,mid,l,r,id);
	else if(l>=mid+1)
		go(x<<1|1,mid+1,rp,l,r,id);
	else
		go(x<<1,lp,mid,l,mid,id),go(x<<1|1,mid+1,rp,mid+1,r,id);
	return;
}
inline void add(int x,ull k)
{
	while(x<=n)
		bit[x]^=k,x+=x&-x;
}
inline ull ask(int x)
{
	ull res=0;
	while(x)
		res^=bit[x],x&=x-1;
	return res;
}
void dfs(int x,int father)
{
	register int i;
	deep[x]=deep[father]+1;
	id[x]=++idx;size[x]=1;
	p[x][0]=father;
	for(i=1;i<=20;i++)
		p[x][i]=p[p[x][i-1]][i-1];
	for(int y:e[x])
		if(y!=father)
			dfs(y,x),size[x]+=size[y];
	return;
}
inline int lca(int x,int y)
{
	register int i;
	if(deep[x]<deep[y])
		swap(x,y);
	for(i=20;i>=0;i--)
		if(deep[p[x][i]]>=deep[y])
			x=p[x][i];
	if(x==y)
		return x;
	for(i=20;i>=0;i--)
		if(p[x][i]!=p[y][i])
			x=p[x][i],y=p[y][i];
	return p[x][0];
}
inline void run(int x,int l,int r)
{
	register int i;
	for(i=l;i<=r;i++)
		val[i]=Rand();
	for(cell c:Q[x])
		if(c.opt==1&&a[c.x]>=l&&a[c.x]<=r)
			add(id[c.x],val[a[c.x]]),add(id[c.x]+size[c.x],val[a[c.x]]);
	for(cell c:Q[x])
		if(c.opt==2)
			cans[c.x]=ask(id[u[c.x]])^ask(id[v[c.x]])^ask(id[lc[c.x]])^ask(id[p[lc[c.x]][0]]);
	for(cell c:Q[x])
		if(c.opt==1&&a[c.x]>=l&&a[c.x]<=r)
			add(id[c.x],val[a[c.x]]),add(id[c.x]+size[c.x],val[a[c.x]]);
	return;
}
void solve(int x,int l,int r)
{
	register int i,j,k;
	for(int t:dd[x])
		Q[x].push_back(cell{2,t});
	if(l==r)
	{
		run(x,l,r);
		for(cell c:Q[x])
			if(c.opt==2&&cans[c.x])
				ans[c.x]=l;
		return;
	}
	int mid=(l+r)>>1,_=0;
	run(x,l,r);
	for(cell c:Q[x])
		if(c.opt==2)
			bk[c.x]=(cans[c.x]?0:1);
	run(x,l,mid);
	for(cell c:Q[x])
		if(c.opt==1)
		{
			if(a[c.x]<=mid)
				Q[x<<1].push_back(c);
			else
				Q[x<<1|1].push_back(c);
		}
		else if(!bk[c.x]&&ans[c.x]==-1)
		{
			if(cans[c.x])
				Q[x<<1].push_back(c);
			else
				Q[x<<1|1].push_back(c);
		}
	solve(x<<1,l,mid);
	solve(x<<1|1,mid+1,r);
	return;
}
signed main()
{
	int x,y;
	register int i;
	scanf("%d%d",&n,&q);
//	n=300000;q=300000;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
//		x=Randint(1,i);y=i+1;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d%d%d",&u[i],&v[i],&x,&y);
		lc[i]=lca(u[i],v[i]),go(1,1,n,x,y,i);
	}
	memset(ans,-1,sizeof(ans));
	for(i=1;i<=n;i++)
		Q[1].push_back(cell{1,i});
	solve(1,1,n);
	for(i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}