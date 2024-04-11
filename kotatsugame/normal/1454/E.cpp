#line 1 "a.cpp"
#include<cstdio>
#include<vector>
using namespace std;
#line 2 "/home/kotatsugame/library/datastructure/UF.cpp"
struct UF{
	int n;
	vector<int>parent,rank;
	UF(int n_=0):n(n_),parent(n_),rank(n_,1)
	{
		for(int i=0;i<n_;i++)parent[i]=i;
	}
	int find(int a){return parent[a]!=a?parent[a]=find(parent[a]):a;}
	bool same(int a,int b){return find(a)==find(b);}
	bool unite(int a,int b)
	{
		a=find(a),b=find(b);
		if(a==b)return false;
		if(rank[a]<rank[b])
		{
			parent[a]=b;
			rank[b]+=rank[a];
		}
		else
		{
			parent[b]=a;
			rank[a]+=rank[b];
		}
		return true;
	}
	int size(int a){return rank[find(a)];}
};
#line 5 "a.cpp"
int T,N;
vector<vector<int> >G;
vector<int>loop;
bool dfs(int u,int p,int to)
{
	loop.push_back(u);
	if(u==to)return true;
	for(int v:G[u])if(v!=p)
	{
		if(dfs(v,u,to))return true;
	}
	loop.pop_back();
	return false;
}
bool vis[2<<17];
int cnt(int u)
{
	int ret=1;
	vis[u]=true;
	for(int v:G[u])if(!vis[v])ret+=cnt(v);
	return ret;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		G.clear();
		G.assign(N,vector<int>());
		vector<pair<int,int> >Es(N);
		for(int i=0;i<N;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			Es[i]=make_pair(u,v);
			vis[i]=false;
		}
		UF uf(N);
		int U,V;
		int ei;
		for(int i=0;i<N;i++)
		{
			int u=Es[i].first,v=Es[i].second;
			if(!uf.unite(u,v))
			{
				U=u;
				V=v;
				ei=i;
				break;
			}
			G[u].push_back(v);
			G[v].push_back(u);
		}
		loop.clear();
		dfs(U,-1,V);
		for(int i=ei;i<N;i++)
		{
			int u=Es[i].first,v=Es[i].second;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		long long ans=(long long)N*(N-1);
		for(int u:loop)vis[u]=true;
		for(int u:loop)
		{
			int c=cnt(u);
			ans-=(long long)c*(c-1)/2;
		}
		printf("%lld\n",ans);
	}
}