#include<iostream>
using namespace std;
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		string s;cin>>s;
		bool ok=true;
		for(int i=1;i<s.size();i++)if(s[0]!=s[i])ok=false;
		if(ok)
		{
			cout<<s<<endl;
		}
		else
		{
			string t="";
			for(int i=0;i<s.size();i++)t+="01";
			cout<<t<<endl;
		}
	}
}