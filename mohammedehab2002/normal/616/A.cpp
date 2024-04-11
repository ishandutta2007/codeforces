#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	string s1,s2,noz1,noz2;
	cin >> s1 >> s2;
	int lz=0;
	while (s1[lz]=='0' && lz<s1.size())
	lz++;
	noz1=s1.substr(lz,s1.size());
	lz=0;
	while (s2[lz]=='0' && lz<s2.size())
	lz++;
	noz2=s2.substr(lz,s2.size());
	if (noz1.size()>noz2.size())
	{
		cout << '>';
		return 0;
	}
	if (noz2.size()>noz1.size())
	{
		cout << '<';
		return 0;
	}
	if (noz1==noz2)
	{
		cout << '=';
		return 0;
	}
	else if (noz1>noz2)
	{
		cout << '>';
		return 0;
	}
	else
	{
		cout << '<';
		return 0;
	}
}