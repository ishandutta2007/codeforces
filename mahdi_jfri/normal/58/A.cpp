#include<iostream>
#include<string>
using namespace std;
char ch[6]={'h','e','l','l','o'};
string check(string a, int j)
{
	for(int i=0;i<a.size();i++)
	{
		if( a[i] == ch[j]){string b=a.substr(i+1); return b;}
	}
	return "1";
}
int main()
{
	string a;
	cin>>a;
	for(int i=0;i<5;i++)
	{
		string b=check(a,i);
		a=b;
	}
	if(a!="1")
	cout<<"YES";
	else
	cout<<"NO";
}