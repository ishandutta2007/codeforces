#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i;cin>>n;
		for (i=1;i<=n;i++) cin>>a[i];
		if (n==3)
		{
			if (a[2]&1) puts("-1");
			else cout<<a[2]/2<<endl;
			continue;
		}
		int flg=0;
		for (i=2;i<n;i++) if (a[i]>1) flg=1;
		if (!flg) {puts("-1");continue;}
		ll ans=0;
		for (i=2;i<n;i++) ans+=(a[i]+1)/2;
		cout<<ans<<endl;
	}
}