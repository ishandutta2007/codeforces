#include<cstdio>
#include<queue>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=3e5+5,LogN=20;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int next,to;long long dis;
}e[2*M];
struct node
{
	int id;long long dis;
	node(int a,long long b){id=a,dis=b;}
	bool operator<(node b)const{return b.dis<dis;}
};
struct edge
{
	int u,v;long long w;
	bool operator<(edge b)const{return w<b.w;}
}g[M];
int n,m,k,q,hd[N],cnt,f[N],fa[N][LogN],logn,dep[N];
long long mx[N][LogN],dis[N];bool vis[N];
priority_queue<node> pq;
void adline(int u,int v,long long w)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dij()
{
	F(i,k,n)dis[i]=LLINF;
	F(i,0,k)pq.push(node(i,0));
	while(!pq.empty())
	{
		int u=pq.top().id;pq.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			if(dis[u]+e[i].dis<dis[v])
			{
				dis[v]=dis[u]+e[i].dis;
				pq.push(node(v,dis[v]));
			}
		}
	}
}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void dfs(int u,int f)
{
	fa[u][0]=f;
	F(k,0,logn)mx[u][k+1]=max(mx[u][k],mx[fa[u][k]][k]),fa[u][k+1]=fa[fa[u][k]][k];
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==f)continue;
		dep[v]=dep[u]+1;
		mx[v][0]=e[i].dis;
		dfs(v,u);
	}
}
long long query(int u,int v)
{
	long long ans=0;
	if(dep[u]>dep[v]){for(int i=dep[u]-dep[v],j=0;i;i>>=1,++j)if(i&1)ans=max(ans,mx[u][j]),u=fa[u][j];}
	else for(int i=dep[v]-dep[u],j=0;i;i>>=1,++j)if(i&1)ans=max(ans,mx[v][j]),v=fa[v][j];
	for(int j=logn;~j;--j)if(fa[u][j]!=fa[v][j])ans=max(ans,mx[u][j]),ans=max(ans,mx[v][j]),u=fa[u][j],v=fa[v][j];
	if(u!=v)ans=max(ans,max(mx[u][0],mx[v][0]));
	return ans;
}
int main()
{
	read(n);read(m);read(k);read(q);
	while((1<<logn)<n)++logn;
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		int u,v,w;read(u);read(v);read(w);
		adline(--u,--v,w);adline(v,u,w);
	}
	dij();
	F(i,0,m)g[i].u=e[i<<1].to,g[i].v=e[i<<1|1].to,g[i].w=e[i<<1].dis+dis[g[i].u]+dis[g[i].v];
	sort(g,g+m);
	F(i,cnt=0,n)f[i]=i,hd[i]=-1;
	F(i,0,m)if(find(g[i].u)!=find(g[i].v))
	{
		adline(g[i].u,g[i].v,g[i].w);
		adline(g[i].v,g[i].u,g[i].w);
		f[find(g[i].u)]=find(g[i].v);
	}
	dfs(0,0);
	while(q--)
	{
		int u,v;read(u);read(v);
		printf("%lld\n",query(--u,--v));
	}
	return 0;
}