#include<cstdio>
#include<vector>
#include<queue>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=2e5+5,M=3e5+5;
constexpr long long LLINF=0x3fffffffffffffffll;
struct line
{
	int next,to,dis;
}e[2*M];
struct nodedis
{
	int node;long long dis;
	friend bool operator<(nodedis a,nodedis b){return b.dis<a.dis;}
};
int n,m,s,hd[N],cnt,b[N],q[N],qf,qr,in[N],ib[N],siz[N],ans;long long dis[N];bool vis[N];
vector<int> adj[N];
priority_queue<nodedis> pq;
void addline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int main()
{
	read(n,m,s);--s;
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		int u,v,w;read(u,v,w);--u,--v;
		addline(u,v,w);
		addline(v,u,w);
	}
	F(i,0,n)dis[i]=LLINF;
	dis[s]=0;
	pq.push({s,0});
	while(!pq.empty())
	{
		int u=pq.top().node;pq.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to,w=e[i].dis;
			if(dis[v]>dis[u]+w)dis[v]=dis[u]+w,pq.push({v,dis[v]});
		}
	}
	F(i,0,m)
	{
		int u=e[i<<1].to,v=e[i<<1|1].to,w=e[i<<1].dis;
		if(dis[v]==dis[u]+w)adj[u].emplace_back(v),++in[v];
		if(dis[u]==dis[v]+w)adj[v].emplace_back(u),++in[u];
	}
	F(i,0,n)b[i]=i,ib[i]=-1;
	q[qr++]=s;
	while(qf<qr)
	{
		int u=q[qf++];
		if(u!=s&&ib[u]!=-2&&ib[u]!=s)b[u]=ib[u];
		for(int v:adj[u])
		{
			if(!~ib[v])ib[v]=b[u];
			else if(ib[v]!=b[u])ib[v]=-2;
			if(--in[v]==0)q[qr++]=v;
		}
	}
	F(i,0,n)++siz[b[i]];
	F(i,0,n)ans=max(ans,siz[i]);
	if(adj[s].empty())ans=0;
	printf("%d\n",ans);
	return 0;
}