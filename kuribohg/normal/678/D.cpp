#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MOD=1000000007;
LL A,B,x,n;
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
int main()
{
	cin>>A>>B>>n>>x;
	if(A==1) cout<<(n%MOD*B+x)%MOD<<endl;
	else cout<<((qpow(A,n,MOD)*x)%MOD+(qpow(A-1,MOD-2,MOD)*((qpow(A,n,MOD)+MOD-1)%MOD))%MOD*B%MOD)%MOD<<endl;
	return 0;
}