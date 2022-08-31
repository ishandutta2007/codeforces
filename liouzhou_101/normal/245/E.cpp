#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

string s;

int main()
{
	cin>>s;
	int n=s.length();
	int pin=0,pout=0;
	for (int i=0;i<n;++i)
	{
		if (s[i]=='+')
		{
			++pin;
			if (pout) --pout;
		}
		else
		{
			++pout;
			if (pin) --pin;
		}
	}
	cout<<pin+pout<<endl;
	return 0;
}