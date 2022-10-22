#include<bits/stdc++.h>
#define int long long 
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5;
int a[MaxN];
signed main()
{
	register int T;
	scanf("%lld",&T);
	while(T--)
	{
		register int p,a,b,c;
		scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
		register int ta=((p+a-1)/a)*a;
		register int tb=((p+b-1)/b)*b;
		register int tc=((p+c-1)/c)*c;
		printf("%lld\n",min(ta,min(tb,tc))-p);
	}
	return 0;
}