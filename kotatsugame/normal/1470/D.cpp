#line 1 "a.cpp"
#include<cstdio>
#include<vector>
#include<queue>
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
#line 6 "a.cpp"
int T,N,M;
vector<int>G[3<<17];
int col[3<<17];
bool vis[3<<17];
vector<int>ans;
void dfs(int u)
{
	vis[u]=true;
	if(col[u]==1)
	{
		ans.push_back(u);
		for(int v:G[u])col[v]=2;
		for(int v:G[u])if(!vis[v])dfs(v);
	}
	else
	{
		for(int v:G[u])if(col[v]==0)
		{
			col[v]=1;
			dfs(v);
		}
	}
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)
		{
			G[i].clear();
			col[i]=0;
			vis[i]=false;
		}
		ans.clear();
		UF uf(N);
		int cnt=N;
		for(int i=0;i<M;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			u--,v--;
			if(uf.unite(u,v))cnt--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(cnt!=1)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		col[0]=1;
		dfs(0);
		printf("%d\n",(int)ans.size());
		for(int i=0;i<ans.size();i++)printf("%d%c",ans[i]+1,i+1==ans.size()?10:32);
	}
}