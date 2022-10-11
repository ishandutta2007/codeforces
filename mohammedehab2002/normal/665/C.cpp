#include <iostream>
#include <string.h>
using namespace std;
char func(char a,char b)
{
	for (char i='a';i<='z';i++)
	{
		if (i!=a && i!=b)
		return i;
	}
}
int main()
{
	string s;
	cin >> s;
	for (int i=1;i<s.size();i++)
	{
		if (s[i]==s[i-1])
		{
			if (i==s.size()-1)
			{
				if (s[i]=='a')
				s[i]='b';
				else
				s[i]='a';
			}
			else
			s[i]=func(s[i],s[i+1]);
		}
	}
	cout << s;
}