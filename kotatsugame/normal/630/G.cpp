#include<iostream>
using namespace std;
long long N;
main()
{
	cin>>N;
	//N H 5=N+4 C 5
	//N H 3=N+2 C 3
	long long ans=1;
	for(int i=1;i<=5;i++)ans=ans*(N+5-i)/i;
	long long bns=1;
	for(int i=1;i<=3;i++)bns=bns*(N+3-i)/i;
	cout<<ans*bns<<endl;
}