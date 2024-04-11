#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
	int next,to,dis;
}e[2*N];
int n,m,u[N],v[N],w[N],sum[N],val[30],ans,hd[N],cnt;
bool vis[N];
void insert(int x)
{
	for(int i=28;~i;--i)if(x>>i&1)
	{
		if(!val[i])val[i]=x;
		x^=val[i];
	}
}
void adline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u)
{
	vis[u]=true;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		if(!vis[v])sum[v]=sum[u]^e[i].dis,dfs(v);
	}
}
int main()
{
	read(n);read(m);
	F(i,0,n)hd[i]=-1;
	F(i,0,m)read(u[i]),read(v[i]),read(w[i]),adline(--u[i],--v[i],w[i]),adline(v[i],u[i],w[i]);
	dfs(0);
	F(i,0,m)insert(w[i]^sum[u[i]]^sum[v[i]]);
	ans=sum[n-1];
	for(int i=28;~i;--i)if((ans^val[i])<ans)ans^=val[i];
	printf("%d\n",ans);
	return 0;
}