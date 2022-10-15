#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,T,ans,a[300000];
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>n;ans=0;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=n;i++) if (a[i]<a[i-1]) ans+=a[i-1]-a[i];
		cout<<ans<<endl;
	}
}