#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int ans;
int a[1<<17];
int sum[1<<17];
main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	a[n+1]=m;
	for(int i=0;i<n+1;i++)
	{
		if(i%2==0)ans+=a[i+1]-a[i];
		sum[i+1]=ans;
	}
	for(int i=1;i<n+1;i++)
	{
		if(a[i]-1>a[i-1])
		{
			if(i%2==0)
			{
				int now=sum[i]+(m-a[i]-(sum[n+1]-sum[i]))+1;
				ans=max(ans,now);
			}
			else
			{
				int now=sum[i]+(m-a[i]-(sum[n+1]-sum[i]))-1;
				ans=max(ans,now);
			}
		}
		if(a[i]+1<a[i+1])
		{
			if(i%2==0)
			{
				int now=sum[i]+(m-a[i]-(sum[n+1]-sum[i]))+1;
				ans=max(ans,now);
			}
			else
			{
				int now=sum[i]+(m-a[i]-(sum[n+1]-sum[i]))-1;
				ans=max(ans,now);
			}
		}
	}
	cout<<ans<<endl;
}