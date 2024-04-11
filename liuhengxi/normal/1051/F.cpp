#include<cstdio>
#include<queue>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
	int next,to,dis,type;
}e[2*N];
struct nodedis
{
	int id;long long dis;
	nodedis(int a,long long b){id=a;dis=b;}
	bool operator<(nodedis b)const{return dis>b.dis;}
};
int n,m,uu[45],vv[45],len[45],m2,f[N],hd[N],cnt,fa[N][20],logn,dep[N];
long long dis[45][N],rtdis[N];
bool vis[N];
priority_queue<nodedis> q;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void adline(int u,int v,int w,int t)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].type=t;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dijkstra(long long *dis,int s)
{
	F(i,0,n)dis[i]=LLINF,vis[i]=false;
	dis[s]=0;
	q.push(nodedis(s,0));
	while(!q.empty())
	{
		int u=q.top().id;q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].dis)
			{
				dis[v]=dis[u]+e[i].dis;
				q.push(nodedis(v,dis[v]));
			}
		}
	}
}
void dfs(int u,int f)
{
	fa[u][0]=f;
	F(i,0,logn)fa[u][i+1]=fa[fa[u][i]][i];
	for(int i=hd[u];~i;i=e[i].next)if(e[i].type)
	{
		int v=e[i].to;if(v==f)continue;
		rtdis[v]=rtdis[u]+e[i].dis;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
int lca(int u,int v)
{
	int k=dep[u]-dep[v];
	if(k>0){for(int i=0;k;k>>=1,++i)if(k&1)u=fa[u][i];}
	else{k=-k;for(int i=0;k;k>>=1,++i)if(k&1)v=fa[v][i];}
	for(int i=logn;~i;--i)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return u!=v?fa[u][0]:u;
}
int main()
{
	int q;
	read(n);read(m);while((1<<logn)<n)++logn;
	F(i,0,n)hd[i]=-1,f[i]=i;
	F(i,0,m)
	{
		int u,v,w;read(u);read(v);read(w);--u,--v;
		if(find(u)!=find(v))adline(u,v,w,1),adline(v,u,w,1),f[find(u)]=find(v);
		else adline(u,v,w,0),adline(v,u,w,0),uu[m2]=u,vv[m2]=v,len[m2++]=w;
	}
	F(i,0,m2)dijkstra(dis[i<<1],uu[i]),dijkstra(dis[i<<1|1],vv[i]);
	dfs(0,0);
	read(q);
	while(q--)
	{
		int u,v;long long ans;read(u);read(v);--u,--v;
		ans=rtdis[u]+rtdis[v]-(rtdis[lca(u,v)]<<1);
		F(i,0,m2)
		{
			ans=min(ans,dis[i<<1][u]+dis[i<<1|1][v]+len[i]);
			ans=min(ans,dis[i<<1][v]+dis[i<<1|1][u]+len[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}