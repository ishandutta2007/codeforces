#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;
char s[100][22];
int main ()
{
	//freopen("input.txt", "r", stdin);
	////freopen ("output.txt", "w", stdout);
int n, i, j, k=0, q=0;
for (i=0; i<100; i++)
memset (s[i], 0, sizeof(s[i]));
scanf("%d\n", &n);
int z=0;
for (i=0; i<n; i++)
{
	gets (s[i]);
	for (j=0; j<i; j++)
	{
		z=1;
		for (k=0; k<22; k++)
			if (s[j][k]!=s[i][k])
			{
				z=0;
				break;
			}
		if (z==1)
			break;
	}
	if (z==0)
		q++;
}
printf ("%d", q);
return 0;
}