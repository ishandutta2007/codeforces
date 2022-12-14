#include<bits/stdc++.h>
using namespace std;
int n,cr[555555],col[1111111],sum,x;
vector<int> g[1111111];
void dfs(int i,int c)
{
	col[i]=c;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (!col[to]) dfs(to,3-c);
	}
}
int main()
{
	scanf("%d",&n);
	if (n%2==0)
	{
		printf("First\n");
		fflush(stdout);
		for (int i=1;i<=2*n;i++)
		{
			printf("%d ",(i-1)%n+1);
		}
		printf("\n");
		fflush(stdout);
	}
	else
	{
		printf("Second\n");
		fflush(stdout);
		for (int i=1;i<=2*n;i++)
		{
			scanf("%d",&x);
			if (cr[x]) 
			{
				g[cr[x]].push_back(i);
				g[i].push_back(cr[x]);
			}
			cr[x]=i;
		}
		for (int i=1;i<=n;i++) 
		{
			g[i].push_back(i+n);
			g[i+n].push_back(i);
		}
		for (int i=1;i<=2*n;i++)
		{
			if (!col[i]) dfs(i,1);
		}
		for (int i=1;i<=2*n;i++)
		{
			if (col[i]==1) sum=(sum+i)%(2*n);
		}
		if (!sum)
		{
			for (int i=1;i<=2*n;i++)
			{
				if (col[i]==1) printf("%d ",i);
			}
			printf("\n");
			fflush(stdout);
		}
		else
		{
			for (int i=1;i<=2*n;i++)
			{
				if (col[i]==2) printf("%d ",i);
			}
			printf("\n");
			fflush(stdout);
		}
	}
	return 0;
}