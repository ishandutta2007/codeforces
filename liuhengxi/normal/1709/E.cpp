#include<cstdio>
#include<vector>
#include<set>
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
int n,a[N],id[N],ans,s[N];
vector<int> adj[N];
set<int> t[N];
bool dfs(int u,int fa)
{
	bool del=false;
	id[u]=u;
	t[id[u]].emplace(s[u]);
	for(int v:adj[u])if(v!=fa)
	{
		s[v]=s[u]^a[v];
		if(!dfs(v,u))
		{
			if(t[id[v]].size()>t[id[u]].size())
			{
				for(int x:t[id[u]])if(t[id[v]].count(x^a[u]))del=true;
				for(int x:t[id[u]])t[id[v]].insert(x);
				id[u]=id[v];
			}
			else
			{
				for(int x:t[id[v]])if(t[id[u]].count(x^a[u]))del=true;
				for(int x:t[id[v]])t[id[u]].insert(x);
			}
		}
	}
	ans+=del;
	return del;
}
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	F(i,0,n-1)
	{
		int u,v;read(u,v);--u,--v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(0,0);
	printf("%d\n",ans);
	return 0;
}