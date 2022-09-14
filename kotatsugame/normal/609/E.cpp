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
vector<pair<int,pair<int,int> > >Es;
int A[2<<17],B[2<<17],C[2<<17];
int L[2<<17],R[2<<17],mid[2<<17];
main()
{
	scanf("%d%d",&N,&M);
	Es.resize(M);
	for(int i=0;i<M;i++)
	{
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		a--,b--;
		A[i]=a;B[i]=b;C[i]=c;
		Es[i]=make_pair(c,make_pair(a,b));
		L[i]=-1;R[i]=M-1;
	}
	sort(Es.begin(),Es.end());
	UF uf(N);
	long long all=0;
	for(pair<int,pair<int,int> >p:Es)
	{
		int a=p.second.first,b=p.second.second;
		if(uf.unite(a,b))all+=p.first;
	}
	for(int tm=0;tm<20;tm++)
	{
		vector<vector<int> >ids(M);
		for(int i=0;i<M;i++)
		{
			mid[i]=(L[i]+R[i])/2;
			ids[mid[i]].push_back(i);
		}
		UF uf(N);
		for(int i=0;i<M;i++)
		{
			uf.unite(Es[i].second.first,Es[i].second.second);
			for(int id:ids[i])
			{
				if(uf.same(A[id],B[id]))R[id]=mid[id];
				else L[id]=mid[id];
			}
		}
	}
	for(int i=0;i<M;i++)printf("%lld\n",all+C[i]-Es[R[i]].first);
}