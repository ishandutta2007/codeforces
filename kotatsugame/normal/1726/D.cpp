#include<iostream>
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
vector<pair<int,int> >G[2<<17];
vector<int>pr;
bool dfs(int u,int p,int to)
{
	if(u==to)return true;
	for(pair<int,int>e:G[u])if(e.first!=p)
	{
		pr.push_back(e.second);
		if(dfs(e.first,u,to))return true;
		pr.pop_back();
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N,M;
		cin>>N>>M;
		for(int i=0;i<N;i++)G[i].clear();
		vector<pair<int,pair<int,int> > >Ei;
		vector<int>vs;
		UF uf(N);
		for(int i=0;i<M;i++)
		{
			int u,v;cin>>u>>v;u--,v--;
			if(uf.unite(u,v))
			{
				G[u].push_back(make_pair(v,i));
				G[v].push_back(make_pair(u,i));
			}
			else
			{
				Ei.push_back(make_pair(i,make_pair(u,v)));
				vs.push_back(u);
				vs.push_back(v);
			}
		}
		sort(vs.begin(),vs.end());
		vs.erase(unique(vs.begin(),vs.end()),vs.end());
		string ans(M,'0');
		for(int i=0;i<Ei.size();i++)ans[Ei[i].first]='1';
		if(Ei.size()==3&&vs.size()==3)
		{
			int U=Ei[0].second.first,V=Ei[0].second.second;
			pr.clear();
			dfs(U,-1,V);
			ans[Ei[0].first]='0';
			ans[pr[0]]='1';
		}
		cout<<ans<<"\n";
	}
}