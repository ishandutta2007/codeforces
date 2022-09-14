#line 1 "a.cpp"
#include<cstdio>
#include<vector>
#include<queue>
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
#line 6 "a.cpp"
int T;
int N,M;
bool W[4<<17];
int dp[4<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		vector<pair<int,int> >E(M);
		SCC P(N);
		for(int i=0;i<M;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			u--,v--;
			E[i]=make_pair(u,v);
			P.add_edge(u,v);
		}
		vector<vector<int> >G;
		int K=P.build(G);
		for(int i=0;i<K;i++)
		{
			W[i]=false;
			dp[i]=0;
		}
		for(pair<int,int>e:E)
		{
			int u=e.first,v=e.second;
			if(P[u]==P[v])W[P[u]]=true;
		}
		dp[P[0]]=1;
		for(int u=0;u<K;u++)
		{
			if(dp[u]>0&&W[u])dp[u]=-1;
			if(dp[u]!=0)
			{
				for(int v:G[u])
				{
					if(dp[u]==-1)dp[v]=-1;
					else if(dp[v]!=-1)
					{
						dp[v]+=dp[u];
						if(dp[v]>=2)dp[v]=2;
					}
				}
			}
		}
		for(int i=0;i<N;i++)printf("%d%c",dp[P[i]],i+1==N?10:32);
	}
}