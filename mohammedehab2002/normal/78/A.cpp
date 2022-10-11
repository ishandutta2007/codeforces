#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
	int i,aa=0,ab=0,ac=0;
	char a[101],b[101],c[101];
	gets (a);
	gets (b);
	gets (c);
	for (i=0;i<strlen(a);i++)
	{
		if (a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u')
		aa++;
	}
	for (i=0;i<strlen(b);i++)
	{
		if (b[i]=='a' || b[i]=='e' || b[i]=='i' || b[i]=='o' || b[i]=='u')
		ab++;
	}
	for (i=0;i<strlen(c);i++)
	{
		if (c[i]=='a' || c[i]=='e' || c[i]=='i' || c[i]=='o' || c[i]=='u')
		ac++;
	}
	if (aa==5 && ab==7 && ac==5)
	cout << "YES";
	else
	cout << "NO";
}