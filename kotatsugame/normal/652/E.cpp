#line 1 "a.cpp"
#include<cstdio>
using namespace std;
#line 1 "/home/kotatsugame/library/graph/TECC.cpp"
//Two Edge Connected Components require bridge
#line 1 "/home/kotatsugame/library/graph/bridge.cpp"
#include<vector>
#include<algorithm>
struct bridge{
	int n;
	vector<int>ord,low;
	vector<bool>art;
	vector<vector<int> >G;
	bridge(int n_=0):n(n_),ord(n_,-1),low(n_),art(n_,false),G(n_){}
	void add_edge(int u,int v)
	{
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bool operator[](int i)const{return art[i];}
	bool is_bridge(int a,int b)const
	{
		if(ord[a]>ord[b])swap(a,b);
		return ord[a]<low[b];
	}
	void dfs(int u,int p,int&k)
	{
		low[u]=ord[u]=k++;
		bool now=false;
		int pc=0;
		for(int v:G[u])
		{
			if(ord[v]==-1)
			{
				dfs(v,u,k);
				low[u]=min(low[u],low[v]);
				now=now||ord[u]<=low[v];
			}
			else if(v!=p||pc++)
			{
				low[u]=min(low[u],ord[v]);
			}
		}
		art[u]=now;
	}
	void build()
	{
		int k=0;
		for(int u=0;u<n;u++)if(ord[u]==-1)
		{
			int cnt=0;
			low[u]=ord[u]=k++;
			for(int v:G[u])if(ord[v]==-1)
			{
				dfs(v,u,k);
				cnt++;
			}
			if(cnt>=2)art[u]=true;
		}
	}
};
#line 3 "/home/kotatsugame/library/graph/TECC.cpp"
struct TECC:bridge{
	vector<int>comp;
	TECC(int n_=0):bridge(n_),comp(n_,-1){}
	int operator[](int i)const{return comp[i];}
	void dfs(int u,int p,int&k)
	{
		comp[u]=p==-1||is_bridge(p,u)?k++:comp[p];
		for(int v:G[u])if(comp[v]==-1)dfs(v,u,k);
	}
	int build()
	{
		bridge::build();
		int k=0;
		for(int u=0;u<n;u++)if(comp[u]==-1)dfs(u,-1,k);
		return k;
	}
	int build(vector<vector<int> >&H)
	{
		int k=build();
		H.assign(k,vector<int>());
		for(int u=0;u<n;u++)
		{
			for(int v:G[u])if(comp[u]!=comp[v])
			{
				H[comp[u]].push_back(comp[v]);
			}
		}
		return k;
	}
};
#line 4 "a.cpp"
int N,M;
bool ok[3<<17];
int U[3<<17],V[3<<17],Z[3<<17];
vector<vector<int> >G;
int S,T;
bool dfs(int u,int p)
{
	for(int v:G[u])if(v!=p)
	{
		if(dfs(v,u))ok[u]=true;
	}
	if(u==T)ok[u]=true;
	return ok[u];
}
main()
{
	scanf("%d%d",&N,&M);
	TECC P(N);
	for(int i=0;i<M;i++)
	{
		scanf("%d%d%d",&U[i],&V[i],&Z[i]);
		U[i]--,V[i]--;
		P.add_edge(U[i],V[i]);
	}
	scanf("%d%d",&S,&T);
	S--,T--;
	int K=P.build(G);
	S=P[S],T=P[T];
	dfs(S,-1);
	for(int i=0;i<M;i++)if(Z[i]&&ok[P[U[i]]]&&ok[P[V[i]]])
	{
		puts("YES");
		return 0;
	}
	puts("NO");
}