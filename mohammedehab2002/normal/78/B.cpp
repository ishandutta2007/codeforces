#include <iostream>
using namespace std;
int main()
{
	char s[]="ROYGBIV";
	int n,mod,div,i,x;
	cin >> n;
	mod=n%7;
	div=n/7;
	for (i=0;i<div;i++)
	{
		for (x=0;x<7;x++)
		cout << s[x];
	}
	if (n-div*7<=4)
	{
		for (i=3;i<mod+3;i++)
		cout << s[i];
	}
	else
	{
		for (i=3;i<7;i++)
		cout << s[i];
		if (n-div*7==5)
		cout << "G";
		else
		cout << "GB";
	}
}