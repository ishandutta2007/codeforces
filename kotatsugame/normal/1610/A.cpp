#include<iostream>
using namespace std;
int T,N,M;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		if(N==1)
		{
			if(M==1)cout<<"0\n";
			else cout<<"1\n";
		}
		else
		{
			if(M==1)cout<<"1\n";
			else cout<<"2\n";
		}
	}
}