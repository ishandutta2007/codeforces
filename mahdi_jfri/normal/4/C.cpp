#include <iostream>
#include <map>
using namespace std;
map<string, int> a;
int main()
{
	int n;
	cin>> n;
	for (int i = 0; i < n; i++)
	{
		string b;
		cin>>b;
		if(a[b]==0)
		{cout<<"OK"<<endl; a[b]=1;}
		else
		{cout<<b<<a[b]++<<endl;}
	}
}