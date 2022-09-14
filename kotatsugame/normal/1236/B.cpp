#include<iostream>
using namespace std;
long long mod=1e9+7;
long long power(long long a,long long b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
main()
{
	long long N,M;cin>>N>>M;
	cout<<power((power(2,M)+mod-1)%mod,N)<<endl;
}