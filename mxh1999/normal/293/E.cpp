//This is meng meng da mjy>_<
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000007
typedef long long ll;
using namespace std;

void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 100010
struct Edge
{
	int v,w,next;
}	e[maxn<<1];
int g[maxn],tot;
void addedge(int x,int y,int w)
{
	e[++tot].v=y;e[tot].w=w,e[tot].next=g[x];g[x]=tot;
}
bool vis[maxn];
int root,all;
int f[maxn],sz[maxn];
ll len[maxn],dis[maxn];
int n;
ll mjy;
int l,w;

void getroot(int t,int fa)
{
	sz[t]=1,f[t]=0;
	for (int i=g[t];i;i=e[i].next)
	if (e[i].v!=fa && !vis[e[i].v])
	{
		getroot(e[i].v,t);
		sz[t]+=sz[e[i].v];
		f[t]=max(f[t],sz[e[i].v]);
	}
	f[t]=max(f[t],all-sz[t]);
	if (f[t]<f[root])	root=t;
}
void getsz(int t,int fa)
{
	sz[t]=1;
	for (int i=g[t];i;i=e[i].next)
	if (e[i].v!=fa && !vis[e[i].v])
	{
		getroot(e[i].v,t);
		sz[t]+=sz[e[i].v];
	}
}
pair<int,int>	que[maxn];
int cnt,xmm;
void getinfo(int t,int fa)
{
	if (fa!=0)
	que[++cnt]=mp(dis[t],len[t]);
	for (int i=g[t];i;i=e[i].next)
	if (e[i].v!=fa && !vis[e[i].v])
	{
		dis[e[i].v]=dis[t]+e[i].w;
		len[e[i].v]=len[t]+1;
		getinfo(e[i].v,t);
	}
}
int c[maxn];
void insert(int t,int val)
{
	for (int i=t;i<=xmm;i+=i&(-i))	c[i]+=val;
}
int query(int t)
{
	if (t>xmm)	t=xmm;
	int mjy=0;
	for (int i=t;i>0;i-=i&(-i))	mjy+=c[i];
	return mjy;
}
ll calc(int t,int l,int w)
{
	xmm=sz[t];
	dis[t]=0;len[t]=0;cnt=0;
	getinfo(t,0);
	sort(que+1,que+cnt+1);
	ll mxh=0;
	int now=1;
	for (int i=1;i<=cnt;i++)
	if (que[i].fi<=w && que[i].se<=l)	mxh+=2;
	for (int i=1;i<=xmm;i++)	c[i]=0;
	for (int i=cnt;i>=1;i--)
	{
		while (now<=cnt && que[now].fi+que[i].fi<=w)	insert(que[now].se,1),now++;
		mxh+=query(l-que[i].se);
		if (que[i].fi*2<=w && que[i].se*2<=l)	mxh--;
	}
	return mxh;
}
void solve(int t)
{
	vis[t]=true;
	getsz(t,0);
	mjy+=calc(t,l,w);
	for (int i=g[t];i;i=e[i].next)
	if (!vis[e[i].v])
	{
		mjy-=calc(e[i].v,l-2,w-2*e[i].w);
		root=0;all=sz[e[i].v];
		getroot(e[i].v,0);
		solve(root);
	}
}
int main()
{
	read(n),read(l),read(w);
	for (int i=2;i<=n;i++)
	{
		int x,y;
		read(x),read(y);
		addedge(i,x,y);
		addedge(x,i,y);
	}
	f[0]=n;all=n,root=0,mjy=0;
	getroot(1,0);
	solve(root);
	cout<<mjy/2<<endl;
	return 0;
}