#include<iostream>
#include<algorithm>
using namespace std;
int T,N,A[2<<17];
long long K;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		long long sum=0;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			sum+=A[i];
		}
		long long ans=sum-K;
		if(ans<0)ans=0;
		if(N==1)
		{
			cout<<ans<<"\n";
			continue;
		}
		sort(A,A+N);
		sum-=A[0];
		for(int i=N;--i;)
		{
			sum-=A[i];
			long long c=N-i+1;
			long long t=(K-sum)/c;
			if(t*c>K-sum)t--;
			t-=A[0];
			long long x=-t;
			if(x<0)x=0;
			ans=min(ans,x+N-i);
		}
		cout<<ans<<"\n";
	}
}