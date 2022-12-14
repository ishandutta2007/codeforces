#include<iostream>
#include<cstdio>
using namespace std;
int p[222222],b[222222];
int n,ans,cnt,cntt;
bool used[222222],f;
void dfs(int i)
{
	used[i]=1;
	if (!used[p[i]]) dfs(p[i]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		if (b[i]) cntt++;
	}
	if (cntt%2==0) ans++;
	for (int i=1;i<=n;i++)
	{
		if (!used[i])
		{
			dfs(i);
			cnt++;
		}
	}
	if (cnt==1) cnt=0;
	printf("%d\n",ans+cnt);
	return 0;
 }