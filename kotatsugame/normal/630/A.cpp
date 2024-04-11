#include<iostream>
using namespace std;
main()
{
	long long N,E=1,A=5;
	cin>>N;
	while(N)
	{
		if(N&1)E=E*A%100;
		N>>=1;
		A=A*A%100;
	}
	if(E<10)cout<<0;
	cout<<E<<endl;
}