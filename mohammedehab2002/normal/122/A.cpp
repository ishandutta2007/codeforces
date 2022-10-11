#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
	char s[5];
	bool test;
	int n,i,x;
	cin >> n;
	for (i=4;i<=n;i++)
	{
		test=true;
		if (n%i==0)
		{
			sprintf (s,"%d",i);
			for (x=0;x<strlen(s);x++)
			{
				if (s[x]!='4' && s[x]!='7')
				test=false;
			}
			if (test==true)
			{
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}