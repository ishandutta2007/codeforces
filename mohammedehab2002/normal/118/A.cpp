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
		if (isupper(s[i]))
		s[i]=tolower(s[i]);
		if (s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' && s[i]!='y')
		cout << '.' << s[i];
	}
}