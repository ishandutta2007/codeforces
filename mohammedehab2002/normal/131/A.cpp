#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
int main()
{
	int i;
	string s;
	cin >> s;
	for (i=0;i<s.size();i++)
	{
		if (i!=0 && islower(s[i]))
		{
			cout << s;
			return 0;
		}
	}
	for (i=0;i<s.size();i++)
	{
		if (isupper(s[i]))
		s[i]=tolower(s[i]);
		else
		s[i]=toupper(s[i]);
	}
	cout << s;
}