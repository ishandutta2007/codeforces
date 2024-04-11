#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
	int next,to;
}e[2*N];
int n,a[N],hd[N],cnt;
long long f1[N],f2[N],g1[N],g2[N];
void addline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int fa)
{
	long long f2m=0;
	g2[u]=g1[u]=f2[u]=f1[u]=a[u];
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);
		g2[u]=max(g2[u],g1[u]+f1[v]);
		g2[u]=max(g2[u],f1[u]+g1[v]);
		g2[u]=max(g2[u],f2[u]+f2[v]);
		g2[u]=max(g2[u],g2[v]);
		g1[u]=max(g1[u],g1[v]+a[u]);
		g1[u]=max(g1[u],f1[u]+f2[v]);
		g1[u]=max(g1[u],f2m+f1[v]+a[u]);
		f2m=max(f2m,f2[v]);
		f2[u]=max(f2[u],f1[u]+f1[v]);
		f2[u]=max(f2[u],f2[v]);
		f1[u]=max(f1[u],f1[v]+a[u]);
	}
}
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u,v);--u,--v;
		addline(u,v);
		addline(v,u);
	}
	dfs(0,0);
	printf("%lld\n",g2[0]);
	return 0;
}