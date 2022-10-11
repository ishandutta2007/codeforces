#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int cum[100005];
int main()
{
	int n,m;
	scanf("%d",&n);
	int a[n];
	for (int i=0;i<n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&m);
	pair<int,int> arr[m];
	for (int i=0;i<m;i++)
	scanf("%d%d",&arr[i].first,&arr[i].second);
	cum[0]=a[0];
	for (int i=1;i<n;i++)
	cum[i]=cum[i-1]+a[i];
	int r=0,mom;
	for (int l=0;l<m;l++)
	{
		mom=max(arr[l].first,cum[r]);
		while (r<n && mom<=arr[l].second)
		{
			r++;
			mom=max(mom,cum[r]);
		}
		if (r==n)
		{
			printf("%d\n",mom);
			return 0;
		}
	}
	printf("-1");
}