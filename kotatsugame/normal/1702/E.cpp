#include<iostream>
#include<vector>
using namespace std;
int T,N;
vector<int>G[2<<17];
int col[2<<17];
bool dfs(int u,int c)
{
	col[u]=c;
	for(int v:G[u])
	{
		if(col[v]!=0)
		{
			if(col[v]==c)return false;
		}
		else if(!dfs(v,3-c))return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=1;i<=N;i++)G[i].clear(),col[i]=0;
		for(int i=0;i<N;i++)
		{
			int a,b;cin>>a>>b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		bool ok=true;
		for(int i=1;i<=N;i++)if(G[i].size()!=2)ok=false;
		if(ok)
		{
			for(int i=1;i<=N;i++)if(col[i]==0)
			{
				if(!dfs(i,1))
				{
					ok=false;
					break;
				}
			}
		}
		cout<<(ok?"YES\n":"NO\n");
	}
}