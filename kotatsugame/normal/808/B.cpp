#include<iostream>
#include<iomanip>
using namespace std;
int N,K;
int A[2<<17];
main()
{
	cin>>N>>K;
	for(int i=0;i<N;i++)cin>>A[i];
	long long sum=0;
	long long now=0;
	for(int i=0;i<K-1;i++)now+=A[i];
	for(int i=K-1;i<N;i++)
	{
		now+=A[i];
		sum+=now;
		now-=A[i-(K-1)];
	}
	cout<<fixed<<setprecision(16)<<sum/(N-K+1.)<<endl;
}