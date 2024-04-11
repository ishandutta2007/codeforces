#include<iostream>
using namespace std;
string s,t;
main()
{
	cin>>s;
	for(int i=0;i<5;i++)
	{
		cin>>t;
		if(s[0]==t[0]||s[1]==t[1])
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
}