#include<cstdio>
#include<algorithm>
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
namespace flow
{
	constexpr int N=1e5+5,M=1e5+5,INF=0x3fffffff;
	constexpr long long LLINF=0x3fffffffffffffff;
	struct line
	{
		int next,to,cap,cost;
	}e[2*M];
	int n,hd[N],cur[N],cnt,q[N],qf,qr,s,t;
	long long dis[N];
	bool vis[N],inq[N];
	inline void init(int n_,int s_,int t_){F(i,cnt=0,n=n_)hd[i]=-1;s=s_,t=t_;}
	inline void addline(int u,int v,int cap,int cost)
	{
		e[cnt].to=v;
		e[cnt].cap=cap;
		e[cnt].cost=cost;
		e[cnt].next=hd[u];
		hd[u]=cnt++;
	}
	inline void addline2(int u,int v,int cap,int cost){addline(u,v,cap,cost);addline(v,u,0,-cost);}
	bool spfa()
	{
		F(i,0,n)cur[i]=hd[i],dis[i]=LLINF,vis[i]=false;
		qf=qr=0;
		dis[q[qr++]=s]=0;qr%=n;
		inq[s]=true;
		while(qf!=qr)
		{
			int u=q[qf++];qf%=n;
			inq[u]=false;vis[u]=true;
			for(int i=hd[u];~i;i=e[i].next)if(e[i].cap)
			{
				int v=e[i].to;if(dis[v]<=dis[u]+e[i].cost)continue;
				dis[v]=dis[u]+e[i].cost;if(!inq[v])inq[q[qr++]=v]=true,qr%=n;
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
	void ssp(int &flow,long long &cost)
	{
		cost=flow=0;
		while(spfa())
		{
			int tmp;
			F(i,0,n)vis[i]=false;
			tmp=dfs(s,INF);
			flow+=tmp;
			cost+=tmp*(long long)dis[t];
		}
	}
};
using flow::init;using flow::addline2;using flow::ssp;
constexpr int N=(1<<20)+5,M=(20<<20)+5;
int n,k,m,a[N],e[M],full,id[N];
bool used[N];
int main()
{
	read(n,k);full=(1<<n)-1;
	F(i,0,1<<n)read(a[i]);
	auto le=[](int u){return u&full;};
	auto ri=[](int u){return (u&full)^1<<(u>>n);};
	m=0;
	F(i,0,n<<n)if(!__builtin_parity(i&full))e[m++]=i;
	m=min(m,(2*n-1)*(k-1)+1);
	nth_element(e,e+m,e+(n<<(n-1)),[&](int u,int v){return a[le(u)]+a[ri(u)]>a[le(v)]+a[ri(v)];});
	F(i,0,m)used[le(e[i])]=used[ri(e[i])]=true;
	int node=0,ss,tt;
	F(i,0,1<<n)if(used[i])id[i]=node++;
	ss=node++;tt=node++;
	init(node+2,node,node+1);
	addline2(flow::s,ss,k,0);addline2(tt,flow::t,k,0);
	F(i,0,1<<n)if(used[i])
	{
		if(__builtin_parity(i))addline2(id[i],tt,1,0);
		else addline2(ss,id[i],1,0);
	}
	F(i,0,m)addline2(id[le(e[i])],id[ri(e[i])],1,-a[le(e[i])]-a[ri(e[i])]);
	int fl;long long cost;
	ssp(fl,cost);
	printf("%lld\n",-cost);
	return 0;
}