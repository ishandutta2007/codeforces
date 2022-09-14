#include<iostream>
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
int T,N,M;
vector<pair<pair<int,int>,int> >E;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		E.clear();
		E.reserve(M);
		for(int i=0;i<M;i++)
		{
			int u,v,w;cin>>u>>v>>w;
			u--,v--;
			E.push_back(make_pair(make_pair(u,v),w));
		}
		int ans=0;
		for(int k=30;k--;)
		{
			UF uf(N);
			int cnt=N;
			for(pair<pair<int,int>,int>e:E)if(!(e.second>>k&1))
			{
				if(uf.unite(e.first.first,e.first.second))cnt--;
			}
			if(cnt==1)
			{
				vector<pair<pair<int,int>,int> >nE;
				for(pair<pair<int,int>,int>e:E)if(!(e.second>>k&1))
				{
					nE.push_back(e);
				}
				E=nE;
			}
			else ans|=1<<k;
		}
		cout<<ans<<"\n";
	}
}