#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
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
int n,m,deg[N],hd[N],cnt,f[N],q,n0,x[N],y[N],fa[N],dep[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int f)
{
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==f)continue;
		dep[v]=dep[u]+1;
		dfs(v,fa[v]=u);
	}
}
int len(int u,int v)
{
	if(u==v)return 1;
	if(dep[u]>dep[v])return len(fa[u],v)+1;
	return len(u,fa[v])+1;
}
void print(int u,int v)
{
	if(u==v)return printf("%d ",u+1),void();
	if(dep[u]>dep[v])return printf("%d ",u+1),print(fa[u],v);
	return print(u,fa[v]),printf("%d ",v+1),void();
}
int main()
{
	read(n);read(m);
	F(i,0,n)hd[f[i]=i]=-1;
	F(i,0,m)
	{
		int u,v;read(u);read(v);--u,--v;
		if(find(u)==find(v))continue;
		f[find(u)]=find(v);
		adline(u,v);adline(v,u);
	}
	read(q);
	F(i,0,q)read(x[i]),read(y[i]),++deg[--x[i]],++deg[--y[i]];
	F(i,0,n)if(deg[i]&1)++n0;
	if(n0)return printf("NO\n%d\n",n0>>1),0;
	dfs(0,0);
	puts("YES");
	F(i,0,q)
	{
		printf("%d\n",len(x[i],y[i]));
		print(x[i],y[i]);puts("");
	}
	return 0;
}