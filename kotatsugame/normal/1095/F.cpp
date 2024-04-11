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
int N,M;
long long A[2<<17];
main()
{
	scanf("%d%d",&N,&M);
	int mx=0;
	for(int i=0;i<N;i++)
	{
		scanf("%lld",&A[i]);
		if(A[mx]>A[i])mx=i;
	}
	vector<pair<long long,pair<int,int> > >E;
	E.reserve(N-1+M);
	for(int i=0;i<M;i++)
	{
		int x,y;
		long long w;
		scanf("%d%d%lld",&x,&y,&w);
		x--,y--;
		E.push_back(make_pair(w,make_pair(x,y)));
	}
	for(int i=0;i<N;i++)if(i!=mx)
	{
		E.push_back(make_pair(A[i]+A[mx],make_pair(i,mx)));
	}
	sort(E.begin(),E.end());
	UF uf(N);
	long long ans=0;
	for(pair<long long,pair<int,int> >e:E)
	{
		if(uf.unite(e.second.first,e.second.second))ans+=e.first;
	}
	printf("%lld\n",ans);
}