#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
pair<int,int> arr[105];
int tmp[105],ans[105];
int main()
{
    int n,w;
    scanf("%d%d",&n,&w);
    for (int i=0;i<n;i++)
    {
    	scanf("%d",&arr[i].first);
    	arr[i].second=i;
	}
	sort(arr,arr+n);
	tmp[0]=(arr[0].first+1)/2;
	w-=tmp[0];
	for (int i=1;i<n;i++)
	{
		tmp[i]=max((arr[i].first+1)/2,tmp[i-1]);
		w-=tmp[i];
	}
	for (int i=n-1;i>=0 && w>0;i--)
	{
		int t=min(w,arr[i].first-tmp[i]);
		tmp[i]+=t;
		w-=t;
	}
	if (w!=0)
	{
		printf("-1");
		return 0;
	}
	for (int i=0;i<n;i++)
	ans[arr[i].second]=tmp[i];
	for (int i=0;i<n;i++)
	printf("%d ",ans[i]);
}