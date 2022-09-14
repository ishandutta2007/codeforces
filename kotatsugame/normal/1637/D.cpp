#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
int T,N;
int A[100],B[100];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		long long S=0,T=0;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			S+=A[i]*A[i];
			T+=A[i];
		}
		for(int i=0;i<N;i++)
		{
			cin>>B[i];
			S+=B[i]*B[i];
			T+=B[i];
		}
		bitset<20001>dp;
		dp.reset();
		dp[0]=1;
		for(int i=0;i<N;i++)
		{
			dp=dp<<A[i]|dp<<B[i];
		}
		long long ans=T*T;
		for(int i=0;i<=T;i++)if(dp[i]==1)ans=min(ans,(long long)i*i+(T-i)*(T-i));
		cout<<ans+S*(N-2)<<"\n";
	}
}