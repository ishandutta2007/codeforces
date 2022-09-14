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
main()
{
	scanf("%d%d",&N,&M);
	vector<pair<int,pair<int,int> > >Es(M);
	for(int i=0;i<M;i++)
	{
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		u--,v--;
		Es[i]=make_pair(w,make_pair(u,v));
	}
	sort(Es.begin(),Es.end());
	int ans=0;
	UF uf(N);
	for(int i=0;i<M;)
	{
		int cnt=0;
		int j=i;
		while(j<M&&Es[i].first==Es[j].first)
		{
			if(!uf.same(Es[j].second.first,Es[j].second.second))cnt++;
			j++;
		}
		while(i<j)
		{
			if(uf.unite(Es[i].second.first,Es[i].second.second))cnt--;
			i++;
		}
		ans+=cnt;
	}
	printf("%d\n",ans);
}