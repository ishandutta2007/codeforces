#include<bits/stdc++.h>
using namespace std;
long long mod = 998244353;
int main()
{
	long long n;
	long long p=1;
	long long s=0;
	long long t;
	scanf("%lld",&n);
	for(long long i=2;i<=n;i++) {
		p*=i;
		p%=mod;
	}
	s+=p;
	long long k=1;
	for(long long i=n;i>=1;i--) {
		k=k*i;
		k%=mod;
		t=p-k;
		t%=mod;
		if(t<0) t+=mod;
		s+=t;
		s%=mod;
	}
	printf("%lld",s);
	return 0;
}