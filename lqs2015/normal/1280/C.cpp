#include<bits/stdc++.h>
using namespace std;
int n,test,sub[222222],x,y,z;
long long mn,mx;
vector<pair<int,int> > g[222222];
void dfs(int i,int fa,int vl)
{
	sub[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first,val=g[i][j].second;
		if (to==fa) continue;
		dfs(to,i,val);
		sub[i]+=sub[to];
	}
	if (fa)
	{
		mx+=(1ll*vl*min(sub[i],2*n-sub[i]));
		if (sub[i]&1) mn+=vl;
	}
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=2*n;i++) g[i].clear();
		for (int i=1;i<2*n;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			g[x].push_back(make_pair(y,z));
			g[y].push_back(make_pair(x,z));
		}
		mn=mx=0;
		dfs(1,0,0);
		printf("%lld %lld\n",mn,mx);
	}
	return 0;
}