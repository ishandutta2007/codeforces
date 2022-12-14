#include<bits/stdc++.h>
using namespace std;
int test,nxt[555555],n,m,ans,x,y,used[555555];
void dfs(int i)
{
	if (used[i]==1) 
	{
		ans++;
		return;
	}
	if (used[i]) return;
	used[i]=1;
	if (nxt[i]) dfs(nxt[i]);
	used[i]=2;
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);ans=0;
		for (int i=1;i<=n;i++) nxt[i]=used[i]=0;
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			if (x!=y)
			{
				ans++;
				nxt[x]=y;
			} 
		}
		for (int i=1;i<=n;i++)
		{
			if (!used[i]) dfs(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}