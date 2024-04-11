#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
ll a[200010];
int main()
{
	ll n,s,i,ps=1,zw,ans=0;cin>>n>>s;for (i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);while (a[ps++]<s && ps<=n+1);ps--;zw=(n+1)/2;
	if (ps>zw) ps--,swap(ps,zw);
	for (i=ps;i<=zw;i++) ans+=abs(s-a[i]);
	cout<<ans;
}