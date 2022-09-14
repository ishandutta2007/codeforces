#include<iostream>
#include<algorithm>
using namespace std;
int T,A,B;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>A>>B;
		cout<<min({A,B,(A+B)/4})<<"\n";
	}
}