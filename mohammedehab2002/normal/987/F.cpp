#include <iostream>
using namespace std;
bool b[(1<<22)],vis[(1<<22)];
int n,l;
void dfs(int mask)
{
	if (vis[mask])
	return;
	vis[mask]=1;
	if (b[mask])
	{
		b[mask]=0;
		dfs((~mask)&l);
	}
	for (int i=0;i<n;i++)
	{
		if (mask&(1<<i))
		dfs(mask^(1<<i));
	}
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	l=(1<<n)-1;
	while (m--)
	{
		int a;
		scanf("%d",&a);
		b[a]=1;
	}
	int ans=0;
	for (int i=0;i<=l;i++)
	{
		if (b[i])
		{
			ans++;
			dfs(i);
		}
	}
	printf("%d",ans);
}