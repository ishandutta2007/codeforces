#include<cstdio>
#include<vector>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
	int next,to,dis;
}e[N];
int n,m,q,hd[N],cnt,dfn[N],low[N],ind,sta[N],top,scc[N],scnt;
long long p[N],g[N];
bool ins[N];
inline void adline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void tarjan(int u)
{
	low[u]=dfn[u]=ind++;
	sta[top++]=u;
	ins[u]=true;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		if(!~dfn[v])
		{
			p[v]=p[u]+e[i].dis;
			tarjan(v);
			if(low[v]<low[u])low[u]=low[v];
		}
		else if(ins[v]&&dfn[v]<low[u])low[u]=dfn[v];
	}
	if(dfn[u]==low[u])
	{
		while(sta[--top]!=u)ins[sta[top]]=false,scc[sta[top]]=scnt;
		ins[u]=false;
		scc[u]=scnt++;
	}
}
long long gcd(long long a,long long b){return !b?a:gcd(b,a%b);}
int main()
{
	read(n,m);
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		int u,v,w;--read(u),--read(v),read(w);
		adline(u,v,w);
	}
	F(i,0,n)dfn[i]=-1;
	F(i,0,n)if(!~dfn[i])tarjan(i);
	F(u,0,n)
	{
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to,w=e[i].dis;
			if(scc[u]==scc[v])g[scc[u]]=gcd(g[scc[u]],abs(p[v]-p[u]-w));
		}
	}
	for(read(q);q--;)
	{
		int v,s,t;read(v,s,t);--v;
		puts(s%gcd(g[scc[v]],t)?"NO":"YES");
	}
	return 0;
}