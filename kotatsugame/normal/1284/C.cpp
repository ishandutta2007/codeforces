#include<iostream>
using namespace std;
long long N,M;
long long F[3<<17];
main()
{
	cin>>N>>M;
	F[0]=1;
	for(long long i=1;i<=N;i++)F[i]=F[i-1]*i%M;
	long long ans=0;
	for(long long W=1;W<=N;W++)
	{
		ans+=F[W]*F[N-W]%M*(N-W+1)%M*(N-W+1)%M;
		ans%=M;
	}
	cout<<ans<<endl;
}