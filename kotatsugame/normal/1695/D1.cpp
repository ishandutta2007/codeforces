#include<iostream>
#include<vector>
using namespace std;
int T,N;
vector<int>G[2<<17];
int dp[2<<17],zc[2<<17];
void dfs1(int u,int p)
{
	dp[u]=0;
	zc[u]=0;
	for(int i=0;i<G[u].size();i++)
	{
		if(G[u][i]==p)
		{
			if(i+1<G[u].size())swap(G[u][i],G[u][G[u].size()-1]);
			G[u].pop_back();
			break;
		}
	}
	for(int v:G[u])
	{
		dfs1(v,u);
		dp[u]+=dp[v];
		if(dp[v]==0)zc[u]++;
	}
	if(zc[u]>1)dp[u]+=zc[u]-1;
}
int ans;
void dfs2(int u)
{
	ans=min(ans,dp[u]+1);
	//cout<<"root : "<<u+1<<endl;
	//for(int i=0;i<N;i++)cout<<i+1<<" : (dp,zc)=("<<dp[i]<<","<<zc[i]<<")"<<endl;
	for(int v:G[u])
	{
		int dpu=dp[u],dpv=dp[v],zcu=zc[u],zcv=zc[v];
		dp[u]=dpu-(zcu>1?zcu-1:0)-dpv+(zcu-!dpv>1?zcu-!dpv-1:0);
		zc[u]=zcu-!dpv;
		dp[v]=dpv-(zcv>1?zcv-1:0)+dp[u]+(zcv+!dp[u]>1?zcv+!dp[u]-1:0);
		zc[v]=zcv+!dp[u];
		dfs2(v);
		dp[u]=dpu,dp[v]=dpv,zc[u]=zcu,zc[v]=zcv;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)G[i].clear();
		for(int i=1;i<N;i++)
		{
			int u,v;cin>>u>>v;
			u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(N==1)
		{
			cout<<"0\n";
			continue;
		}
		dfs1(0,-1);
		ans=N;
		dfs2(0);
		cout<<ans<<"\n";
	}
}