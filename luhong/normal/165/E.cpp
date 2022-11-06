#include<iostream>
#include<cstdio>
using namespace std;
int id[5010000],used[5010000],a[1010000];
int ans[1010000];
int Ans[5010000];
void dfs(int x,int k)
{
	if(used[x])return;
	used[x]=1;
	if(id[x])ans[id[x]]=k,dfs(((1<<22)-1)^a[id[x]],id[x]);
	for(int i=0;i<22;i++)
	{
		if((x>>i)&1)dfs(x^(1<<i),k);
	}
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),id[a[i]]=i;
	for(int i=1;i<=n;i++)
	{
		if(!used[a[i]])
		{
			dfs(((1<<22)-1)^a[i],i);
		}
	}
	for(int i=1;i<=n;i++)if(ans[i])Ans[a[i]]=ans[i];
	for(int i=1;i<=n;i++)if(!Ans[a[i]])printf("-1 ");else printf("%d ",a[Ans[a[i]]]);
	return 0;
}