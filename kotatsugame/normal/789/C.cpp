#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll a[1<<17],s[1<<17];int n;
main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<n;i++)
	{
		s[i-1]=abs(a[i-1]-a[i]);
	}
	ll ans=0;
	int f=0,l=0;
	ll sum=0;n--;
	for(;l<n;)
	{
		while(l<n&&sum>=0)
		{
			sum+=s[l]*((l-f)%2?-1:1);
			ans=max(ans,sum);l++;
		}
		ans=max(ans,sum);
		sum=0;f=l;
	}
	sum=0;f=1;l=1;
	for(;l<n;)
	{
		while(l<n&&sum>=0)
		{
			sum+=s[l]*((l-f)%2?-1:1);
			ans=max(ans,sum);l++;
		}
		ans=max(ans,sum);
		sum=0;f=l;
	}
	cout<<ans<<endl;
}