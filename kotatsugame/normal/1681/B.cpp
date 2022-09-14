#include<iostream>
using namespace std;
int T,N,A[2<<17],M;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		cin>>M;
		int S=0;
		for(int i=0;i<M;i++)
		{
			int b;cin>>b;
			S+=b;
			if(S>=N)S-=N;
		}
		cout<<A[S]<<"\n";
	}
}