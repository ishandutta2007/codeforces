#include<iostream>
#include<string>
using namespace std;
int n;
string s1,s;
int main()
{
	cin>>n>>s1>>s;
	if (s=="week")
	{
		if (n==5 || n==6) cout<<53<<endl;
		else cout<<52<<endl;
	}
	else
	{
		if (n==31) cout<<7<<endl;
		else if (n==30) cout<<11<<endl;
		else cout<<12<<endl;
	}
	return 0;
}