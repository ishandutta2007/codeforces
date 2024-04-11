#include<iostream>
#include<string>
using namespace std;
string s,p;
int main()
{
	cin>>s;
	for (int i=s.size()-1;i>=0;i--)
	{
		p+=s[i];
	}
	cout<<s+p<<endl;
	return 0;
}