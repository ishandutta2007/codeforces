#include<bits/stdc++.h>
using namespace std;
int n,u,v,pa[111111];
vector<int> g[111111];
double x[111111],y[111111],sumx,sumy,subx[111111],suby[111111],f[111111],all[111111],ans;
void dfs(int i,int fa)
{
	pa[i]=fa;f[i]=1.00;
	subx[i]=x[i];suby[i]=y[i];
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
		subx[i]+=subx[to];suby[i]+=suby[to];
		f[i]+=f[to];
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);  
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&x[i],&y[i]);
		sumx+=x[i];sumy+=y[i];
	}
	dfs(1,0);
	for (int i=1;i<=n;i++)
	{
		if (pa[i])
		{
			ans+=f[i]*y[pa[i]]*subx[i]/sumx/sumy;
		}
		ans+=(n-f[i])*y[i]*(sumx-subx[i])/sumx/sumy;
	}
	printf("%.9lf\n",ans);
	return 0;
}