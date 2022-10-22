#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,ans=0;ll x,l=-1e16,r=1e16;
		cin>>n;cin>>x;
		for (i=1;i<=n;i++)
		{
			cin>>a[i];
			ll nl=a[i]-x,nr=a[i]+x;
			l=max(l,nl);r=min(r,nr);
			if (l>r)
			{
				ans++;l=nl;r=nr;
			}
		}
		cout<<ans<<endl;
	}
}