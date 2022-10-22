#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a,b,k;
signed main()
{
	scanf("%lld",&n);
	for(int am=1;am<=n;am++)
	{
		scanf("%lld%lld%lld",&a,&b,&k);
		int g=__gcd(a,b);
		a/=g;
		b/=g;
		if(a>b) swap(a,b);
		if((b-2)/a+1>=k) printf("REBEL\n");
		else printf("OBEY\n");
	}
	return 0;
}