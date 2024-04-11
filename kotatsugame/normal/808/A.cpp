#include<iostream>
using namespace std;
int N;
main()
{
	cin>>N;
	int L=N;
	int p=1;
	while(N>=10)N/=10,p*=10;
	p*=N+1;
	cout<<p-L<<endl;
}