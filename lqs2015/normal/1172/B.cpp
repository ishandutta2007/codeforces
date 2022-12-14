#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,x,y,jc[222222],sub[222222],ans;
vector<int> g[222222];
void Init()
{
	jc[0]=1;
	for (int i=1;i<=n;i++)
	{
		jc[i]=1ll*jc[i-1]*i%mod;
	}
}
void dfs(int i,int fa)
{
	int cnt=0;sub[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
		sub[i]+=sub[to];cnt++;
	}
	if (fa) cnt++;
	ans=1ll*ans*jc[cnt]%mod;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	Init();
	ans=1;
	dfs(1,0);
	printf("%d\n",1ll*ans*n%mod);
	return 0;
}