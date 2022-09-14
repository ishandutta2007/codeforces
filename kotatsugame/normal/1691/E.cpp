#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
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
int T,N;
int col[1<<17],R[1<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		vector<pair<int,int> >A;
		A.reserve(2*N);
		for(int i=0;i<N;i++)
		{
			int l,r;
			cin>>col[i]>>l>>r;
			A.push_back(make_pair(l,~i));
			A.push_back(make_pair(r,i));
			R[i]=r;
		}
		set<int>S[2];
		int cnt=N;
		UF uf(N);
		sort(A.begin(),A.end());
		for(pair<int,int>p:A)
		{
			if(p.second<0)
			{
				int i=~p.second;
				S[col[i]].insert(i);
			}
			else
			{
				int i=p.second;
				S[col[i]].erase(i);
				if(!S[!col[i]].empty())
				{
					int mx=-1;
					for(int u:S[!col[i]])
					{
						cnt-=uf.unite(i,u);
						if(mx==-1||R[mx]<R[u]||R[mx]==R[u]&&mx<u)mx=u;
					}
					S[!col[i]].clear();
					S[!col[i]].insert(mx);
				}
			}
		}
		cout<<cnt<<"\n";
	}
}