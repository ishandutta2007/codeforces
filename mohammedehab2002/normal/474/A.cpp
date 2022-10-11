#include <iostream>
#include <ctype.h>
using namespace std;
int main()
{
	size_t place;
	int i;
	char c;
	string s,k="qwertyuiopasdfghjkl;zxcvbnm,./";
	cin >> c >> s;
	for (i=0;i<s.size();i++)
	{
		place=k.find(s[i]);
		if (c=='R')
		cout << k[place-1];
		else
		cout << k[place+1];
	}
}