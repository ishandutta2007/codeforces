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
constexpr int N=305,X=1e9;
namespace flow
{
	constexpr int N=::N*2+7,M=::N*(::N+2);
	constexpr long long INF=0x3fffffffffffffff;
	struct line
	{
		int next,to;
		long long cap;
	}e[2*M];
	int n,s,t,hd[N],cnt,cur[N],q[N],qf,qr,dis[N];
	inline void init(int n_,int s_,int t_){F(i,cnt=0,n=n_)hd[i]=-1;s=s_,t=t_;}
	inline void addline(int u,int v,long long cap)
	{
		e[cnt].to=v;
		e[cnt].cap=cap;
		e[cnt].next=hd[u];
		hd[u]=cnt++;
	}
	inline void addline2(int u,int v,long long cap){addline(u,v,cap);addline(v,u,0);}
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
	long long dfs(int u,long long flow)
	{
		long long ans=0;
		if(u==t)return flow;
		for(int i=cur[u];~i;i=e[i].next,cur[u]=i)
		{
			int v=e[i].to;long long newflow=e[i].cap<flow?e[i].cap:flow;
			if(dis[v]!=dis[u]+1||!e[i].cap)continue;
			newflow=dfs(v,newflow);
			e[i].cap-=newflow;e[i^1].cap+=newflow;
			flow-=newflow;ans+=newflow;
			if(!flow)break;
		}
		return ans;
	}
	long long dinic()
	{
		long long ans=0;
		while(bfs())ans+=dfs(s,INF);
		return ans;
	}
}
using flow::init;using flow::addline2;using flow::dinic;
int n;
int main()
{
	read(n);
	init(2*n+2,2*n,2*n+1);
	F(i,0,n)
	{
		int m;read(m);
		while(m--)
		{
			int x;--read(x);
			addline2(i,x+n,flow::INF);
		}
	}
	long long sum=0;
	F(i,0,n)
	{
		int x;read(x);
		addline2(flow::s,i,X-x);
		sum+=X-x;
	}
	F(i,0,n)addline2(i+n,flow::t,X);
	printf("%lld\n",dinic()-sum);
	return 0;
}