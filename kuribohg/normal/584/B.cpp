#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
LL qpow(LL x,LL n,LL MOD)
{
	LL p=x,con=1;
	while(n)
	{
		if(n&1) con=(con*p)%MOD;
		p=(p*p)%MOD;
		n>>=1;
	}
	return con;
}
int n;
int main()
{
	scanf("%d",&n);
	printf("%I64d\n",(qpow(27,n,MOD)-qpow(7,n,MOD)+MOD)%MOD);
	return 0;
}