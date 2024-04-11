#include<cstdio>
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
constexpr int N=205,INF=0x3fffffff;
namespace flow
{
	const int N=2*::N*::N+2,M=6*::N*::N;
	struct line
	{
		int next,to,cap;
	}e[2*M];
	int n,s,t,hd[N],cnt,cur[N],q[N],qf,qr,dis[N];
	inline void init(int n_,int s_,int t_){F(i,cnt=0,n=n_)hd[i]=-1;s=s_,t=t_;}
	inline void addline(int u,int v,int cap)
	{
		e[cnt].to=v;
		e[cnt].cap=cap;
		e[cnt].next=hd[u];
		hd[u]=cnt++;
	}
	inline void addline2(int u,int v,int cap){addline(u,v,cap);addline(v,u,0);}
	bool bfs()
	{
		F(i,0,n)cur[i]=hd[i],dis[i]=-1;
		qf=qr=0;
		dis[q[qr++]=s]=0;
		while(qf<qr)
		{
			int u=q[qf++];
			for(int i=hd[u];~i;i=e[i].next)if(e[i].cap)
			{
				int v=e[i].to;if(~dis[v])continue;
				dis[q[qr++]=v]=dis[u]+1;
			}
		}
		return ~dis[t];
	}
	int dfs(int u,int flow)
	{
		int ans=0;
		if(u==t)return flow;
		for(int i=cur[u];~i;i=e[i].next,cur[u]=i)
		{
			int v=e[i].to,newflow=e[i].cap<flow?e[i].cap:flow;
			if(dis[v]!=dis[u]+1||!e[i].cap)continue;
			newflow=dfs(v,newflow);
			e[i].cap-=newflow;e[i^1].cap+=newflow;
			flow-=newflow;ans+=newflow;
			if(!flow)break;
		}
		return ans;
	}
	int dinic()
	{
		int ans=0;
		while(bfs())ans+=dfs(s,INF);
		return ans;
	}
}
using flow::init;using flow::addline2;using flow::dinic;
int n,m,r[N][N],d[N][N];
char s[N][N];
int main()
{
	int nd=0,ans=0;
	read(n,m);
	F(i,0,n)scanf("%s",s[i]);
	F(i,0,n)F(j,0,m)ans+=s[i][j]=='#';
	F(i,0,n)F(j,0,m-1)r[i][j]=nd++;
	F(i,0,n-1)F(j,0,m)d[i][j]=nd++;
	init(nd+2,nd,nd+1);
	F(i,0,n-1)F(j,0,m-1)
	{
		addline2(r[i][j],d[i][j],1);
		addline2(r[i+1][j],d[i][j],1);
		addline2(r[i][j],d[i][j+1],1);
		addline2(r[i+1][j],d[i][j+1],1);
	}
	F(i,0,n)F(j,0,m-1)if(s[i][j]=='#'&&s[i][j+1]=='#')addline2(flow::s,r[i][j],1),--ans;
	F(i,0,n-1)F(j,0,m)if(s[i][j]=='#'&&s[i+1][j]=='#')addline2(d[i][j],flow::t,1),--ans;
	ans+=dinic();
	printf("%d\n",ans);
	return 0;
}