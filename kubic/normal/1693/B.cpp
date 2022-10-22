#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
#define pb push_back
int T,n,L[N],R[N],dp1[N],dp2[N];vector<int> e[N];
void dfs(int u)
{
	dp1[u]=dp2[u]=0;
	for(auto v:e[u])
	{
		dfs(v);dp1[u]+=dp1[v];
		dp2[u]=min(dp2[u]+dp2[v],R[u]);
	}if(dp2[u]<L[u]) ++dp1[u],dp2[u]=R[u];
}
void slv()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) e[i].clear();
	for(int i=2,f;i<=n;++i) scanf("%d",&f),e[f].pb(i);
	for(int i=1;i<=n;++i) scanf("%d %d",&L[i],&R[i]);
	dfs(1);printf("%d\n",dp1[1]);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}