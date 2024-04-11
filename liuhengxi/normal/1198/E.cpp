#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=55,INF=0x3fffffff;
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
namespace dinic
{
	const int N=207,M=500005;
	struct line
	{
		int next,to,cap;
	}e[M<<1];
	int nd,hd[N],cnt,cur[N],s,t,dis[N],q[N],qf,qr;
	inline void adline(int u,int v,int c){e[cnt].to=v;e[cnt].cap=c;e[cnt].next=hd[u];hd[u]=cnt++;}
	inline void adline2(int u,int v,int c){adline(u,v,c);adline(v,u,0);}
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
using dinic::nd;
using dinic::s;
using dinic::t;
using dinic::adline2;
int n,x1[N],x2[N],y1[N],y2[N],xv[N<<1],yv[N<<1],m;
int main()
{
	read(n,n);m=n<<1;
	F(i,0,n)read(x1[i],y1[i],x2[i],y2[i]),--x1[i],--y1[i];
	F(i,0,n)xv[i<<1]=x1[i],xv[i<<1|1]=x2[i],yv[i<<1]=y1[i],yv[i<<1|1]=y2[i];
	sort(xv,xv+m);sort(yv,yv+m);
	F(i,0,n)x1[i]=int(lower_bound(xv,xv+m,x1[i])-xv);
	F(i,0,n)x2[i]=int(lower_bound(xv,xv+m,x2[i])-xv);
	F(i,0,n)y1[i]=int(lower_bound(yv,yv+m,y1[i])-yv);
	F(i,0,n)y2[i]=int(lower_bound(yv,yv+m,y2[i])-yv);
	nd=n<<2|2;F(i,0,nd)dinic::hd[i]=-1;s=nd-2;t=nd-1;
	F(i,0,m-1)adline2(s,i,xv[i+1]-xv[i]);
	F(i,0,m-1)adline2(i+m,t,yv[i+1]-yv[i]);
	F(j,0,m)F(k,0,m)
	{
		bool is=false;
		F(i,0,n)is=is||(x1[i]<=j&&j<x2[i]&&y1[i]<=k&&k<y2[i]);
		if(is)adline2(j,k+m,min(xv[j+1]-xv[j],yv[k+1]-yv[k]));
	}
	printf("%d\n",dinic::dinic());
	return 0;
}