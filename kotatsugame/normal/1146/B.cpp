#include<iostream>
using namespace std;
string s,t;
main()
{
	cin>>s;
	t="";
	int id=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='a')t+=s[i];
		else id=i+1;
	}
	if(t.size()%2)cout<<":("<<endl;
	else
	{
		if(t.substr(0,t.size()/2)!=t.substr(t.size()/2))cout<<":("<<endl;
		else if(s.substr(s.size()-t.size()/2)!=t.substr(t.size()/2))cout<<":("<<endl;
		else if(id+t.size()/2>s.size())cout<<":("<<endl;
		else cout<<s.substr(0,s.size()-t.size()/2)<<endl;
	}
}