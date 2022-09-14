#include<cstdio>
#include<vector>
#include<algorithm>
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
int N,M;
vector<int>G[1<<17];
bool used[1<<17];
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	UF uf(N);
	int ans=N-1;
	if(N<=1000)
	{
		for(int i=0;i<N;i++)
		{
			int pre=0;
			sort(G[i].begin(),G[i].end());
			for(int v:G[i])
			{
				for(;pre<v;pre++)
				{
					ans-=uf.unite(i,pre);
				}
				pre++;
			}
			for(;pre<N;pre++)
			{
				ans-=uf.unite(i,pre);
			}
		}
	}
	else
	{
		int id=0;
		for(int i=1;i<N;i++)
		{
			if(G[id].size()>G[i].size())id=i;
		}
		for(int i=0;i<N;i++)used[i]=true;
		sort(G[id].begin(),G[id].end());
		int pre=0;
		for(int v:G[id])
		{
			for(;pre<v;pre++)
			{
				ans-=uf.unite(id,pre);
				used[pre]=false;
			}
			pre++;
		}
		for(;pre<N;pre++)
		{
			ans-=uf.unite(id,pre);
			used[pre]=false;
		}
		for(int i=0;i<N;i++)
		{
			if(!used[i])continue;
			sort(G[i].begin(),G[i].end());
			int pre=0;
			for(int v:G[i])
			{
				for(;pre<v;pre++)
				{
					ans-=uf.unite(i,pre);
				}
				pre++;
			}
			for(;pre<N;pre++)
			{
				ans-=uf.unite(i,pre);
			}
		}
	}
	printf("%d\n",ans);
}