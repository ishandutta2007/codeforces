#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
string a[12];
string b;
int main()
{
	char k=90;
	int n,l,i,t;
	while (k!='\n')
	{
		k=getchar ();
		if (k!='\n')
		b.push_back(k);
	}
	scanf("%d",&n);
	n=n%12;
	a[0]="January";
	a[1]="February";
	a[2]="March";
	a[3]="April";
	a[4]="May";
	a[5]="June";
	a[6]="July";
	a[7]="August";
	a[8]="September";
	a[9]="October";
	a[10]="November";
	a[11]="December";
	for(i=0;i<12;i++)
	if (b==a[i])
	{
		t=i;
		break;
	}
	t=(t+n)%12;
	for (i=0; i<a[t].length(); i++)
		putchar (a[t][i]);
	return 0;
}