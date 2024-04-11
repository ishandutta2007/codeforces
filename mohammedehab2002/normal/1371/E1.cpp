#include <bits/stdc++.h>
using namespace std;
int a[2005];
int main()
{
	int n,p;
	scanf("%d%d",&n,&p);
	for (int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a,a+n);
	vector<int> v;
	for (int x=a[n-1]-n+1;x<a[n-1];x++)
	{
		int cnt=1;
		for (int i=n-1;i>=0;i--)
		cnt=(cnt*(i+1-max(a[i]-x,0)))%p;
		if (cnt)
		v.push_back(x);
	}
	printf("%d\n",v.size());
	for (int i:v)
	printf("%d ",i);
}