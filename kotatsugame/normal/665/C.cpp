#include<iostream>
using namespace std;
string s;
main()
{
	cin>>s;
	for(int i=1;i<s.size();i++)if(s[i-1]==s[i])
	{
		char a=s[i-1],b=i+1==s.size()?a:s[i+1];
		char c='a';
		while(c==a||c==b)c++;
		s[i]=c;
	}
	cout<<s<<endl;
}