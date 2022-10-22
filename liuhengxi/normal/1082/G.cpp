#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e3+7,M=4e3+5;
const long long LLINF=0x3fffffff;
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
struct line
{
	int next,to;long long cap;
}e[2*M];
int nd,s,t,hd[N],cur[N],cnt,dis[N],q[N],qf,qr;
bool bfs()
{
	F(i,0,nd)cur[i]=hd[i],dis[i]=-1;
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
	while(bfs())ans+=dfs(s,LLINF);
	return ans;
}
inline void adline(int u,int v,long long c){e[cnt].to=v;e[cnt].cap=c;e[cnt].next=hd[u];hd[u]=cnt++;}
inline void adline2(int u,int v,long long c){adline(u,v,c);adline(v,u,0);}
int main()
{
	int n,m;
	long long ans=0;
	read(n,m);nd=(t=(s=n+m)+1)+1;
	F(i,0,nd)hd[i]=-1;
	F(i,0,n)
	{
		int a;read(a);
		adline2(s,i,a);
	}
	F(i,0,m)
	{
		int u,v,w;--read(u);--read(v);read(w);
		adline2(u,i+n,LLINF);
		adline2(v,i+n,LLINF);
		adline2(i+n,t,w);
		ans+=w;
	}
	ans-=dinic();
	printf("%lld\n",ans);
	return 0;
}