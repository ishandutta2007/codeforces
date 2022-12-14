#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
bool used[222222];
int n,ans,x;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (!used[x])
		{
			ans++;
			used[i]=1;
		}
		else
		{
			used[x]=0;
			used[i]=1;
		}
	}
	printf("%d\n",ans);
	return 0;
}