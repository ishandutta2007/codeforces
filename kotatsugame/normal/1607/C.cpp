#include<iostream>
#include<algorithm>
using namespace std;
int T,N,A[2<<17];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		sort(A,A+N);
		long long ans=-1e18,sub=0;
		for(int i=0;i<N;i++)
		{
			long long now=A[i]-sub;
			ans=max(ans,now);
			sub+=now;
		}
		cout<<ans<<"\n";
	}
}