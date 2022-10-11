#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int> arr[1000005];
int n,k,a[1000005],b[2000005];
bool check(int mid)
{
	int l=0,r=mid-1,sz=n+mid;
	for (int i=0;i<sz;i++)
	{
		if (r<0)
		b[i]=a[l++];
		else if (l>=n || a[l]>arr[r].first)
		b[i]=arr[r--].first;
		else
		b[i]=a[l++];
	}
	for (int i=0;i<sz;i+=k)
	{
		for (int j=i;j<min(sz,i+k);j++)
		{
			if (b[j]<i/k)
			return 0;
		}
	}
	return 1;
}
int main()
{
	int m;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for (int i=0;i<m;i++)
	{
		scanf("%d",&arr[i].first);
		arr[i].second=i;
	}
	sort(a,a+n);
	sort(arr,arr+m,greater<pair<int,int> >());
	int st=-1,en=m;
	while (st!=en)
	{
		int mid=(st+en+1)/2;
		if (check(mid))
		st=mid;
		else
		en=mid-1;
	}
	printf("%d\n",st);
	for (int i=0;i<st;i++)
	printf("%d ",arr[i].second+1);
}