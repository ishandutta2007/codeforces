#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
	char a[10000],b[10000],sum[10000];
	int c,i,x;
	cin >> a >> b;
	c=atoi(a)+atoi(b);
	sprintf(sum,"%d",c);
	for (i=0;i<strlen(a);i++)
	{
		if (a[i]=='0')
		{
			for (x=i;x<strlen(a)-1;x++)
			a[x]=a[x+1];
			i--;
			a[(strlen(a)-1)]=0;
		}
	}
	for (i=0;i<strlen(b);i++)
	{
		if (b[i]=='0')
		{
			for (x=i;x<strlen(b)-1;x++)
			b[x]=b[x+1];
			i--;
			b[(strlen(b)-1)]=0;		
		}
	}
	for (i=0;i<strlen(sum);i++)
	{
		if (sum[i]=='0')
		{
			for (x=i;x<strlen(sum)-1;x++)
			sum[x]=sum[x+1];
			i--;
			sum[(strlen(sum)-1)]=0;
		}
	}
	if (atoi(a)+atoi(b)==atoi(sum))
	cout << "YES";
	else
	cout << "NO";
}