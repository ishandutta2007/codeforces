#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long n,m,x,y,num,ans,p;
vector<long long> g[1111111];
bool used[1111111],k[1111111];
void dfs(long long i)
{
	used[i]=1;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		if (!used[to]) dfs(to);
	}
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (long long i=1;i<=m;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		if (x==y) 
		{
			num++;
			k[x]=1;
		}
		else
		{
			g[x].push_back(y);
			g[y].push_back(x); 
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (g[i].size() || k[i]) 
		{
			dfs(i);
			break;
		}
	}
	for (long long i=1;i<=n;i++)
	{
		if (!used[i] && (g[i].size() || k[i])) 
		{
			printf("0\n");
			return 0;
		}
	}
	ans=num*(num-1)/2+num*(m-num);
	for (long long i=1;i<=n;i++)
	{
		p=(long long)g[i].size();
		ans=ans+p*(p-1)/2;
	}
	printf("%I64d\n",ans);
	return 0;
}