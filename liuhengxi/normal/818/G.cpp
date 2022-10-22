#include<cstdio>
#define F(i,l,r) for(int i=l,i##_en=r;i<i##_en;++i)
using namespace std;
const int N=3005,M=1e5+5,INF=0x3fffffff;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
namespace flow
{
	const int N=4*::N+4,M=10*::N+2;
	struct line
	{
		int next,to,cap,cost;
	}e[2*M];
	int n,hd[N],cur[N],cnt,q[N],qf,qr,s,t;
	long long dis[N];
	bool vis[N],inq[N];
	inline void init(int n_,int s_,int t_){F(i,cnt=0,n=n_)hd[i]=-1;s=s_,t=t_;}
	inline void adline(int u,int v,int cap,int cost)
	{
		e[cnt].to=v;
		e[cnt].cap=cap;
		e[cnt].cost=cost;
		e[cnt].next=hd[u];
		hd[u]=cnt++;
	}
	inline void adline2(int u,int v,int cap,int cost){adline(u,v,cap,cost);adline(v,u,0,-cost);}
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
		flow=cost=0;
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
using flow::init;using flow::adline2;using flow::ssp;
int n,a[N],s,t,lm[7],le[M],useless;long long ans;
int &S=flow::s,&T=flow::t;
inline int in(int x){return x<<2|0;}
inline int out(int x){return x<<2|1;}
inline int equ(int x){return x<<2|2;}
inline int mod(int x){return x<<2|3;}
int main()
{
	F(i,0,read(n))read(a[i]);
	init(4*n+4,4*n+2,4*n+3);
	s=4*n,t=4*n+1;
	adline2(S,s,4,0);
	adline2(t,T,4,0);
	F(i,0,n)
	{
		adline2(s,in(i),1,0),adline2(out(i),t,1,0);
		adline2(in(i),out(i),1,-1);
		adline2(equ(i),in(i),1,0),adline2(mod(i),in(i),1,0);
	}
	F(i,0,7)lm[i]=-1;
	F(i,0,M)le[i]=-1;
	for(int i=n;~--i;)
	{
		if(~le[a[i]-1])adline2(out(i),equ(le[a[i]-1]),1,0);
		if(~le[a[i]])adline2(equ(i),equ(le[a[i]]),INF,0);
		if(~le[a[i]+1])adline2(out(i),equ(le[a[i]+1]),1,0);
		if(~lm[a[i]%7])adline2(mod(i),mod(lm[a[i]%7]),INF,0),adline2(out(i),mod(lm[a[i]%7]),1,0);
		le[a[i]]=i;
		lm[a[i]%7]=i;
	}
	ssp(useless,ans);
	printf("%lld\n",-ans);
	return 0;
}