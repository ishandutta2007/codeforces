#include <iostream>
using namespace std;
int p[1000005];
bool vis[1000005];
void dfs(int x)
{
	vis[x]=1;
	if (!vis[p[x]])
	dfs(p[x]);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&p[i]);
	int ans=n;
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		{
			dfs(i);
			ans--;
		}
	}
	if ((3*n-ans)%2==0)
	printf("Petr");
	else
	printf("Um_nik");
}