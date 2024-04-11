#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int NN=105,N=85,M=1400,INF=0x3fffffff;
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
struct line
{
	int next,to,cap,cost;
}e[2*M];
int n,b[NN],c[NN];
char str[NN];
int nd,s,t,hd[N],cnt,cur[N],q[N],qf,qr,dis[N];
bool vis[N],inq[N];
inline void adline(int u,int v,int cap,int cost)
{e[cnt].to=v;e[cnt].cap=cap;e[cnt].cost=cost;e[cnt].next=hd[u];hd[u]=cnt++;}
inline void adline2(int u,int v,int cap,int cost){adline(u,v,cap,cost);adline(v,u,0,-cost);}
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
		cost+=tmp*dis[t];
	}
}
int main()
{
	int flow=0,cost=0;
	read(n);
	scanf("%s",str);
	F(i,0,n)read(b[i]);
	F(i,0,nd=(t=(s=n/2+26)+1)+1)hd[i]=-1;
	F(i,0,n)++c[str[i]-'a'];
	F(i,0,26)adline2(s,i,c[i],0);
	F(i,0,n/2)F(j,0,26)
	{
		int a=0;
		if(str[i]-'a'==j)a=b[i];
		if(str[n-1-i]-'a'==j&&b[n-1-i]>a)a=b[n-1-i];
		adline2(j,i+26,1,-a);
	}
	F(i,0,n/2)adline2(i+26,t,2,0);
	ssp(flow,cost);
	printf("%d\n",-cost);
	return 0;
}