#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
int main()
{
	int i;
	string s;
	getline (cin,s);
	for (i=s.size()-1;i>=0;i--)
	{
		s[i]=tolower(s[i]);
		if (isalpha(s[i]))
		{
			if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='y')
			cout << "YES";
			else
			cout << "NO";
			return 0;
		}
	}
}