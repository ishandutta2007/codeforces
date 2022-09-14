#include<iostream>
using namespace std;
int T;
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>S;
		int ans=0;
		for(char c:S)if(ans<c-'0')ans=c-'0';
		cout<<ans<<"\n";
	}
}