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
const int mod=1e9+7;
main()
{
	scanf("%d%d",&N,&M);
	vector<int>ans;
	UF uf(M+1);
	int as=1;
	for(int i=0;i<N;i++)
	{
		int k;scanf("%d",&k);
		int x,y=0;
		if(k==1)
		{
			scanf("%d",&x);
		}
		else
		{
			scanf("%d%d",&x,&y);
		}
		if(uf.unite(x,y))
		{
			ans.push_back(i);
			as=as*2%mod;
		}
	}
	printf("%d %d\n",as,(int)ans.size());
	for(int i=0;i<ans.size();i++)printf("%d%c",ans[i]+1,i+1==ans.size()?10:32);
}