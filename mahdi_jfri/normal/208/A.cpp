#include<iostream>
#include<string>
using namespace std;

string hazf(string a)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='W' && a[i+1]=='U' && a[i+2]=='B')
		{
			if(i>0)
			{
			a.insert(i," ");
			a.erase(i+1,3);
			}
			else
			a.erase(i,3);
			i=-1;
		}
	}
	return a;
}

int main()
{
	string a;
	cin>>a;
	a=hazf(a);
	cout<<a;
}