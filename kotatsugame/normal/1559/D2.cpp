#include<cstdio>
#include<set>
#include<map>
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
int N,M[2];
main()
{
	scanf("%d%d%d",&N,&M[0],&M[1]);
	vector<UF>uf(2,N);
	map<int,int>mp[2];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<M[i];j++)
		{
			int a,b;scanf("%d%d",&a,&b);
			uf[i].unite(a-1,b-1);
		}
		for(int j=0;j<N;j++)mp[i][uf[i].find(j)]=j;
	}
	vector<pair<int,int> >E;
	while(mp[0].size()>=2&&mp[1].size()>=2)
	{
		int u1=mp[0].begin()->second;
		int v1=(++mp[0].begin())->second;
		int u2=mp[1].begin()->second;
		int v2=(++mp[1].begin())->second;
		int x,y;
		if(!uf[1].same(u1,v1))
		{
			x=u1,y=v1;
		}
		else
		{
			if(uf[1].same(u1,u2))u2=v2;
			if(!uf[0].same(u1,u2))
			{
				x=u1,y=u2;
			}
			else
			{
				x=v1,y=u2;
			}
		}
		E.push_back(make_pair(x,y));
		mp[0].erase(uf[0].find(x));
		mp[0].erase(uf[0].find(y));
		mp[1].erase(uf[1].find(x));
		mp[1].erase(uf[1].find(y));
		uf[0].unite(x,y);
		uf[1].unite(x,y);
		mp[0][uf[0].find(x)]=x;
		mp[1][uf[1].find(x)]=x;
	}
	printf("%d\n",E.size());
	for(pair<int,int>e:E)printf("%d %d\n",e.first+1,e.second+1);
}