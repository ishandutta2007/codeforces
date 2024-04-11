#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	string s;
	int i;
	cin >> s;
	for (i=0;i<s.size();i++)
	{
		if (s[i]=='.')
		cout << 0;
		else if (s[i]=='-')
		{
			i++;
			if (s[i]=='-')
			cout << 2;
			else
			cout << 1;
		}
	}
}