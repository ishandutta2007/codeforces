#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;
int n, b;
char s[103];
int main ()
{
	int i, z=0;
	gets (s);
	n=strlen(s);
	putchar(s[0]);
	for (i=1; i<n-3; i++)
	{
		if (s[i]=='a' && s[i+1]=='t' && z==0)
		{
			printf ("@");
			z=1;
			i++;
		}
		else
		{
			if (s[i]=='d' && s[i+1]=='o' && s[i+2]=='t')
		{
			printf (".");
			i++; i++;
		}
			else 
			{
				putchar (s[i]);
			}
		}
	}
	if (z==0)
	{
		printf ("@");
		putchar (s[n-1]);
		return 0;
	}
	int j;
	for (j=i; j<n; j++)
		putchar (s[j]);
return 0;
}