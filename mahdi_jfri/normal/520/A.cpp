#include<iostream>
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
	string a;
	int b;
	cin>>b;
	cin>>a;
	a=lower(a);
	for(int i=97;i<97+26;i++)
	{
		if(a.find(i)==(string::npos))
		{cout<<"NO"; return 0;}
	}
	cout<<"YES";
}