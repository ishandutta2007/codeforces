#include<iostream>
using namespace std;
int N,K;
main()
{
	cin>>N>>K;
	for(;K--;)
	{
		N=N%10?N-1:N/10;
	}
	cout<<N<<endl;
}