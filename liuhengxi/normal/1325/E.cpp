#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=1e6+5,INF=0x3fffffff,P=200;
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
	int next,to;
}e[2*N];
int n,a[N],b[N][3],c[N],ans=N,fac[M],p=169,m=78499,mp[M],hd[N],cnt,dis[N],q[N],qf,qr;
bool fsb[M],use[N];
namespace number_theory
{
	int pri[M],cnt;
	bool vis[M];
	void init()
	{
		F(i,2,M)
		{
			if(!vis[i])fac[pri[cnt++]=i]=i;
			F(j,0,cnt)
			{
				int x=i*pri[j];
				if(x>=M)break;
				vis[x]=true;fac[x]=pri[j];
				if(i%pri[j]==0)break;
			}
		}
		F(i,0,cnt)mp[pri[i]]=i+1;
	}
}
using number_theory::init;
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void bfs(int s)
{
	F(i,0,m)dis[i]=INF;
	qf=qr=0;
	dis[q[qr++]=s]=0;
	F(i,0,n)use[i]=false;
	while(qf<qr)
	{
		int u=q[qf++];
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			if(dis[v]>dis[u]+1)
			{
				use[i>>1]=true;
				dis[v]=dis[u]+1;
				q[qr++]=v;
			}
		}
	}
	F(i,0,n)if(!use[i]&&dis[b[i][0]]+dis[b[i][1]]+1<ans)ans=dis[b[i][0]]+dis[b[i][1]]+1;
}
int main()
{
	init();
	read(n);
	F(i,0,m)hd[i]=-1;
	F(i,0,n)
	{
		read(a[i]);
		for(int x=a[i];x!=1;x/=fac[x])fsb[fac[x]]^=1;
		c[i]=0;b[i][0]=0;b[i][1]=0;
		for(int x=a[i];x!=1;x/=fac[x])if(fsb[fac[x]])
		{
			b[i][c[i]++]=mp[fac[x]];
			fsb[fac[x]]=false;
		}
		if(c[i]==0)return puts("1"),0;
		adline(b[i][0],b[i][1]);adline(b[i][1],b[i][0]);
	}
	F(i,0,p)bfs(i);
	if(ans==N)ans=-1;
	printf("%d\n",ans);
	return 0;
}