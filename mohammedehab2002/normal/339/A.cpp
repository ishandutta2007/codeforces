#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int i,x;
	string s;
	cin >> s;
	for (i=0;i<s.size();i++)
	{
		for (x=i+1;x<s.size();x++)
		{
			if (s[i]>s[x] && s[i]!='+' && s[x]!='+')
			swap (s[i],s[x]);
		}
	}
	cout << s;
}