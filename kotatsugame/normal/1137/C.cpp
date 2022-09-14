#line 1 "a.cpp"
#include<cstdio>
#include<vector>
#include<algorithm>
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
#line 7 "a.cpp"
int N,M,D,K;
vector<int>G[1<<17];
long long S[1<<17];
SCC P;
vector<int>vs[1<<17];
long long dist[1<<17];
int add[1<<17][50],cnt[1<<17][50];
main()
{
	scanf("%d%d%d",&N,&M,&D);
	P=SCC(N);
	for(int i=0;i<M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
		P.add_edge(u,v);
	}
	for(int i=0;i<N;i++)
	{
		scanf("\n");
		for(int j=0;j<D;j++)
		{
			char c;scanf("%c",&c);
			if(c=='1')S[i]|=1LL<<j;
		}
	}
	int K=P.build();
	for(int i=0;i<N;i++)vs[P[i]].push_back(i);
	const long long msk=(1LL<<D)-1;
	for(int k=K;k--;)
	{
		dist[vs[k][0]]=1;
		queue<int>Q;
		Q.push(vs[k][0]);
		while(!Q.empty())
		{
			int u=Q.front();Q.pop();
			for(int v:G[u])
			{
				if(k==P[v])
				{
					long long nxt=dist[u]<<1&msk|dist[u]>>D-1;
					if(nxt&~dist[v])
					{
						dist[v]|=nxt;
						Q.push(v);
					}
				}
			}
		}
		for(int u:vs[k])for(int v:G[u])if(k!=P[v])
		{
			vector<int>ret(D);
			for(int d2=0;d2<D;d2++)
			{
				int nd=(d2+1)%D;
				for(int d3=0;d3<D;d3++)if(dist[v]>>d3&1)
				{
					int d4=(nd-d3+D)%D;
					ret[d2]=max(ret[d2],cnt[P[v]][d4]+add[P[v]][d4]);
				}
			}
			for(int d=0;d<D;d++)
			{
				for(int d2=0;d2<D;d2++)if(dist[u]>>d2&1)
				{
					add[k][d]=max(add[k][d],ret[(d+d2)%D]);
				}
			}
		}
		for(int d=0;d<D;d++)
		{
			for(int u:vs[k])
			{
				long long now=dist[u];
				if(now&S[u])cnt[k][d]++;
				dist[u]=dist[u]<<1&msk|dist[u]>>D-1;
			}
		}
	}
	printf("%d\n",add[P[0]][0]+cnt[P[0]][0]);
}