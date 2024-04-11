#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
struct LCA{
	int N;
	vector<vector<int> >G,parent;
	vector<int>depth;
	LCA(int N_=0):N(N_),G(N_),depth(N_)
	{
		int lg=0;
		while((1<<lg)+1<N_)lg++;
		parent.assign(lg+1,vector<int>(N_));
	}
	void add_edge(int u,int v)
	{
		G[u].push_back(v);
		G[v].push_back(u);
	}
	void dfs(int u,int p,int d)
	{
		depth[u]=d;
		parent[0][u]=p;
		for(int v:G[u])if(v!=p)dfs(v,u,d+1);
	}
	void build(int root=0)
	{
		dfs(root,-1,0);
		for(int k=1;k<parent.size();k++)
		{
			for(int i=0;i<N;i++)
			{
				if(parent[k-1][i]==-1)parent[k][i]=-1;
				else parent[k][i]=parent[k-1][parent[k-1][i]];
			}
		}
	}
	int lca(int u,int v)
	{
		if(depth[u]>depth[v])swap(u,v);
		for(int k=0;k<parent.size();k++)if(depth[v]-depth[u]>>k&1)v=parent[k][v];
		if(u==v)return u;
		for(int k=parent.size();k--;)if(parent[k][u]!=parent[k][v])
		{
			u=parent[k][u];
			v=parent[k][v];
		}
		return parent[0][u];
	}
	int dist(int u,int v)
	{
		int w=lca(u,v);
		return depth[u]+depth[v]-2*depth[w];
	}
};
int N;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	LCA P(N);
	for(int i=1;i<N;i++)
	{
		int u,v;cin>>u>>v;
		P.add_edge(u-1,v-1);
	}
	P.build();
	int Q;cin>>Q;
	for(;Q--;)
	{
		int k;cin>>k;
		vector<int>U(k),vis(k,0);
		for(int i=0;i<k;i++)cin>>U[i],U[i]--;
		sort(U.begin(),U.end(),[&P](int l,int r){return P.depth[l]>P.depth[r];});
		int x=-1,y=U[0];
		vis[0]=1;
		for(int i=1;i<k;i++)
		{
			if(P.lca(y,U[i])==U[i])
			{
				x=y;
				y=U[i];
				vis[i]=1;
			}
		}
		bool ok=true;
		bool fst=true;
		for(int i=k-1;i>=0;i--)if(vis[i]==0)
		{
			if(fst)
			{
				fst=false;
				if(x!=-1)
				{
					if(P.depth[P.lca(x,U[i])]>P.depth[y])
					{
						ok=false;
						break;
					}
				}
				y=U[i];
			}
			else
			{
				if(P.lca(y,U[i])==y)
				{
					y=U[i];
				}
				else
				{
					ok=false;
					break;
				}
			}
		}
		cout<<(ok?"YES\n":"NO\n");
	}
}