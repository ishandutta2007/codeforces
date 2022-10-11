#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int arr[100005];
map<int,int> cnt;
int main()
{
	int n,x,k;
	scanf("%d%d%d",&n,&x,&k);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	sort(arr,arr+n);
	int l=0,r=0;
	long long ans=0;
	for (int i=0;i<n;i++)
	{
		l=max(l,i);
		while (l<n && arr[l]/x-(arr[i]-1)/x<k)
		l++;
		r=max(l,r);
		while (r<n && arr[r]/x-(arr[i]-1)/x<=k)
		r++;
		if ((k==1 && arr[i]%x==0) || (k==0 && arr[i]%x))
		ans+=cnt[arr[i]];
		ans+=r-l;
		cnt[arr[i]]++;
	}
	printf("%I64d",ans);
}