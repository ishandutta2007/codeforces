#line 1 "a.cpp"
#include<cstdio>
#include<algorithm>
using namespace std;
#line 1 "/home/kotatsugame/library/datastructure/UF.cpp"
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
#line 5 "a.cpp"
int T,N,M,K;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&N,&M,&K);
		int mx=0;
		int cnt=N;
		UF uf(N);
		vector<pair<int,pair<int,int> > >E;
		for(int i=0;i<M;i++)
		{
			int u,v,s;scanf("%d%d%d",&u,&v,&s);
			u--,v--;
			if(s<=K)
			{
				mx=max(mx,s);
				cnt-=uf.unite(u,v);
			}
			else
			{
				E.push_back(make_pair(s-K,make_pair(u,v)));
			}
		}
		sort(E.begin(),E.end());
		if(cnt==1)
		{
			int ans=K-mx;
			if(!E.empty())ans=min(ans,E[0].first);
			printf("%d\n",ans);
			continue;
		}
		long long ans=0;
		for(int i=0;i<E.size();i++)if(uf.unite(E[i].second.first,E[i].second.second))
		{
			ans+=E[i].first;
		}
		printf("%lld\n",ans);
	}
}