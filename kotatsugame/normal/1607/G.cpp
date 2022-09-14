#include<iostream>
#include<algorithm>
using namespace std;
int T,N,M;
int A[2<<17],B[2<<17],ans[2<<17];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		long long sum=0;
		for(int i=0;i<N;i++)
		{
			cin>>A[i]>>B[i];
			ans[i]=max(M-B[i],0);
			sum+=(A[i]-ans[i])-(B[i]-(M-ans[i]));
		}
		for(int i=0;i<N;i++)
		{
			long long t=min({max(sum,0LL)/2,(long long)(M-ans[i]),(long long)(A[i]-ans[i])});
			ans[i]+=t;
			sum-=t*2;
		}
		cout<<abs(sum)<<"\n";
		for(int i=0;i<N;i++)cout<<ans[i]<<" "<<M-ans[i]<<"\n";
	}
}