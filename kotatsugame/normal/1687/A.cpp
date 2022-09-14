#include<iostream>
using namespace std;
int T,N,K;
int A[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=0;i<N;i++)A[i]+=K;
		int len=min(N,K);
		long long ans=0;
		long long sum=0;
		for(int i=0;i<N;i++)
		{
			sum+=A[i];
			if(i>=len)sum-=A[i-len];
			if(i+1>=len)ans=max(ans,sum);
		}
		cout<<ans-(long long)len*(len+1)/2<<"\n";
	}
}