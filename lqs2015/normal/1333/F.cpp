#include<bits/stdc++.h>
using namespace std;
int n,prime[555555],cnt,mn[555555],ans[555555],cf[555555],ps;
bool f[555555];
void Init()
{
	for (int i=2;i<=n;i++)
	{
		if (!f[i])
		{
			prime[++cnt]=i;
		}
		for (int j=1;j<=cnt && i*prime[j]<=n;j++)
		{
			f[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
	mn[1]=1;
	for (int i=cnt;i>=1;i--)
	{
		for (int j=prime[i];j<=n;j+=prime[i])
		{
			mn[j]=prime[i];
		}
	}
}
int main()
{
	scanf("%d",&n);
	Init();
	for (int i=1;i<=n;i++)
	{
		cf[i/mn[i]]++;
	}
	for (int i=1;i<=n;i++) cf[i]+=cf[i-1];
	ps=1;
	for (int i=2;i<=n;i++)
	{
		while(ps<=n && cf[ps]<i) ps++;
		printf("%d ",ps);
	}
	printf("\n");
	return 0;
}