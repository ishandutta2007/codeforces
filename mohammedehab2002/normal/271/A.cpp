#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
	bool found;
	char s[6];
	int n,i,x;
	cin >> n;
	n++;
	while (found==false)
	{
		found=true;
		sprintf (s,"%d",n);
		for (i=0;i<strlen(s);i++)
		{
			for (x=i+1;x<strlen(s);x++)
			{
				if (s[i]==s[x])
				found=false;
			}
		}
		n++;
	}
	cout << s;
}