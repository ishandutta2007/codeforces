#include<bits/stdc++.h>
using namespace std;
int n,test,a[1111111],dfn[1111111],pa[1111111],cnt,cnr;
vector<int> g[1111111];
bool flag;
void dfs(int i,int fa)
{
	dfn[i]=++cnt;pa[i]=fa;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (!dfn[to])
		{
			dfs(to,i);
		}
		else
		{
			if (dfn[to]<=dfn[i] && !flag)
			{
				flag=1;
				cnr=0;int cr=i;
				while(cr!=to) 
				{
					cnr++;
					cr=pa[cr];
				}
				cnr++;cr=i;
				printf("%d\n",cnr);
				while(cr!=to)
				{
					printf("%d ",cr);
					cr=pa[cr];
				}
				printf("%d\n",cr);
			}
		}
	}
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) g[i].clear();
		flag=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if (a[i]==0 && !flag)
			{
				printf("1\n%d\n",i);
				flag=1;
			}
			g[i].push_back(i-a[i]);
		}
		if (flag) continue;
		cnt=0;
		for (int i=1;i<=n;i++) 
		{
			dfn[i]=pa[i]=0;
		}
		dfs(1,0);
	}
	return 0;
}