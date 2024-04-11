#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int i;
	string s;
	cin >> s;
	for (i=0;i<s.size();i++)
	{
		if (s[i]>'4')
		s[i]='9'-s[i]+'0';
	}
	if (s[0]=='0')
	s[0]='9';
	cout << s;
}