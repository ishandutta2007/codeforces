#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL n,ans;
LL gcd(LL a,LL b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
LL lcm(LL a,LL b)
{
	return a/gcd(a,b)*b;
}
int main()
{
	scanf("%I64d",&n);
	for(LL i=max(n-100,1LL);i<=n;i++)
		for(LL j=max(n-100,1LL);j<=n;j++)
			for(LL k=max(n-100,1LL);k<=n;k++)
				ans=max(ans,lcm(i,lcm(j,k)));
	printf("%I64d\n",ans);
	return 0;
}