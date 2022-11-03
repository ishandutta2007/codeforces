#include<iostream>
using namespace std;
bool check(string a)
{
	for(int i=1;i<a.size();i++)
	{
		if(a[i]>='a')
		return 0;
	}
	return 1;
}
string lower(string a)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]<'a')
		a[i]=a[i]-'A'+'a';
		else
		a[i]=a[i]-32;
	}
	return a;
}
int main()
{
	string a;
	cin>>a;
	if(check(a)==1)
	{
		a=lower(a);
	}
	cout<<a;
}