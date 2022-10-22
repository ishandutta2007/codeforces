#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=505,Node=1007,Line=1505,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
bool fail;
struct tree
{
	struct line
	{
		int next,to;
	}e[2*N];
	int hd[N],cnt,col[N],w[N],sw[N];
	void init(int n){F(i,0,n)hd[i]=w[i]=-1;}
	void adline(int u,int v)
	{
		e[cnt].to=v;
		e[cnt].next=hd[u];
		hd[u]=cnt++;
	}
	void dfs(int u,int fa)
	{
		col[u]=~w[u]?u:col[fa];
		if(~w[u])sw[u]=w[u];
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;if(v==fa)continue;
			dfs(v,u);
			if(~w[u])
			{
				w[u]-=sw[v];
				if(w[u]<0)fail=true;
			}
			else sw[u]+=sw[v];
		}
	}
}tree1,tree2;
struct flow
{
	struct line
	{
		int next,to,cap,cost;
	}e[2*Line];
	int hd[Node],cnt,nd,cur[Node],dis[Node],q[Node],qf,qr,s,t;
	bool vis[Node],inq[Node];
	void init(int n,int ss,int tt){nd=n;s=ss;t=tt;F(i,0,n)hd[i]=-1;}
	void adline(int u,int v,int cap,int cost)
	{
		e[cnt].to=v;
		e[cnt].cap=cap;
		e[cnt].cost=cost;
		e[cnt].next=hd[u];
		hd[u]=cnt++;
	}
	void adline2(int u,int v,int cap,int cost){adline(u,v,cap,cost);adline(v,u,0,-cost);}
	bool spfa()
	{
		F(i,0,nd)cur[i]=hd[i],dis[i]=INF,vis[i]=false;
		qf=qr=0;
		dis[q[qr++]=s]=0;qr%=nd;
		inq[s]=true;
		while(qf!=qr)
		{
			int u=q[qf++];qf%=nd;
			inq[u]=false;vis[u]=true;
			for(int i=hd[u];~i;i=e[i].next)if(e[i].cap)
			{
				int v=e[i].to;if(dis[v]<=dis[u]+e[i].cost)continue;
				dis[v]=dis[u]+e[i].cost;if(!inq[v])inq[q[qr++]=v]=true,qr%=nd;
			}
		}
		return vis[t];
	}
	int dfs(int u,int flow)
	{
		int ans=0;
		if(u==t)return flow;
		vis[u]=true;
		for(int i=cur[u];~i;i=e[i].next,cur[u]=i)
		{
			int v=e[i].to,newflow=e[i].cap<flow?e[i].cap:flow;
			if(dis[v]!=dis[u]+e[i].cost||!e[i].cap||vis[v])continue;
			newflow=dfs(v,newflow);
			e[i].cap-=newflow;e[i^1].cap+=newflow;
			flow-=newflow;ans+=newflow;
			if(!flow)break;
		}
		vis[u]=false;
		return ans;
	}
	void ssp(int &flow,int &cost)
	{
		flow=cost=0;
		while(spfa())
		{
			int tmp;
			F(i,0,nd)vis[i]=false;
			tmp=dfs(s,INF);
			flow+=tmp;
			cost+=tmp*(long long)dis[t];
		}
	}
}fl;
int n,x,y,q1,q2,a[N];
int main()
{
	int flow,cost,tot1,tot2;
	read(n);read(x);read(y);--x,--y;
	tree1.init(n);tree2.init(n);
	F(i,0,n)read(a[i]);
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);
		tree1.adline(--u,--v);tree1.adline(v,u);
	}
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);
		tree2.adline(--u,--v);tree2.adline(v,u);
	}
	read(q1);
	while(q1--)
	{
		int k,p;read(k);read(p);
		tree1.w[--k]=p;
		if(k==x)tot1=p;
	}
	read(q2);
	while(q2--)
	{
		int k,p;read(k);read(p);
		tree2.w[--k]=p;
		if(k==y)tot2=p;
	}
	if(tot1!=tot2)return puts("-1"),0;
	tree1.dfs(x,x);tree2.dfs(y,y);
	if(fail)return puts("-1"),0;
	fl.init(2*n+2,2*n,2*n+1);
	F(i,0,n)if(~tree1.w[i])fl.adline2(fl.s,i,tree1.w[i],0);
	F(i,0,n)if(~tree2.w[i])fl.adline2(i+n,fl.t,tree2.w[i],0);
	F(i,0,n)fl.adline2(tree1.col[i],tree2.col[i]+n,1,-a[i]);
	fl.ssp(flow,cost);
	if(flow!=tot1)puts("-1");
	else printf("%d\n",-cost);
	return 0;
}