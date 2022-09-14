#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int T,N;
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
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		LCA P(N);
		for(int i=1;i<N;i++)
		{
			int u,v;cin>>u>>v;u--,v--;
			P.add_edge(u,v);
		}
		P.build();
		vector<pair<int,int> >rt(N);
		{
			for(int i=0;i<N;i++)rt[i]=make_pair(P.depth[i],i);
		}
		sort(rt.begin(),rt.end());
		vector<int>ans(N+1,1e9);
		int l=-1,r=-1,dirm=-1;
		for(int d=N;d>=1;d--)
		{
			while(!rt.empty()&&rt.back().first>d)
			{
				int u=rt.back().second;
				rt.pop_back();
				if(dirm<0)
				{
					dirm=0;
					l=r=u;
				}
				else
				{
					if(dirm<P.dist(l,u))
					{
						dirm=P.dist(l,u);
						r=u;
					}
					else if(dirm<P.dist(r,u))
					{
						dirm=P.dist(r,u);
						l=u;
					}
				}
			}
			if(dirm<0)ans[N]=d;
			else
			{
				int need=d-(dirm+1)/2;
				if(need>0)ans[need]=d;
			}
		}
		for(int i=N;--i;)ans[i]=min(ans[i],ans[i+1]);
		for(int i=1;i<=N;i++)cout<<ans[i]<<(i==N?"\n":" ");
	}
}