#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n,m,minnum[110],p,tmp,ans[110],tot;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) minnum[i]=1000000000;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p);
		for(int j=1;j<=p;j++)
		{
			scanf("%d",&tmp);
			minnum[i]=min(minnum[i],tmp);
		}
		if(minnum[i]<m) ans[++tot]=i;
	}
	printf("%d\n",tot);
	for(int i=1;i<tot;i++) printf("%d ",ans[i]);
	if(tot) printf("%d",ans[tot]);
	puts("");
	return 0;
}