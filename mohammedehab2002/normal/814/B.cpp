#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
int n,arr[100005][2],ans[100005],ind[2];
bool check()
{
	set<int> s;
	for (int i=0;i<n;i++)
	s.insert(ans[i]);
	int mis[]={0,0};
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<2;x++)
		{
			if (ans[i]!=arr[i][x])
			mis[x]++;
		}
	}
	if (s.size()==n && mis[0]==1 && mis[1]==1)
	return 1;
	return 0;
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<2;i++)
	{
		for (int x=0;x<n;x++)
		scanf("%d",&arr[x][i]);
	}
	int cur=0;
	for (int i=0;i<n;i++)
	{
		if (arr[i][0]==arr[i][1])
		ans[i]=arr[i][0];
		else
		{
			ind[cur]=i;
			cur++;
		}
	}
	if (cur==1)
	{
		for (int i=1;i<=n;i++)
		{
			ans[ind[0]]=i;
			if (check())
			break;
		}
	}
	else
	{
		for (int i=0;i<2;i++)
		{
			for (int x=0;x<2;x++)
			{
				ans[ind[i]]=arr[ind[i]][0];
				ans[ind[x]]=arr[ind[x]][1];
				if (check())
				break;
			}
			if (check())
			break;
		}
	}
	for (int i=0;i<n;i++)
	printf("%d ",ans[i]);
}