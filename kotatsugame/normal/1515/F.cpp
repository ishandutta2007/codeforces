#line 1 "a.cpp"
#include<cstdio>
#include<vector>
#include<algorithm>
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
int pr[3<<17],sz[3<<17];
long long A[3<<17];
int N,M,X;
int find(int u){return pr[u]==u?u:(pr[u]=find(pr[u]));}
bool same(int u,int v){return find(u)==find(v);}
int unite(int u,int v)
{
	u=find(u);
	v=find(v);
	if(sz[u]<sz[v])swap(u,v);
	pr[v]=u;
	sz[u]+=sz[v];
	return u;
}
vector<pair<int,int> >G[3<<17];
vector<int>ans;
void dfs(int u,int p)
{
	for(pair<int,int>e:G[u])
	{
		int v=e.first;
		if(v==p)continue;
		if(!same(u,v))
		{
			long long T=A[find(u)]+A[find(v)];
			if(T>=X)
			{
				T-=X;
				A[unite(u,v)]=T;
				ans.push_back(e.second);
			}
		}
		dfs(v,u);
		if(!same(u,v))
		{
			long long T=A[find(u)]+A[find(v)];
			if(T>=X)
			{
				T-=X;
				A[unite(u,v)]=T;
				ans.push_back(e.second);
			}
		}
	}
}
main()
{
	scanf("%d%d%d",&N,&M,&X);
	for(int i=0;i<N;i++)
	{
		scanf("%lld",&A[i]);
	}
	UF uf(N);
	for(int i=0;i<M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		if(uf.unite(u,v))
		{
			G[u].push_back(make_pair(v,i));
			G[v].push_back(make_pair(u,i));
		}
	}
	for(int i=0;i<N;i++)
	{
		pr[i]=i;
		sz[i]=1;
	}
	dfs(0,-1);
	dfs(0,-1);
	if(ans.size()<N-1)puts("NO");
	else
	{
		puts("YES");
		for(int id:ans)printf("%d\n",id+1);
	}
}