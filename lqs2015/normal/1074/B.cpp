#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,mn,mni;
vector<int> g[1111];
bool a[1111],b[1111];
void dfs(int i,int fa,int dep)
{
	if (a[i]) 
	{
		if (dep<mn)
		{
			mn=dep;
			mni=i;
		}
	}
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i,dep+1);
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);  
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%d",&x);
		for (int i=1;i<=x;i++)
		{
			scanf("%d",&y);
			a[y]=1;
		}
		scanf("%d",&x);
		for (int i=1;i<=x;i++)
		{
			scanf("%d",&y);
			b[y]=1;
		}
		printf("B %d\n",y);
		fflush(stdout);
		scanf("%d",&x);
		if (a[x])
		{
			printf("C %d\n",x);
			fflush(stdout);
			continue;
		}
		mn=1e9;mni=0;
		dfs(x,0,0);
		printf("A %d\n",mni);
		fflush(stdout);
		scanf("%d",&x);
		if (b[x])
		{
			printf("C %d\n",mni);
			fflush(stdout);
		}
		else
		{
			printf("C -1\n");
			fflush(stdout);
		}
	}
	return 0;
}