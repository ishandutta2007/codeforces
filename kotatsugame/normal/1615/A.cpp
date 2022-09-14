#include<iostream>
using namespace std;
int T,N;
int A[100];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int S=0;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			S+=A[i];
		}
		cout<<(S%N==0?0:1)<<"\n";
	}
}