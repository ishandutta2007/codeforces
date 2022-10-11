#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int c,i;
	string s;
	cin >> s;
	if (s[0]!='-')
	cout << s;
	else
	{
		c=max(s[s.size()-1],s[s.size()-2]);
		if (c==s[s.size()-1])
		{
			for (i=0;i<s.size()-1;i++)
			cout << s[i];
		}
		else
		{
			if (s.size()==3 && s[2]=='0')
			{
				cout << 0;
				return 0;
			}
			for (i=0;i<s.size();i++)
			{
				if (i!=s.size()-2)
				cout << s[i];
			}
		}
	}
}