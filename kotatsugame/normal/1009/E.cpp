#include<iostream>
using namespace std;
long long n,a[1<<20];
long long M=998244353;
long long pow(long long a,long long b){return b?pow(a*a%M,b/2)*(b%2?a:1)%M:1;}
main()
{
	scanf("%lld",&n);
	for(int i=0;i<n;i++)scanf("%lld",a+i);
	long ans=0,now=0;
	for(int i=0;i<n;i++)
	{
		if(i<n-1)ans=(ans+a[i]*pow(2,n-i-2)%M*(2+n-i-1)%M)%M;
		else ans=(ans+a[i])%M;
	}
	cout<<ans<<endl;
}