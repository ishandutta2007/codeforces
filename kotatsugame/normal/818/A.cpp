#include<iostream>
using namespace std;
long long N,K;
main()
{
	cin>>N>>K;
	long long A=N/2/(K+1);
	long long B=A*K;
	cout<<A<<" "<<B<<" "<<N-A-B<<endl;
}