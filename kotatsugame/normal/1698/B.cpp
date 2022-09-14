#include<iostream>
using namespace std;
int T,N,K,A[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		for(int i=0;i<N;i++)cin>>A[i];
		if(K>=2)
		{
			int cnt=0;
			for(int i=1;i<N-1;i++)cnt+=A[i]>A[i-1]+A[i+1];
			cout<<cnt<<"\n";
		}
		else
		{
			cout<<(N-1)/2<<"\n";
		}
	}
}