#include<cstdio>
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
int N,M1,M2;
main()
{
	scanf("%d%d%d",&N,&M1,&M2);
	UF uf1(N),uf2(N);
	for(int i=0;i<M1;i++)
	{
		int a,b;scanf("%d%d",&a,&b);
		uf1.unite(a-1,b-1);
	}
	for(int i=0;i<M2;i++)
	{
		int a,b;scanf("%d%d",&a,&b);
		uf2.unite(a-1,b-1);
	}
	vector<pair<int,int> >E;
	for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)if(!uf1.same(i,j)&&!uf2.same(i,j))
	{
		uf1.unite(i,j);
		uf2.unite(i,j);
		E.push_back(make_pair(i,j));
	}
	printf("%d\n",E.size());
	for(pair<int,int>e:E)printf("%d %d\n",e.first+1,e.second+1);
}