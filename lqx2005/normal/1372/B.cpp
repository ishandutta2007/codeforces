#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
signed main()
{
	scanf("%lld",&t);
	for(int am=1;am<=t;am++)
	{
		scanf("%lld",&n);
		int fac=1;
		for(int d=2;d*d<=n;d++)
		{
			if(n%d) continue;
			fac=n/d;
			break;
		}
		printf("%lld %lld\n",fac,n-fac);
	}
	return 0;
}