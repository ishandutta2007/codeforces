#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF=100000000;
ll n;
int main()
{
	ll ans=INF;
	scanf("%lld",&n);
	ll len=sqrt(n);
	for(ll i=len;i<=2*len;i++)
	{
		for(ll j=len;j<=2*len;j++)
		{
			if(i*j>=n)
			{
				ans=min(ans,i+j);
				break;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}