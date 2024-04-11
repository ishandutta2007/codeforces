#include<iostream>
using namespace std;
long long N;
main()
{
	cin>>N;
	int T=1;
	while(T<N)N-=T++;
	cout<<N<<endl;
}