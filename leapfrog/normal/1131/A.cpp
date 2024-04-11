#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	long long l=b+d+1,r=max(a,c)+1;
	printf("%lld\n",(l+r)<<1);
	return 0;
}