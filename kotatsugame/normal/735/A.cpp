#include <iostream>
using namespace std;

int main() {
	string s;
	int n,k;cin>>n>>k>>s;
	int g,t;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='G')
		{
			g=i;
		}
		else if(s[i]=='T')t=i;
	}
	if(t<g)
	{
		for(int i=g;i>=0;i-=k)
		{
			if(s[i]=='#')
			{
				cout<<"NO"<<endl;
				return 0;
			}
			else if(i==t)
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	else
	{
		for(int i=g;i<n;i+=k)
		{
			if(s[i]=='#')
			{
				cout<<"NO"<<endl;
				return 0;
			}
			else if(i==t)
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}