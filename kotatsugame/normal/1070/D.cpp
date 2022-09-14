#include<iostream>
using namespace std;
int N,K;
int A[2<<17];
main()
{
	cin>>N>>K;
	for(int i=0;i<N;i++)cin>>A[i];
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		if(i>0&&A[i-1]>0)
		{
			ans++;
			int t=K-A[i-1];
			A[i]-=t;
			if(A[i]<0)A[i]=0;
		}
		ans+=A[i]/K;
		A[i]%=K;
	}
	if(A[N-1]>0)ans++;
	cout<<ans<<endl;
}