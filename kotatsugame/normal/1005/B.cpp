#include<iostream>
using namespace std;
string s,t;
main()
{
	cin>>s>>t;
	int id=0;
	while(id<s.size()&&id<t.size()&&s[s.size()-id-1]==t[t.size()-id-1])id++;
	cout<<s.size()+t.size()-2*id<<endl;
}