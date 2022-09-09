#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long int li;
typedef vector<int> vi;

int main()
{
string q[3];
int a[3];
a[0]=0; a[1]=0; a[2]=0;
int i;
for (i=0; i<3; i++)
{
	cin>>q[i];
	char w=getchar ();
}
for (i=0; i<3; i++)
{
	if (q[i][1]=='<')
	a[q[i][2]-65]++;
	else 
	a[q[i][0]-65]++;
}
if (a[0]==a[1] || a[1]==a[2] || a[0]==a[2])
{
	printf ("Impossible");
	return 0;
}
for (i=0; i<3; i++)
if (a[i]==0)
putchar (i+65);
for (i=0; i<3; i++)
if (a[i]==1)
putchar (i+65);
for (i=0; i<3; i++)
if (a[i]==2)
putchar (i+65);
return 0;
}