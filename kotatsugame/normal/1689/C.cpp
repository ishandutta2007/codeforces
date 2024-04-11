#include<iostream>
#include<vector>
using namespace std;
int T,N;
vector<int>G[3<<17];
int dp[3<<17],ch[3<<17];
void dfs(int u,int p)
{
	ch[u]=1;
	vector<int>c;
	for(int v:G[u])if(v!=p)
	{
		c.push_back(v);
		dfs(v,u);
		ch[u]+=ch[v];
	}
	if(c.size()==0)
	{
		dp[u]=0;
	}
	else if(c.size()==1)
	{
		dp[u]=ch[c[0]]-1;
	}
	else
	{
		dp[u]=max(ch[c[0]]-1+dp[c[1]],ch[c[1]]-1+dp[c[0]]);
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
		dfs(0,-1);
		cout<<dp[0]<<"\n";
	}
}