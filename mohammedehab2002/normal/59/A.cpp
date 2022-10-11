#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int i,up=0,low=0;
	string s;
	cin >> s;
	for (i=0;i<s.size();i++)
	{
		if (s[i]>='A' && s[i]<='Z')
		up++;
		else
		low++;
	}
	if (up>low)
	{
		for (i=0;i<s.size();i++)
		{
			if (s[i]>'Z')
			s[i]=s[i]-'a'+'A';
		}
	}
	else
	{
		for (i=0;i<s.size();i++)
		{
			if (s[i]<='Z')
			s[i]=s[i]-'A'+'a';
		}
	}
	cout << s;
}