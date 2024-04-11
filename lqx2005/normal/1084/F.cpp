#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
const int M=20;
struct tree
{
	int l,r,lx,rx;
	bool flag;
}t[N*4],now;
int n,q,opt,u,v;
int p[N+5],dep[N+5],st[M+5][N+5],low[N+5],p2[M+5],l2[N+5];
int sizest,ll[N+5];
vector<int> g[N+5];
void add(int u,int v)
{
	g[u].push_back(v);
	g[v].push_back(u);
	return;
}
void dfs(int u,int fa)
{
	sizest++;
	low[u]=sizest;
	st[0][sizest]=u;
	dep[u]=dep[fa]+1;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==fa) continue;
		dfs(v,u);
		sizest++;
		st[0][sizest]=u;
	}
	return;
}
int queryst(int l,int r)
{
	if(l>r) return 0;
	int len=(r-l+1);
	len=l2[len];
	if(dep[st[len][l]]<dep[st[len][r-p2[len]+1]]) return st[len][l];
	else return st[len][r-p2[len]+1];
}
void ST()
{
	for(int i=1;i<=M;i++) 
	{
		for(int j=1;j+p2[i]-1<=sizest;j++) 
		{
			if(dep[st[i-1][j]]<dep[st[i-1][j+p2[i-1]]]) st[i][j]=st[i-1][j];
			else st[i][j]=st[i-1][j+p2[i-1]];
		}
	}
	return;
}
void init()
{
	p2[0]=1,l2[1]=0;
	for(int i=1;i<=M;i++) p2[i]=p2[i-1]*2;
	for(int i=2;i<=N;i++) l2[i]=l2[i/2]+1;
	dep[0]=-1;
	dfs(1,0);
	ST();
	return;
}
int lca(int u,int v)
{
	int l=low[u],r=low[v];
	if(l>r) swap(l,r);
	return queryst(l,r);
}
bool checkx(int u,int v,int x)
{
	int fa=lca(u,v);
	if((lca(u,x)==x||lca(v,x)==x)&&lca(fa,x)==fa) return true;
	return false;
}
bool check(int u,int v,int uu,int vv)
{
	bool flag=0;
	if(checkx(u,v,uu)&&checkx(u,v,vv)) return true;
	return false;
}
tree up(tree l,tree r)
{
	tree res;
	res.l=l.l;
	res.r=r.r;
	res.flag=0;
	res.lx=-1;
	res.rx=-1;
	if(!l.flag) return res;
	if(!r.flag) return res;
	if(check(l.lx,l.rx,r.lx,r.rx)) res.lx=l.lx,res.rx=l.rx,res.flag=1;
	else if(check(l.lx,r.lx,l.rx,r.rx)) res.lx=l.lx,res.rx=r.lx,res.flag=1;
	else if(check(l.lx,r.rx,r.lx,l.rx)) res.lx=l.lx,res.rx=r.rx,res.flag=1;
	else if(check(l.rx,r.lx,r.rx,l.lx)) res.lx=l.rx,res.rx=r.lx,res.flag=1;
	else if(check(l.rx,r.rx,l.lx,r.lx)) res.lx=l.rx,res.rx=r.rx,res.flag=1;
	else if(check(r.lx,r.rx,l.lx,l.rx)) res.lx=r.lx,res.rx=r.rx,res.flag=1;
	return res;
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		t[x].l=l,t[x].r=r;
		t[x].lx=t[x].rx=ll[l];
		t[x].flag=1;
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	t[x]=up(t[x*2],t[x*2+1]);
	return;
}
void change(int x,int p,int v)
{
	if(t[x].l==t[x].r)
	{
		t[x].lx=t[x].rx=v;
		t[x].flag=1;
		return;
	}
	int mid=(t[x].l+t[x].r)/2;
	if(p<=mid) change(x*2,p,v);
	else change(x*2+1,p,v);
	t[x]=up(t[x*2],t[x*2+1]);
	return;
}
void query(int x)
{
	if(t[x].l==t[x].r) 
	{
		if(!now.flag||up(now,t[x]).flag)
		{
			if(now.flag) now=up(now,t[x]);
			else now=t[x];
		}
		return;
	}
	if(t[x*2].flag&&(!now.flag||up(now,t[x*2]).flag))
	{
		if(!now.flag) now=t[x*2];
		else now=up(now,t[x*2]);
		query(x*2+1);
	} 
	else query(x*2);
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]),ll[p[i]]=i;
	int u,v;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&v);
		add(i,v);
	}
	init();
	build(1,0,n-1);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d",&u,&v);
			swap(p[u],p[v]);
			change(1,p[u],u);
			change(1,p[v],v);
		}
		else 
		{
			now.lx=now.rx=-1;
			now.flag=0;
			query(1);
			printf("%d\n",now.r+1);
		}
	}
	return 0;
}