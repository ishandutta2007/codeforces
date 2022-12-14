#include<iostream>
#include<queue>
#define ll long long
using namespace std;
priority_queue<ll> qa,qb;
ll pa[1111111],pb[1111111],a[1111],b[1111],ans;
ll n,m,k,p,x;
int main()
{
	ans=-1e18;
	cin>>n>>m>>k>>p;
	for (ll i=1;i<=n;i++)
	{
		for (ll j=1;j<=m;j++)
		{
			cin>>x;
			a[i]+=x;
			b[j]+=x;
		}
	}
	for (ll i=1;i<=n;i++) qa.push(a[i]);
	for (ll i=1;i<=m;i++) qb.push(b[i]);
	for (ll i=1;i<=k;i++)
	{
		x=qa.top();
		qa.pop();
		pa[i]=pa[i-1]+x;
		qa.push(x-m*p);
		x=qb.top();
		qb.pop();
		pb[i]=pb[i-1]+x;
		qb.push(x-n*p);
	} 
	for (ll i=0;i<=k;i++)
	{
		ll j=k-i;
		ans=max(ans,pa[i]+pb[j]-i*j*p);
	}
	cout<<ans<<endl;
	return 0;
}