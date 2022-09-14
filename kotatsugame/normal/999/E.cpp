#line 1 "a.cpp"
#include<cstdio>
#include<queue>
using namespace std;
#line 1 "/home/kotatsugame/library/graph/SCC.cpp"
//Strongly Connected Components
#include<vector>
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
vector<vector<int> >G;
bool vis[5050];
int deg[5050];
main()
{
	int N,M,S;
	scanf("%d%d%d",&N,&M,&S);
	S--;
	SCC P(N);
	for(int i=0;i<M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		P.add_edge(u,v);
	}
	int K=P.build(G);
	vis[P[S]]=true;
	queue<int>Q;
	Q.push(P[S]);
	while(!Q.empty())
	{
		int u=Q.front();Q.pop();
		for(int v:G[u])if(!vis[v])
		{
			vis[v]=true;
			Q.push(v);
		}
	}
	for(int i=0;i<K;i++)
	{
		for(int v:G[i])deg[v]++;
	}
	int ans=0;
	for(int i=0;i<K;i++)if(!vis[i]&&!deg[i])ans++;
	printf("%d\n",ans);
}