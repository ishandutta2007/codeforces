#include<cstdio>
#include<vector>
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
int n,a,dep[N];
vector<int> adj[N];
void dfs(int u,int fa)
{
	a+=dep[u]&1;
	for(int v:adj[u])if(v!=fa)dep[v]=dep[u]+1,dfs(v,u);
}
int main()
{
	read(n);
	F(i,1,n)
	{
		int u,v;--read(u),--read(v);
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(0,0);
	printf("%d\n",min(a-1,n-1-a));
	return 0;
}