#include<iostream>
#include<cstdio>
using namespace std;
int n,a[222222],cnt,pos,ans[222222],ccnt[222222];
bool used[222222],bus[222222];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (!used[a[i]]) cnt++;
		used[a[i]]=1;
		ccnt[a[i]]++;
	}
	printf("%d\n",n-cnt);
	pos=1;
	while(pos<=n && used[pos]) pos++;
	for (int i=1;i<=n;i++)
	{
		if (bus[a[i]])
		{
			ans[i]=pos;
			pos++;
			while(pos<=n && used[pos]) pos++;
			continue;
		}
		if (ccnt[a[i]]==1) 
		{
			ans[i]=a[i];
			bus[a[i]]=1;
			continue;
		}
		if (pos<a[i])
		{
			ans[i]=pos;
			pos++;
			while(pos<=n && used[pos]) pos++;
			ccnt[a[i]]--;
		}
		else
		{
			ans[i]=a[i];
			bus[a[i]]=1;
		}
	}
	for (int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
 }