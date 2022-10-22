#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
struct line
{
	int next,to;
}e[N<<1];
int n,c[N],hd[N],cnt,k;
long long f[N]/*leaf*/,g[N]/*leaf-1*/;
bool of[N],og[N],o[N];
inline void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs1(int u,int fa)
{
	long long s=0,d=0;
	if(u&&!~e[hd[u]].next)return f[u]=c[u],g[u]=0,void();
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs1(v,u);
		s+=f[v];
		if(g[v]-f[v]<d)d=g[v]-f[v];
	}
	g[u]=s+d;
	f[u]=g[u]+c[u];
	if(f[u]>s)f[u]=s;
}
void dfs2(int u,int fa)
{
	long long s=0,d=0;
	bool os=false;int ex=-1;
	if(u&&!~e[hd[u]].next)return o[u]=of[u],void();
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		s+=f[v];
	}
	if(of[u]&&f[u]==s)os=true,ex=n;
	if(of[u]&&f[u]==g[u]+c[u])o[u]=true,og[u]=true;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		d=g[v]-f[v];
		if(og[u]&&s+d==g[u])
		{
			og[v]=true;os=true;
			if(~ex)ex=n;else ex=v;
		}
	}
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		if(os&&v!=ex)of[v]=true;
		dfs2(v,u);
	}
}
int main()
{
	F(i,0,read(n))read(c[i]);
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u,v);
		adline(--u,--v);adline(v,u);
	}
	F(i,0,n)f[i]=g[i]=LLINF;
	dfs1(0,0);
	of[0]=true;
	dfs2(0,0);
	F(i,0,n)if(o[i])++k;
	printf("%lld %d\n",f[0],k);
	F(i,0,n)if(o[i])printf("%d ",i+1);
	puts("");
	return 0;
}