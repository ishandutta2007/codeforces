#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll l,r;
int main()
{
	scanf("%lld%lld",&l,&r);
	printf("YES\n");
	for (ll i=l;i<=r;i+=2)
	{
		printf("%lld %lld\n",i,i+1);
	}
	return 0;
}