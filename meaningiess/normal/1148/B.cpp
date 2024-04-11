#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200020],b[200020];
int main()
{
	ll n,m,k,ta,tb,i,ans=-1;cin>>n>>m>>ta>>tb>>k;if (k>=n || k>=m) {cout<<-1;exit(0);}
	for (i=1;i<=n;i++) cin>>a[i],a[i]+=ta;for (i=1;i<=m;i++) cin>>b[i];
	for (i=1;i<=n && i<=k+1;i++)
	{
		int t=lower_bound(b+1,b+m+1,a[i])-b;t+=k-i+1;if (t>m) {cout<<-1;exit(0);}
		ans=max(ans,b[t]+tb);
	}
	cout<<ans;
}