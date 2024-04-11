#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
int A[2<<17];
vector<vector<int> >G;
vector<vector<int> >vs;
int dep[2<<17];
void dfs(int u,int p,int d)
{
	if(vs.size()==d)vs.push_back(vector<int>());
	vs[d].push_back(u);
	dep[u]=d;
	for(int v:G[u])if(v!=p)dfs(v,u,d+1);
}
long long dp[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		G.clear();
		G.assign(N,vector<int>());
		for(int i=1;i<N;i++)
		{
			int v;scanf("%d",&v);v--;G[v].push_back(i);
		}
		for(int i=1;i<N;i++)scanf("%d",&A[i]);
		vs.clear();
		dfs(0,-1,0);
		for(int d=vs.size()-1;d>=0;d--)
		{
			for(int u:vs[d])
			{
				dp[u]=0;
				for(int v:G[u])if(dep[v]==dep[u]+1)dp[u]=max(dp[u],dp[v]);
			}
			vector<pair<int,int> >Adp(vs[d].size());
			for(int i=0;i<vs[d].size();i++)
			{
				Adp[i]=make_pair(A[vs[d][i]],vs[d][i]);
			}
			sort(Adp.begin(),Adp.end());
			vector<long long>Lmax(vs[d].size()+1,(long long)-1e18),
							Rmax(vs[d].size()+1,(long long)-1e18);
			for(int i=0;i<vs[d].size();i++)
			{
				Lmax[i+1]=max(Lmax[i],dp[Adp[i].second]-Adp[i].first);
			}
			for(int i=vs[d].size();i--;)
			{
				Rmax[i]=max(Rmax[i+1],dp[Adp[i].second]+Adp[i].first);
			}
			int l=0,r=0;
			for(int i=0;i<vs[d].size();i++)
			{
				int u=Adp[i].second;
				dp[u]+=max(Adp.back().first-A[u],A[u]-Adp[0].first);
				while(l<vs[d].size()&&A[u]>=Adp[l].first)l++;
				while(r<vs[d].size()&&A[u]>Adp[r].first)r++;
				long long other=max(Lmax[l]+A[u],Rmax[r]-A[u]);
				dp[u]=max(dp[u],other);
			}
		}
		printf("%lld\n",dp[0]);
	}
}