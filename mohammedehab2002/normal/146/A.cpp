#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,i,s1=0,s2=0;
	string s;
	cin >> n >> s;
	for (i=0;i<n;i++)
	{
		if (s[i]!='4' && s[i]!='7')
		{
			cout << "NO";
			return 0;
		}
	}
	for (i=0;i<n/2;i++)
	{
		if (s[i]!='0')
		s1+=(int)(s[i]-'1')+1;
	}
	for (i=n/2;i<n;i++)
	{
		if (s[i]!='0')
		s2+=(int)(s[i]-'1')+1;
	}
	if (s1==s2)
	cout << "YES";
	else
	cout << "NO";
}