#include <iostream>
#include <algorithm>
using namespace std;
pair<pair<int,int>,int> arr[5005];
int dp[5005],par[5005];
void go(int pos)
{
	printf("%d ",arr[pos].second+1);
	if (par[pos]!=pos)
	go(par[pos]);
}
int main()
{
	int n,w,h;
	scanf("%d%d%d",&n,&w,&h);
	for (int i=0;i<n;i++)
	scanf("%d%d",&arr[i].first.first,&arr[i].first.second),arr[i].second=i,par[i]=i;
	sort(arr,arr+n);
	reverse(arr,arr+n);
	for (int i=0;i<n;i++)
	{
		dp[i]=1;
		for (int x=0;x<i;x++)
		{
			if (arr[i].first.first<arr[x].first.first && arr[i].first.second<arr[x].first.second && dp[i]<dp[x]+1)
			{
				dp[i]=dp[x]+1;
				par[i]=x;
			}
		}
	}
	int pos=-1;
	for (int i=0;i<n;i++)
	{
		if (arr[i].first.first>w && arr[i].first.second>h)
		{
			if (pos==-1)
			pos=i;
			else if (dp[i]>dp[pos])
			pos=i;
		}
	}
	if (pos==-1)
	printf("0");
	else
	{
		printf("%d\n",dp[pos]);
		go(pos);
	}
}