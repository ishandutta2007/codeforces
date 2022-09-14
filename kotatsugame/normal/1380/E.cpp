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
int N,M;
int fst[2<<17];
int u[2<<17],v[2<<17];
int L[2<<17],R[2<<17];
int cnt[2<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&fst[i]);
	}
	for(int i=1;i<M;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
	}
	for(int i=0;i<N-1;i++)
	{
		L[i]=-1;
		R[i]=M-1;
	}
	for(int tm=0;tm<40;tm++)
	{
		vector<vector<int> >check(M);
		for(int i=0;i<N-1;i++)
		{
			int mid=(L[i]+R[i])/2;
			check[mid].push_back(i);
		}
		UF uf(M+1);
		for(int i=0;i<M;i++)
		{
			if(i)uf.unite(u[i],v[i]);
			for(int id:check[i])
			{
				if(uf.find(fst[id])==uf.find(fst[id+1]))R[id]=i;
				else L[id]=i;
			}
		}
	}
	for(int i=0;i<N-1;i++)cnt[R[i]]++;
	int now=N-1;
	for(int i=0;i<M;i++)
	{
		now-=cnt[i];
		printf("%d\n",now);
	}
}