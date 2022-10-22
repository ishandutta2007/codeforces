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
constexpr int N=1e6+5;
int n,m,x[N],t,r,ansc;
bool e[N],ans[N],cov[N];
vector<int> adj[N];
int main()
{
	read(n,m);
	F(i,0,m)
	{
		int u,v;read(u,v);--u,--v;
		adj[u].emplace_back(v);
	}
	F(i,0,n)e[i]=true;
	while(r<n)
	{
		int &u=x[t];
		if(t)u=x[t-1]+1;
		++t;
		while(!e[u])++u;
		e[u]=false;
		++r;
		for(int v:adj[u])r+=e[v],e[v]=false;
	}
	while(t)
	{
		--t;
		int &u=x[t];
		if(!cov[u])
		{
			ans[u]=true;
			for(int v:adj[u])cov[v]=true;
		}
	}
	F(i,0,n)ansc+=ans[i];
	printf("%d\n",ansc);
	F(i,0,n)if(ans[i])printf("%d ",i+1);
	puts("");
	return 0;
}