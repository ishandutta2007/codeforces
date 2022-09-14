#include<iostream>
using namespace std;
int T;
int B[7];
main()
{
	cin>>T;
	for(;T--;)
	{
		for(int i=0;i<7;i++)cin>>B[i];
		cout<<B[0]<<" "<<B[1]<<" "<<B[B[0]+B[1]==B[2]?3:2]<<"\n";
	}
}