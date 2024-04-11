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
int N,M,D;
main()
{
	scanf("%d%d%d",&N,&M,&D);
	vector<pair<int,int> >Es;
	vector<int>ONE;
	UF uf(N+1);
	for(int i=0;i<M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		if(u==1)ONE.push_back(v);
		else if(v==1)ONE.push_back(u);
		else
		{
			Es.push_back(make_pair(u,v));
			uf.unite(u,v);
		}
	}
	vector<int>L,R;
	for(int u:ONE)
	{
		if(uf.unite(1,u))L.push_back(u);
		else R.push_back(u);
	}
	if(L.size()<=D&&D<=L.size()+R.size())
	{
		puts("YES");
		UF ug(N+1);
		for(int u:L)
		{
			ug.unite(1,u);
			printf("%d %d\n",1,u);
		}
		for(int i=0;i<D-L.size();i++)
		{
			int u=R[i];
			ug.unite(1,u);
			printf("%d %d\n",1,u);
		}
		for(pair<int,int>e:Es)
		{
			if(ug.unite(e.first,e.second))printf("%d %d\n",e.first,e.second);
		}
	}
	else puts("NO");
}