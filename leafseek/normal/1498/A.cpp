#include<bits/stdc++.h>
#define int long long
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=10+5;
inline int Gcd(const register int a,const register int b)
{
	return (b==0)?a:Gcd(b,a%b);
}
inline int digSum(const register int val)
{
	register int sum=0,mem=val;
	while(mem>=1)
		sum+=(mem%10),mem/=10;
	return sum;
}
inline bool pd(const register int val)
{
	return (Gcd(val,digSum(val))==1?false:true);
}
signed main()
{
	register int T;
	scanf("%lld",&T);
	register int n;
	while(T--)
	{
		scanf("%lld",&n);
		rep(Delta,0,100000)
			if(pd(n+Delta))
			{
				printf("%lld\n",n+Delta);
				break;
			}
	}
	return 0;
}