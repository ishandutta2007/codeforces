#include<iostream>
using namespace std;
string s;
main()
{
	int cnt=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='a'||s[i]=='i'||s[i]=='u'||s[i]=='e'||s[i]=='o'||s[i]=='1'||s[i]=='3'||s[i]=='5'||s[i]=='7'||s[i]=='9')cnt++;
	}
	cout<<cnt<<endl;
}