#line 1 "a.cpp"
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
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
#line 7 "a.cpp"
int N,M;
vector<int>G[1000];
int dist(int st)
{
	vector<int>dist(N,1e9);
	dist[st]=0;
	queue<int>P;
	P.push(st);
	int lst;
	while(!P.empty())
	{
		int u=P.front();
		lst=u;
		P.pop();
		for(int v:G[u])if(dist[v]>dist[u]+1)
		{
			dist[v]=dist[u]+1;
			P.push(v);
		}
	}
	return dist[lst];
}
bool usd[1000];
main()
{
	scanf("%d%d",&N,&M);
	UF uf(N);
	for(int i=0;i<M;i++)
	{
		int x,y;scanf("%d%d",&x,&y);x--,y--;
		uf.unite(x,y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	vector<pair<int,int> >P;
	for(int i=0;i<N;i++)if(!usd[uf.find(i)])
	{
		usd[uf.find(i)]=true;
		vector<pair<int,int> >vs;
		for(int j=0;j<N;j++)if(uf.same(i,j))
		{
			int d=dist(j);
			vs.push_back(make_pair(d,j));
		}
		sort(vs.begin(),vs.end());
		P.push_back(vs[0]);
	}
	sort(P.begin(),P.end());
	vector<pair<int,int> >E;
	for(int i=0;i+1<P.size();i++)
	{
		int u=P[i].second,v=P.back().second;
		E.push_back(make_pair(u,v));
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int dir=0;
	for(int i=0;i<N;i++)dir=max(dir,dist(i));
	printf("%d\n",dir);
	for(pair<int,int>e:E)printf("%d %d\n",e.first+1,e.second+1);
}