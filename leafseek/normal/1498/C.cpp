#include<bits/stdc++.h>
#define int long long
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5,Mod=1000000007;
int a[MaxN];
signed main()
{
	register int T;
	scanf("%lld",&T);
	register int n,k;
	while(T--)
	{
		scanf("%lld%lld",&n,&k),--n;
		if(k==1)
		{
			printf("%lld\n",1LL);
			continue;
		}
		if(n==0)
		{
			printf("%lld\n",2LL);
			continue;
		}
		register int Sum=1;
		a[1]=1;
		rep(i,2,n)
			a[i]=0;
		rep(i,2,k)
		{
			rep(j,1,n)
				a[j]=(a[j]+a[j-1])%Mod,Sum=(Sum+a[j])%Mod;
			rep(j,1,n>>1)
				swap(a[j],a[n-j+1]);
		}
		printf("%lld\n",(Sum+1)%Mod);
	}
	return 0;
}