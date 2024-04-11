#line 1 "a.cpp"
#include<cstdio>
#include<algorithm>
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
#line 6 "a.cpp"
int N,M;
long long ans[2<<17];
main()
{
	scanf("%d%d",&N,&M);
	vector<pair<int,pair<int,int> > >E(N-1+M);
	for(int i=1;i<N;i++)
	{
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		u--,v--;
		E[i-1]=make_pair(w,make_pair(~u,~v));
	}
	for(int i=0;i<M;i++)
	{
		int w;scanf("%d",&w);
		E[N-1+i]=make_pair(w,make_pair(i,0));
	}
	sort(E.begin(),E.end());
	long long all=0;
	UF uf(N);
	for(pair<int,pair<int,int> >p:E)
	{
		if(p.second.first>=0)ans[p.second.first]=all;
		else
		{
			int u=~p.second.first,v=~p.second.second;
			all+=(long long)uf.size(u)*uf.size(v);
			uf.unite(u,v);
		}
	}
	for(int i=0;i<M;i++)printf("%lld%c",ans[i],i+1==M?10:32);
}