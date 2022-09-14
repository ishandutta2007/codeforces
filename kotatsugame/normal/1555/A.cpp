#include<iostream>
using namespace std;
int T;
long long N;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		if(N%2==1)N++;
		N/=2;
		if(N<3)N=3;
		cout<<N*5<<endl;
	}
}