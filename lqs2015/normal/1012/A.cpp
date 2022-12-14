#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
long long n,a[222222],mn,mx,ans;
multiset<int> s;
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=2*n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	sort(a+1,a+2*n+1);
	mn=1e9;mx=0;
	for (long long i=1;i<=n;i++)
	{
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	ans=mx-mn;
	mn=1e9;mx=0;
	for (long long i=1;i<=n;i++)
	{
		mn=min(mn,a[i+n]);
		mx=max(mx,a[i+n]);
	}
	ans*=(mx-mn);
	mn=1e9;mx=0;
	for (int i=1;i<=2*n;i++)
	{
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		s.insert(a[i]);
	}
	for (int i=2;i<=n;i++)
	{
		s.erase(s.find(a[i-1]));
		s.insert(a[n+i-1]);
		ans=min(ans,(*s.rbegin()-*s.begin())*(mx-mn));
	}
	printf("%I64d\n",ans);
	return 0;
}