#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=115,INF=0x3fffffff;
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
	int next,to,cap;
}e[2*N*N];
int n,k,p[N],c[N],l[N],hd[N],cnt,cur[N],dis[N],s,t,nd,q[N],qf,qr;
bool ok[N],ban[N][N];
inline void adline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].cap=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
inline void adline2(int u,int v,int w){adline(u,v,w);adline(v,u,0);}
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
bool check(int v)
{
	int sum=0,onemax=0;
	F(i,cnt=0,nd)hd[i]=-1;
	F(i,0,n)if(l[i]<=v&&c[i]==1)onemax=max(onemax,p[i]);
	F(i,0,n)if((ok[i]=l[i]<=v&&((c[i]!=1)||(c[i]==1&&p[i]==onemax&&++onemax))))sum+=p[i];
	F(i,0,n)if(ok[i])
	{
		if(c[i]&1)adline2(s,i,p[i]);
		else adline2(i,t,p[i]);
	}
	F(i,0,n)F(j,i+1,n)if(ok[i]&&ok[j]&&ban[i][j])
	{
		if(c[i]&1)adline2(i,j,INF);else adline2(j,i,INF);
	}
	return sum-dinic()>=k;
}
int solve()
{
	int l=0,r=n+1,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	return r;
}
bool isprime(int x)
{
	for(int i=2;i*i<=x;++i)if(x%i==0)return false;
	return true;
}
int main()
{
	int ans=0;
	read(n,k);nd=n+2;s=n,t=n+1;
	F(i,0,n)read(p[i],c[i],l[i]);
	F(i,0,n)F(j,0,n)ban[i][j]=isprime(c[i]+c[j]);
	ans=solve();
	printf("%d\n",ans<=n?ans:-1);
	return 0;
}