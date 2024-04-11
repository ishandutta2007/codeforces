#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int i,x,test=0;
	string s;
	cin >> s;
	if (s.size()<3)
	{
		cout << s;
		return 0;
	}
	for (i=0;i<s.size()-2;i++)
	{
		if (s[i]=='W' && s[i+1]=='U' && s[i+2]=='B')
		{
			s[i]=' ';
			for (x=i+1;x<s.size()-2;x++)
			s[x]=s[x+2];
			i--;
			s.resize(s.size()-2);
		}
	}
	for (i=0;i<s.size();i++)
	{
		if (s[i]!=' ')
		test=1;
		if (test==1)
		cout << s[i];
	}
}