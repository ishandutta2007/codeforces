#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,k,i;cin>>n>>k;
		ll ans=0;
		for (i=1;i<=n;i++){cin>>a[i];a[i]+=i;ans+=a[i];}
		sort(a+1,a+n+1);
		for (i=n;i>n-k;i--) ans-=a[i];
		cout<<ans-1ll*(n-k)*(n-k+1)/2<<endl;
	}
}