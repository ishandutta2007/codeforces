#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;
int n;
char s[101];
int main ()
{
	int m, j, i;
	gets (s);
	char a;
	n=strlen (s);
	for (i=n-1; i>=0; i--)
	{
		a=getchar ();
		if (a!=s[i])
		{
			printf ("NO");
			return 0;
		}
	}
	a=getchar ();
	if (a!='\n')
	{
		printf ("NO");
		return 0;
	}
	printf ("YES");
return 0;
}