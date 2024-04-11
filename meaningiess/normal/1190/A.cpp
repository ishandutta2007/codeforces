#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
ll a[N];
int main()
{
	ll n,k;int m,i,ans=0;cin>>n;cin>>m>>k;
	for (i=1;i<=m;i++) cin>>a[i];a[m+1]=1e18+100;
	for (i=1;i<=m;)
	{
		ll t=a[i]-i;
		int p=upper_bound(a+1,a+m+2,min(n,a[i]-t%k+k-1))-a-1;ans++;i=p+1;
	}
	cout<<ans;
}