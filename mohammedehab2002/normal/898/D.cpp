#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int arr[200005];
bool del[200005];
deque<int> v;
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	sort(arr,arr+n);
	int r=0,ans=0;
	for (int i=0;i<n;i++)
	{
		if (del[i])
		continue;
		while (r<n && arr[r]<arr[i]+m)
		{
			if (!del[r])
			v.push_back(r);
			r++;
		}
		while (v.size()>=k)
		{
			del[v.back()]=1;
			v.pop_back();
			ans++;
		}
		if (!v.empty())
		v.pop_front();
	}
	printf("%d",ans);
}