#include<iostream>
#include<cstdio>
using namespace std;
long long gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		long long p,q,b;scanf("%lld%lld%lld",&p,&q,&b);
		q=q/gcd(p,q);
		while(1)
		{
			long long k=gcd(q,b);
			if(k==1)break;
			while(q%k==0)q/=k;
		}
		if(q==1)puts("Finite");
		else puts("Infinite");
	}
	return 0;
 } //1/qbb%q0