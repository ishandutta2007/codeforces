#include<iostream>
using namespace std;
string s,t;
main()
{
	cin>>s;
	int c=0;
	for(int i=0;i<s.size();i++)c+=s[i]=='a';
	if(c*2>s.size())cout<<s.size()<<endl;
	else cout<<c*2-1<<endl;
}