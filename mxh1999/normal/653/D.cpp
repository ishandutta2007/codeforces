#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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

#define maxn 1010
#define maxm 5010
const long double eps=1e-12;
const ll INF=1LL<<60;
struct Edge2
{
	int x,y,w;
}	a[maxm];
int n,m;
int S,T;
struct Edge
{
	int v,next;
	ll flow;
}	e[maxm<<1];
int g[maxn],tot;
void addedge(int x,int y,ll flow)
{
	e[++tot].v=y;e[tot].flow=flow;e[tot].next=g[x];g[x]=tot;
	e[++tot].v=x;e[tot].flow=0;e[tot].next=g[y];g[y]=tot;
}
int w[maxn],hash[maxn],d[maxn];
int que[maxn],pre1[maxn],pre2[maxn],p[maxn];
bool vis[maxn];
ll maxflow()
{
	for (int i=1;i<=n;i++)	hash[i]=0,d[i]=0,vis[i]=false;
	for (int i=1;i<=n;i++)	p[i]=g[i];
	//hash[0]=n;
	int l,r;
	l=r=1;
	que[1]=T;hash[0]=1;vis[T]=true;
	while (l<=r)
	{
		int u=que[l++];
		for (int i=g[u];i;i=e[i].next)
		if ((i&1) && !vis[e[i].v])
		{
			que[++r]=e[i].v;
			vis[e[i].v]=true;
			d[e[i].v]=d[u]+1;
			hash[d[e[i].v]]++;
		}
	}
	for (int i=1;i<=n;i++)
	if (!vis[i])	d[i]=n,hash[n]++;
	ll flow=INF;
	ll mjy=0;
	int u=S;
	while (d[S]<n)
	{
		w[u]=flow;
		bool bo=true;
		for (int i=p[u];i;i=e[i].next)
		if (e[i].flow && d[e[i].v]==d[u]-1)
		{
			flow=min(flow,e[i].flow);
			p[u]=i;
			pre1[e[i].v]=u;
			pre2[e[i].v]=i;
			u=e[i].v;
			bo=false;
			if (u==T)
			{
				mjy+=flow;
				while (u!=S)
				{
					e[pre2[u]].flow-=flow;
					e[pre2[u]^1].flow+=flow;
					u=pre1[u];
				}
				flow=INF;
			}
			break;
		}
		if (!bo)	continue;
		int MIN=n,pos=0;
		for (int i=g[u];i;i=e[i].next)
		if (e[i].flow && d[e[i].v]<MIN)	MIN=d[e[i].v],pos=i;
		p[u]=pos;
		hash[d[u]]--;
		if (hash[d[u]]==0)	break;
		d[u]=MIN+1;
		hash[d[u]]++;
		if (u!=S)	u=pre1[u],flow=w[u];
	}
	return mjy;
}

void clear()
{
	tot=1;
	for (int i=1;i<=n;i++)	g[i]=0;
}
int main()
{
	int nn,mm,x;
	read(nn),read(mm),read(x);
	int maxx=0;
	for (int i=1;i<=mm;i++)	read(a[i].x),read(a[i].y),read(a[i].w),maxx=max(maxx,a[i].w);
	long double l=0,r=maxx;
	n=nn;
	S=1,T=n;
	while (r-l>eps)
	{
		clear();
		long double mid=(l+r)/2;
		for (int i=1;i<=mm;i++)
		{
			ll x=floor(a[i].w/mid+1e-8);
			addedge(a[i].x,a[i].y,x);
		}
		if (maxflow()<x)	r=mid;else l=mid;
	}
	printf("%.8lf\n",(double)l*x);
	return 0;
}