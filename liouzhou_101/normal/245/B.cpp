#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

string s;

int main()
{
	cin>>s;
	int n=s.length(),p;
	if (s[0]=='f')
	{
		cout<<"ftp://";
		p=3;
	}
	else
	{
		cout<<"http://";
		p=4;
	}
	for (int i=p+1;i<n;++i)
		if (s[i]=='r'&&s[i+1]=='u')
		{
			for (int j=p;j<i;++j)
				cout<<s[j];
			cout<<".ru";
			if (i+1==n-1) break;
			cout<<"/";
			for (int j=i+2;j<n;++j)
				cout<<s[j];
			break;
		}
	return 0;
}