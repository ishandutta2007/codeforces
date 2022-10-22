#include<cstdio>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
constexpr int N=2e5+5;
int n,m,q,dep[N],tag[N],f1[N],f2[N],s[N],t[N],logn,f[N][20],g[N][2];
vector<int> oe[N],be[N];
bool vis[N],ans=true;
int find1(int x){return f1[x]==x?x:f1[x]=find1(f1[x]);}
int find2(int x){return f2[x]==x?x:f2[x]=find2(f2[x]);}
void dfsa(int u,int fa)
{
	vis[u]=true;
	int ffa=fa;
	for(int v:oe[u])if(v!=fa)
	{
		if(!vis[v])
		{
			dep[v]=dep[u]+1;
			dfsa(v,u);
			tag[u]+=tag[v];
		}
		else if(dep[v]<dep[u])++tag[u],--tag[v];
	}
	else fa=-1;
	if(tag[u])f2[find2(u)]=ffa;
}
void dfsb(int u)
{
	F(i,0,logn)f[u][i+1]=f[f[u][i]][i];
	for(int v:be[u])
	{
		f[v][0]=u;
		dep[v]=dep[u]+1;
		dfsb(v);
	}
}
int lca(int u,int v)
{
	for(int &c=dep[u]>dep[v]?u:v,k=dep[c]-dep[c^u^v],j=0;k;k>>=1,++j)if(k&1)c=f[c][j];
	if(u==v)return u;
	for(int j=logn;~j;--j)if(f[u][j]!=f[v][j])u=f[u][j],v=f[v][j];
	return f[u][0];
}
void dfsc(int u)
{
	for(int v:be[u])
	{
		dfsc(v);
		if(g[v][0]&&g[v][1])ans=false;
		g[u][0]+=g[v][0];
		g[u][1]+=g[v][1];
	}
}
int main()
{
	read(n,m,q);
	F(i,0,n)f2[i]=f1[i]=i;
	F(i,0,m)
	{
		int u,v;read(u,v);--u,--v;
		oe[u].emplace_back(v);
		oe[v].emplace_back(u);
		f1[find1(u)]=find1(v);
	}
	F(i,0,n)if(!vis[i])dfsa(i,i);
	F(i,0,q)read(s[i],t[i]),--s[i],--t[i];
	F(i,0,q)if(find1(s[i])!=find1(t[i]))return puts("No"),0;else s[i]=find2(s[i]),t[i]=find2(t[i]);
	while((1<<logn)<n-1)++logn;
	F(u,0,n)for(int v:oe[u])if(dep[v]>dep[u]&&find2(v)!=find2(u))be[f2[u]].emplace_back(f2[v]);
	F(i,0,n)if(!dep[i])dfsb(f[i][0]=i);
	F(i,0,q)if(s[i]!=t[i])
	{
		int a=lca(s[i],t[i]);
		++g[s[i]][0];
		--g[a][0];
		++g[t[i]][1];
		--g[a][1];
	}
	F(i,0,n)if(!dep[i])dfsc(i);
	puts(ans?"Yes":"No");
	return 0;
}