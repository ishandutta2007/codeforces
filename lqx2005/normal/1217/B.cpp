#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=100;
const ll INF=1e8;
ll t,n,x,d,h;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&x);
		ll ans=-INF,maxlen=-INF;
		for(ll i=1;i<=n;i++) 
		{
			scanf("%lld%lld",&d,&h);
			ans=max(ans,d-h);
			maxlen=max(maxlen,d);
		}
		x-=maxlen;
		if(x<=0) 
		{
			printf("1\n");
			continue;
		}
		if(ans<=0) printf("-1\n");
		else
		{
			if(x%ans==0) printf("%lld\n",(x/ans)+1);
			else printf("%lld\n",(x/ans+1)+1);
		}
	}
	return 0;
}