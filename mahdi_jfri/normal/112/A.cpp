#include<iostream>
#include<string>
using namespace std;
string lower(string a)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]<97)
		a[i]=a[i]-'A'+'a';
	}
	return a;
}
int main()
{
	string a,b;
	cin>>a>>b;
	a=lower(a);
	b=lower(b);
	if(a<b)
	cout<<"-1";
	else if(a!=b)
	cout<<"1";
	else
	cout<<"0";
}