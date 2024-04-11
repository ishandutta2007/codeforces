#line 1 "a.cpp"
#include<cstdio>
#include<vector>
using namespace std;
#line 1 "/home/kotatsugame/library/graph/SCC.cpp"
//Strongly Connected Components
#line 3 "/home/kotatsugame/library/graph/SCC.cpp"
struct SCC{
	int n;
	vector<int>comp,order;
	vector<bool>used;
	vector<vector<int> >G,RG;
	SCC(int _n=0):n(_n),comp(_n,-1),used(_n,false),G(_n),RG(_n){}
	void add_edge(int from,int to)
	{
		G[from].push_back(to);
		RG[to].push_back(from);
	}
	void copy(const vector<vector<int> >&H)
	{
		for(int i=0;i<H.size();i++)
		{
			for(int j=0;j<H[i].size();j++)
			{
				G[i].push_back(H[i][j]);
				RG[H[i][j]].push_back(i);
			}
		}
	}
	int operator[](int u)const{return comp[u];}
	void dfs(int u)
	{
		used[u]=true;
		for(int i=0;i<G[u].size();i++)if(!used[G[u][i]])dfs(G[u][i]);
		order.push_back(u);
	}
	void rdfs(int u,int cnt)
	{
		comp[u]=cnt;
		for(int i=0;i<RG[u].size();i++)if(comp[RG[u][i]]==-1)rdfs(RG[u][i],cnt);
	}
	int build()
	{
		for(int i=0;i<n;i++)if(!used[i])dfs(i);
		int cnt=0;
		for(int i=n-1;i>=0;i--)if(comp[order[i]]==-1)rdfs(order[i],cnt++);
		return cnt;
	}
	int build(vector<vector<int> >&H)
	{
		int ret=build();
		H.assign(ret,vector<int>());
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<G[i].size();j++)
			{
				if(comp[i]!=comp[G[i][j]])
					H[comp[i]].push_back(comp[G[i][j]]);
			}
		}
		return ret;
	}
};
#line 5 "a.cpp"
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
int N,M;
int U[2<<17],V[2<<17],L[2<<17];
vector<pair<int,int> >G[2<<17];
bool vis[2<<17];
long long g[2<<17];
long long dist[2<<17];
void dfs(int u,int id,long long d)
{
	dist[u]=d;
	vis[u]=true;
	for(pair<int,int>e:G[u])
	{
		int v=e.first;
		if(vis[v])
		{
			g[id]=gcd(g[id],d+e.second-dist[v]);
		}
		else
		{
			dfs(v,id,d+e.second);
		}
	}
}
main()
{
	scanf("%d%d",&N,&M);
	SCC P(N);
	for(int i=0;i<M;i++)
	{
		scanf("%d%d%d",&U[i],&V[i],&L[i]);
		U[i]--,V[i]--;
		P.add_edge(U[i],V[i]);
	}
	int K=P.build();
	for(int i=0;i<M;i++)
	{
		int u=P[U[i]],v=P[V[i]];
		if(u==v)G[U[i]].push_back(make_pair(V[i],L[i]));
	}
	for(int i=0;i<N;i++)if(!vis[i])
	{
		int id=P[i];
		dfs(i,id,0);
	}
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++)
	{
		int v,s,t;
		scanf("%d%d%d",&v,&s,&t);
		v--;
		long long ng=gcd(t,g[P[v]]);
		if(s%ng==0)puts("YES");
		else puts("NO");
	}
}