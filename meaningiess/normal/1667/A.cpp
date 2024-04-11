#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5050];
int main()
{
	int n,i,j;ll ans=1e18;cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=n;i++)
	{
		ll nw=0,res=0;
		for (j=i-1;j;j--)
		{
			ll t=nw/a[j]+1;
			res+=t;nw=a[j]*t;
		}
		nw=0;
		for (j=i+1;j<=n;j++)
		{
			ll t=nw/a[j]+1;
			res+=t;nw=a[j]*t;
		}
		ans=min(ans,res);
	}
	cout<<ans;
}