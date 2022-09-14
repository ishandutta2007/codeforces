#include<iostream>
using namespace std;
const long long mod=1e9+7;
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		int N,K;
		cin>>N>>K;
		long long ans=0;
		for(int i=0;i<30;i++)
		{
			ans=ans*N%mod;
			if(K>>29-i&1)ans=(ans+1)%mod;
		}
		cout<<ans<<"\n";
	}
}