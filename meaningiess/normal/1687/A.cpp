#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200010],s[200010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,k,i;cin>>n>>k;
		for (i=1;i<=n;i++)
		{
			cin>>a[i];
			s[i]=s[i-1]+a[i];
		}
			ll ans=0;
		if (k<n)
		{
			for (i=1;i+k-1<=n;i++) ans=max(ans,s[i+k-1]-s[i-1]);
			cout<<ans+1ll*k*(k-1)/2<<endl;
		}
		else
		{
			cout<<s[n]+1ll*k*n-1ll*(n+1)*n/2<<endl;
		}
	}
}