#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int test=1;
	string s,a;
	cin >> s;
	while (test)
	{
		s[4]++;
		if (s[4]=='9'+1)
		{
			s[4]='0';
			s[3]++;
		}
		if (s[3]=='6')
		{
			s[3]='0';
			s[1]++;
		}
		if (s[1]=='9'+1)
		{
			s[1]='0';
			s[0]++;
		}
		if (s[0]=='2' && s[1]=='4')
		{
			s[0]='0';
			s[1]='0';
		}
		a=s;
		reverse (a.begin(),a.end());
		if (a==s)
		{
			cout << a;
			test=0;
		}
	}
}