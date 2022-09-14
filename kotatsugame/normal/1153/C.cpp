#include<iostream>
#include<algorithm>
using namespace std;
int n;
string s;
main()
{
	cin>>n>>s;
	if(n%2==1||s[0]==')'||s[n-1]=='(')
	{
		cout<<":("<<endl;
		return 0;
	}
	s[0]='(';
	s[n-1]=')';
	int op=n/2-1,cl=n/2-1;
	for(int i=1;i<n-1;i++)
	{
		if(s[i]=='(')op--;
		else if(s[i]==')')cl--;
	}
	if(op<0||cl<0)
	{
		cout<<":("<<endl;
		return 0;
	}
	int de=0;
	for(int i=1;i<n-1;i++)
	{
		if(s[i]==')')
		{
			de--;
			if(de<0)
			{
				cout<<":("<<endl;
				return 0;
			}
		}
		else if(s[i]=='(')
		{
			de++;
		}
		else
		{
			if(op)
			{
				op--;
				s[i]='(';
				de++;
			}
			else
			{
				cl--;
				s[i]=')';
				de--;
				if(cl<0||de<0)
				{
					cout<<":("<<endl;
					return 0;
				}
			}
		}
	}
	cout<<s<<endl;
}