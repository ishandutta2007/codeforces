#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#include<vector>
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
#include<vector>
struct LCA{
	int N;
	vector<vector<int> >G,parent;
	vector<int>depth;
	LCA(int N_=0):N(N_),G(N_),depth(N_)
	{
		int lg=0;
		while((1<<lg)+1<N_)lg++;
		parent.assign(lg+1,vector<int>(N_));
	}
	void add_edge(int u,int v)
	{
		G[u].push_back(v);
		G[v].push_back(u);
	}
	void dfs(int u,int p,int d)
	{
		depth[u]=d;
		parent[0][u]=p;
		for(int v:G[u])if(v!=p)dfs(v,u,d+1);
	}
	void build(int root=0)
	{
		dfs(root,-1,0);
		for(int k=1;k<parent.size();k++)
		{
			for(int i=0;i<N;i++)
			{
				if(parent[k-1][i]==-1)parent[k][i]=-1;
				else parent[k][i]=parent[k-1][parent[k-1][i]];
			}
		}
	}
	int lca(int u,int v)
	{
		if(depth[u]>depth[v])swap(u,v);
		for(int k=0;k<parent.size();k++)if(depth[v]-depth[u]>>k&1)v=parent[k][v];
		if(u==v)return u;
		for(int k=parent.size();k--;)if(parent[k][u]!=parent[k][v])
		{
			u=parent[k][u];
			v=parent[k][v];
		}
		return parent[0][u];
	}
	int dist(int u,int v)
	{
		int w=lca(u,v);
		return depth[u]+depth[v]-2*depth[w];
	}
	int pr(int u)const{return parent[0][u];}
};
int N,M;
int U[2<<17],V[2<<17];
vector<int>G[1<<17];
bool MST[2<<17];
int add[1<<17];
void dfs(int u,int p)
{
	for(int v:G[u])if(v!=p)
	{
		add[v]+=add[u];
		dfs(v,u);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M;
	UF uf(N);
	LCA lca(N);
	for(int i=0;i<M;i++)
	{
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
		if(uf.unite(U[i],V[i]))
		{
			MST[i]=true;
			lca.add_edge(U[i],V[i]);
			G[U[i]].push_back(V[i]);
			G[V[i]].push_back(U[i]);
		}
	}
	lca.build();
	for(int i=0;i<M;i++)if(!MST[i])
	{
		int w=lca.lca(U[i],V[i]);
		if(w==U[i]||w==V[i])
		{
			int u=w==U[i]?V[i]:U[i];
			add[0]++;
			add[u]++;
			int d=lca.depth[u]-lca.depth[w]-1;
			for(int k=0;k<lca.parent.size();k++)if(d>>k&1)u=lca.parent[k][u];
			add[u]--;
		}
		else
		{
			add[U[i]]++;
			add[V[i]]++;
		}
	}
	dfs(0,-1);
	for(int i=0;i<N;i++)cout<<(add[i]<M-(N-1)?'0':'1');
	cout<<endl;
}