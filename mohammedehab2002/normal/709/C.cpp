#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int i=0;
	while (i<s.size() && s[i]=='a')
	i++;
	if (i==s.size())
	{
		s[s.size()-1]='z';
		cout << s;
	}
	else
	{
		for (int x=i;x<s.size() && s[x]!='a';x++)
		s[x]--;
		cout << s;
	}
}