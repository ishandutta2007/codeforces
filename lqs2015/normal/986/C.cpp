#include<iostream>
#include<vector>
using namespace std;
int n,m,a[4444444],ans;
bool used[8888888],f[4444444];
void dfs(int i)
{
	used[i]=1;
	if (i>=(1<<n)) 
	{
		if (!f[i-(1<<n)]) return;
		if (!used[i-(1<<n)]) dfs(i-(1<<n));
		return;
	}
	for (int j=0;j<n;j++)
	{
		if (i&(1<<j)) continue;
		if (!used[i|(1<<j)]) dfs(i|(1<<j));
	}
	if (!used[2*(1<<n)-1-i]) dfs(2*(1<<n)-1-i);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		f[a[i]]=1;
	}
	for (int i=1;i<=m;i++)
	{
		if (!used[(1<<n)+a[i]])
		{
			dfs((1<<n)+a[i]);
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}