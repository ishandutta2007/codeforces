#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int i,c1=0,c2=0,c3=0,test=0,sub;
	string s;
	cin >> s;
	for (i=0;i<s.size();i++)
	{
		if (s[i]=='+')
		test++;
		if (s[i]=='=')
		test++;
		if (test==0)
		c1++;
		else if (test==1 && s[i]!='+')
		c2++;
		else if (test==2 && s[i]!='=')
		c3++;
	}
	sub=max((c1+c2),c3)-min((c1+c2),c3);
	if (sub!=0 && sub!=2)
	cout << "Impossible";
	else
	{
		if (sub==0)
		cout << s;
		else if (c3>c1+c2)
		{
			for (i=0;i<c1+c2+1;i++)
			cout << s[i];
			cout << '|';
			for (i=c1+c2+1;i<s.size()-1;i++)
			cout << s[i];
		}
		else
		{
			if (c1>c2)
			{
				for (i=0;i<c1-1;i++)
				cout << s[i];
				for (i=c1;i<s.size();i++)
				cout << s[i];
			}
			else
			{
				for (i=0;i<c1+c2;i++)
				cout << s[i];
				for (i=c1+c2+1;i<s.size();i++)
				cout << s[i];
			}
			cout << '|';
		}
	}
}