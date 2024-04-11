#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a,b;
signed main()
{
	scanf("%lld",&n);
	for(int am=1;am<=n;am++)
	{
		scanf("%lld%lld",&a,&b);
		int sma=b/a,big=b/a+1;
		printf("%lld\n",(a-b%a)*sma*sma+b%a*big*big);
	}
	return 0;
}