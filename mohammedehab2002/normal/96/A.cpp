#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int c1=0,c2=0,i;
	string s;
	cin >> s;
	for (i=0;i<s.size();i++)
	{
		if (s[i]=='0')
		{
			c1++;
			c2=0;
		}
		else
		{
			c2++;
			c1=0;
		}
		if (c1==7 || c2==7)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}