#include <iostream>
#include <algorithm>
using namespace std;
int n,ans[100005];
pair<int,int> arr[100005];
long long a,m,cum[100005];
bool check(int mn,int fcnt)
{
	long long ind=lower_bound(arr,arr+n,make_pair(mn,-1))-arr;
	ind=min(ind,(long long)n-fcnt);
	long long x=mn*ind-cum[ind]+a*fcnt-(cum[n]-cum[n-fcnt]);
	return (x<=m);
}
int main()
{
	long long cf,cm;
	scanf("%d%I64d%I64d%I64d%I64d",&n,&a,&cf,&cm,&m);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i].first),arr[i].second=i;
	sort(arr,arr+n);
	for (int i=1;i<=n;i++)
	cum[i]=arr[i-1].first+cum[i-1];
	int bf=0,bm=0;
	for (int i=0;i<=n;i++)
	{
		int st=0,en=a;
		while (st!=en)
		{
			int mid=(st+en+1)/2;
			if (check(mid,i))
			st=mid;
			else
			en=mid-1;
		}
		if (i*cf+st*cm>bf*cf+bm*cm && st)
		bf=i,bm=st;
	}
	for (int i=0;i<n;i++)
	arr[i].first=max(arr[i].first,bm);
	for (int i=n-bf;i<n;i++)
	arr[i].first=a;
	for (int i=0;i<n;i++)
	ans[arr[i].second]=arr[i].first;
	printf("%I64d\n",bf*cf+bm*cm);
	for (int i=0;i<n;i++)
	printf("%d ",ans[i]);
}