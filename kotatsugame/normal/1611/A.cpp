#include<iostream>
using namespace std;
int T;
string N;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		if(N.back()%2==0)
		{
			cout<<"0\n";
		}
		else if(N[0]%2==0)
		{
			cout<<"1\n";
		}
		else
		{
			bool fn=false;
			for(char c:N)if(c%2==0)fn=true;
			cout<<(fn?"2\n":"-1\n");
		}
	}
}