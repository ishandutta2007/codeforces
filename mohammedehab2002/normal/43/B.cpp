#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;
int main()
{
	int i,a1[52],a2[52];
	char s1[200],s2[200];
	gets(s1);
	gets(s2);
	for (i=0;i<52;i++)
	{
		a1[i]=0;
		a2[i]=0;
	}
	for (i=0;i<strlen(s1);i++)
	{
		if (islower(s1[i]))
		a1[s1[i]-'a']++;
		else
		a1[s1[i]-'A'+26]++;
	}
	for (i=0;i<strlen(s2);i++)
	{
		if (islower(s2[i]))
		a2[s2[i]-'a']++;
		else
		a2[s2[i]-'A'+26]++;
	}
	for (i=0;i<52;i++)
	{
		if (a2[i]>a1[i])
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}