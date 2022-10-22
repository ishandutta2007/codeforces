#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=100000;
ll n,m;
ll a[N+5],cost[N+5];
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	ll sum=1,ans=0,step=0;
	for(ll i=1;i<=n;i++)
	{
		if(a[i]<=-1) sum=-sum,ans+=(-1-a[i]);
		else if(a[i]>=1) ans+=(a[i]-1);
		else ans++,step++;
	}
	if(sum==1) printf("%lld\n",ans);
	else
	{
		if(step>=1) printf("%lld\n",ans);
		else  printf("%lld\n",ans+2);
	}
	return 0;
}