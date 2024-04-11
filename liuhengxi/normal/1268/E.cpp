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
constexpr int N=5e5+5;
int n,m,ff[N],u[N],v[N],f[N],g[N],dep[N],a[N],al;
bool is[N];
vector<int> adj[N];
int find(int x){return ff[x]==x?x:ff[x]=find(ff[x]);}
void dfs(int uu,int fa)
{
	for(int i:adj[uu])
	{
		int vv=u[i]^v[i]^uu;
		if(vv!=fa)
		{
			dep[vv]=dep[uu]+1;
			ff[vv]=i;
			dfs(vv,uu);
		}
	}
}
void getpath(int x,int y)
{
	if(x==y)return;
	if(dep[x]>dep[y])
	{
		a[al++]=ff[x];
		getpath(x^u[ff[x]]^v[ff[x]],y);
	}
	else
	{
		getpath(x,y^u[ff[y]]^v[ff[y]]);
		a[al++]=ff[y];
	}
}
int main()
{
	read(n,m);
	for(int i=m;~--i;)--read(u[i]),--read(v[i]);
	F(i,0,n)ff[i]=i;
	F(i,0,m)if(find(u[i])!=find(v[i]))
	{
		ff[find(u[i])]=find(v[i]);
		adj[u[i]].emplace_back(i);
		adj[v[i]].emplace_back(i);
		is[i]=true;
	}
	F(i,0,n)ff[i]=0;
	dfs(0,0);
	F(i,0,n)f[i]=1;
	F(i,0,m)if(is[i])
	{
		int sum=f[u[i]]+f[v[i]];
		g[i]=f[u[i]]=f[v[i]]=sum;
	}
	else
	{
		int sum=f[u[i]]+f[v[i]];
		al=0,getpath(u[i],v[i]);
		int mn=0;
		bool mo=true;
		F(j,1,al)if(a[j]<a[mn])mn=j;
		F(j,0,mn)mo=mo&&a[j]>a[j+1];
		F(j,mn,al-1)mo=mo&&a[j]<a[j+1];
		if(mo)sum-=g[a[mn]];
		f[u[i]]=f[v[i]]=sum;
	}
	F(i,0,n)printf("%d ",--f[i]);
	puts("");
	return 0;
}