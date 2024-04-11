#include<bits/stdc++.h>
using namespace std;
char c[444444];
int n,pos;
int main()
{
	scanf("%d",&n);
	scanf("%s",c);
	pos=-1;
	for (int i=0;i<n-1;i++)
	{
		if (c[i]>c[i+1]) 
		{
			pos=i;
			break;
		}
	}
	if (!~pos) 
	{
		for (int i=0;i<n-1;i++)
		{
			printf("%c",c[i]);
		}
		printf("\n");
	}
	else 
	{
		for (int i=0;i<n;i++)
		{
			if (i!=pos) printf("%c",c[i]);
		}
		printf("\n");
	}
	return 0;
}