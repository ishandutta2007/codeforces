#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2.5e5+5,M=5e5+5;
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
}e[2*M];
int n,m,k,hd[N],cnt,up[N][2],fa[N],dep[N];
bool vis[N],leaf[N];
inline void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u)
{
	leaf[u]=vis[u]=true;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		if(vis[v])continue;
		leaf[u]=false;
		fa[v]=u;
		dep[v]=dep[u]+1;
		dfs(v);
	}
	if(leaf[u])
	{
		int c=0;
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			if(v!=fa[u])up[u][c]=v,c=1;
		}
	}
}
int main()
{
	read(n,m,k);
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		int u,v;read(u,v);--u,--v;
		adline(u,v);
		adline(v,u);
	}
	dfs(0);
	int maxd=0,v=0;
	F(i,1,n)if(dep[i]>maxd)maxd=dep[i],v=i;
	if(maxd+1>=n/k)
	{
		puts("PATH");
		printf("%d\n",dep[v]+1);
		while(v)printf("%d ",v+1),v=fa[v];
		puts("1");
		return 0;
	}
	puts("CYCLES");
	F(i,0,n)if(leaf[i]&&k)
	{
		--k;
		int len=dep[i]-dep[up[i][0]]+1;
		if(len%3)
		{
			printf("%d\n",len);
			for(int u=i;u!=up[i][0];u=fa[u])printf("%d ",u+1);
			printf("%d\n",up[i][0]+1);
		}
		else if((len=dep[i]-dep[up[i][1]]+1)%3)
		{
			printf("%d\n",len);
			for(int u=i;u!=up[i][1];u=fa[u])printf("%d ",u+1);
			printf("%d\n",up[i][1]+1);
		}
		else
		{
			if(dep[up[i][0]]<dep[up[i][1]])swap(up[i][0],up[i][1]);
			len=dep[up[i][0]]-dep[up[i][1]]+2;
			printf("%d\n",len);
			printf("%d ",i+1);
			for(int u=up[i][0];u!=up[i][1];u=fa[u])printf("%d ",u+1);
			printf("%d\n",up[i][1]+1);
		}
	}
	return 0;
}