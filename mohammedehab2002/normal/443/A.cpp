#include <iostream>
#include <string.h>
#include <set>
#include <stdio.h>
using namespace std;
int main()
{
	int i;
	set <char> c;
	char s[1001];
	gets (s);
	for (i=1;i<strlen(s)-1;i++)
	c.insert(s[i]);
	if (c.size()>2)
	cout << c.size()-2;
	else if (c.size()==1)
	cout << 1;
	else
	cout << 0;
}