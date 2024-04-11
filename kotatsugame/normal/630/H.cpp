#include<iostream>
using namespace std;
long long N;
main()
{
	cin>>N;
	long long ans=1;
	for(int i=0;i<5;i++)ans*=N-i;
	long long bns=1;
	for(int i=1;i<=5;i++)bns=bns*(N+1-i)/i;
	cout<<ans*bns<<endl;
}