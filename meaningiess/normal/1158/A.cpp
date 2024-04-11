#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100010],b[100010];
int main()
{
	int n,m,i;ll ans=0;cin>>n>>m;
	for (i=1;i<=n;i++) cin>>a[i],ans+=a[i]*m;for (i=1;i<=m;i++) cin>>b[i];
	sort(a+1,a+n+1);sort(b+1,b+m+1);if (a[n]>b[1]) {puts("-1");exit(0);}
	for (i=2;i<=m;i++) ans+=b[i]-a[n];if (b[1]!=a[n]) cout<<ans+b[1]-a[n-1];else cout<<ans;
}