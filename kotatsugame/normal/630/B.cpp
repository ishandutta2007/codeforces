#include<iostream>
#include<iomanip>
using namespace std;
main()
{
	double N;
	int T;
	cin>>N>>T;
	double A=1.000000011;
	while(T)
	{
		if(T&1)N*=A;
		T>>=1;
		A*=A;
	}
	cout<<fixed<<setprecision(16)<<N<<endl;
}