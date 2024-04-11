#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2005,Nd=2*N+2,M=3*N,INF=0x3fffffff;
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
	int next,to,cap;
}e[2*M];
int n1,n2,m,hd[Nd],cnt,s,t,nd,deg[Nd],mindeg=N,r[Nd],q[Nd],qf,qr,dis[Nd],cur[Nd];
int anscnt[N];bool ans[N][Nd];
inline void adline(int u,int v,int c){e[cnt].to=v;e[cnt].next=hd[u];e[cnt].cap=c;hd[u]=cnt++;}
inline void adline2(int u,int v,int c){adline(u,v,c);adline(v,u,0);}
bool bfs()
{
	F(i,0,nd)dis[i]=-1,cur[i]=hd[i];
	dis[q[(qr=qf=0)++]=s]=0;
	while(qf<qr)
	{
		int u=q[qf++];
		for(int i=hd[u];~i;i=e[i].next)if(e[i].cap)
		{
			int v=e[i].to;
			if(!~dis[v])dis[q[qr++]=v]=dis[u]+1;
		}
	}
	return ~dis[t];
}
int dfs(int u,int flow)
{
	int ans=0;
	if(u==t)return flow;
	for(int i=cur[u],v;flow&&~i;cur[u]=i=e[i].next)if(e[i].cap&&dis[v=e[i].to]==dis[u]+1)
	{
		int newflow=e[i].cap<flow?e[i].cap:flow;
		newflow=dfs(v,newflow);
		flow-=newflow;ans+=newflow;
		e[i].cap-=newflow;e[i^1].cap+=newflow;
	}
	return ans;
}
void dinic()
{
	while(bfs())dfs(s,INF);
}
int main()
{
	read(n1);read(n2);read(m);s=n1+n2;t=s+1;nd=t+1;
	F(i,0,nd)hd[i]=-1;
	F(i,0,m){int u,v;read(u);read(v);--u,--v,v+=n1;adline2(u,v,1);++deg[u],++deg[v];}
	F(i,0,s)mindeg=min(mindeg,deg[i]);
	F(i,0,n1)r[i]=cnt,adline2(s,i,deg[i]-mindeg);
	F(i,n1,s)r[i]=cnt,adline2(i,t,deg[i]-mindeg);
	for(int k=mindeg;~k;--k)
	{
		dinic();
		F(i,0,s)++e[r[i]].cap;
		F(i,0,m)anscnt[k]+=(ans[k][i]=e[i<<1].cap);
	}
	F(i,0,mindeg+1)
	{
		printf("%d ",anscnt[i]);
		F(j,0,m)if(ans[i][j])printf("%d ",j+1);
		puts("");
	}
	return 0;
}