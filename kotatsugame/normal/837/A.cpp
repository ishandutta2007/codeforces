#include<iostream>
using namespace std;
string s;
main()
{
	int ans=0;
	for(;cin>>s;)
	{
		int now=0;
		for(char c:s)now+='A'<=c&&c<='Z';
		if(ans<now)ans=now;
	}
	cout<<ans<<endl;
}