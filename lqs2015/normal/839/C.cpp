#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
double p[111111],dist[111111],ans;
vector<int> g[111111];
int n,x,y;
void dfs(int i,double d,int fa)
{
	double pp=g[i].size();
	if (fa) pp--;
	dist[i]=d;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		p[to]=p[i]/pp;
		dfs(to,d+1,i);
	}
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
	p[1]=1.00;
	dfs(1,0.00,0);
	for (int i=1;i<=n;i++)
	{
		if (g[i].size()==1) ans=ans+dist[i]*p[i];
	}
	printf("%.8lf\n",ans);
	return 0;
}