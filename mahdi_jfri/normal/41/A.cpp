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
	int j=0;
	for(int i=a.size()-1;i>-1;i--)
	{
		if(b[j]!=a[i]) {cout<<"NO"; return 0;}
		j++;
	}
	cout<<"YES";
}