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
		int cnt=0;
		for(char c:S)cnt+=c=='N';
		cout<<(cnt==1?"NO\n":"YES\n");
	}
}