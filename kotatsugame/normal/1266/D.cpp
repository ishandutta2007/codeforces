#include<cstdio>
#include<vector>
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
int N,M;
long long A[1<<17];
vector<pair<pair<int,int>,long long> >E;
int root[1<<17];
main()
{
	scanf("%d%d",&N,&M);
	UF uf(N);
	for(int i=0;i<M;i++)
	{
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		u--,v--;
		A[u]-=d;
		A[v]+=d;
		uf.unite(u,v);
	}
	int id=0;
	for(int i=0;i<N;i++)
	{
		if(uf.find(i)==i)root[i]=id++;
	}
	vector<vector<int> >V(id);
	for(int i=0;i<N;i++)V[root[uf.find(i)]].push_back(i);
	for(int i=0;i<id;i++)
	{
		vector<pair<int,long long> >pos,neg;
		for(int v:V[i])
		{
			if(A[v]>0)pos.push_back(make_pair(v,A[v]));
			else if(A[v]<0)neg.push_back(make_pair(v,A[v]));
		}
		int negi=0;
		for(pair<int,long long>p:pos)
		{
			long long now=p.second;
			while(now>0)
			{
				long long get=min(now,-neg[negi].second);
				now-=get;
				neg[negi].second+=get;
				E.push_back(make_pair(make_pair(neg[negi].first+1,p.first+1),get));
				if(neg[negi].second==0)negi++;
			}
		}
	}
	printf("%d\n",E.size());
	for(pair<pair<int,int>,long long>p:E)printf("%d %d %lld\n",p.first.first,p.first.second,p.second);
}