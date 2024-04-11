#include<cstdio>
#include<vector>
#include<algorithm>
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
constexpr int N=20005;
int n,m,f[N],dep[N],tag[N],ans,deg[N],l1[N],l2[N],d;
bool vis[N],rt[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
vector<int> adj[N];
vector<pair<int,int>> ne;
void dfsa(int u,int fa)
{
	vis[u]=true;
	for(int v:adj[u])
	{
		if(vis[v])
		{
			if(v!=fa&&dep[v]<dep[u])++tag[u],--tag[v];
		}
		else
		{
			dep[v]=dep[u]+1;
			dfsa(v,u);
			tag[u]+=tag[v];
		}
	}
	if(tag[u])f[u]=fa;
}
void dfsb(int u,int fa)
{
	for(int v:adj[u])if(v!=fa)
	{
		dfsb(v,u);
		if(l1[v]>l1[u])l2[u]=l1[u],l1[u]=l1[v];
		else if(l1[v]>l2[u])l2[u]=l1[v];
	}
	d=max(d,l1[u]+l2[u]);
	++l1[u];
}
int main()
{
	read(n,m);
	F(i,0,m)
	{
		int u,v;read(u,v);--u,--v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	F(i,0,n)f[i]=i;
	F(i,0,n)if(!vis[i])dfsa(i,i),rt[i]=true;
	F(u,0,n)for(int v:adj[u])
	{
		if(find(u)!=find(v))
		{
			if(f[u]<f[v])ne.emplace_back(f[u],f[v]);
			else ne.emplace_back(f[v],f[u]);
		}
	}
	sort(ne.begin(),ne.end());
	auto rend=unique(ne.begin(),ne.end());
	F(i,0,n)adj[i].clear();
	for(auto i=ne.begin();i<rend;++i)
	{
		++deg[i->first];
		++deg[i->second];
	}
	for(auto i=ne.begin();i<rend;++i)
	{
		if(deg[i->second]>1)adj[i->first].emplace_back(i->second);
		if(deg[i->first]>1)adj[i->second].emplace_back(i->first);
		if(deg[i->first]==1&&deg[i->second]==1)++ans;
	}
	F(i,0,n)ans+=f[i]!=i||deg[i]!=1;
	F(i,0,n)if(rt[i])
	{
		int u=i;
		deg[u]=(int)adj[u].size();
		if(deg[u]==0)continue;
		if(deg[u]==1)u=adj[u][0];
		d=0;
		dfsb(u,u);
		ans-=d;
	}
	printf("%d\n",--ans);
	return 0;
}