#include <bits/stdc++.h>
using namespace std;
int h;
int g,l;
int a[2000000];
int d[2000000];
int main()
{
	scanf("%d",&h);
	bool p=true;
	for(int i=0;i<=h;i++) scanf("%d",&a[i]);
	for(int i=0;i<h;i++)
	{
		if(a[i]>1 && a[i+1]>1) p=false;
	}
	if(p)
	{
		printf("perfect\n");
		return 0;
	}
	printf("ambiguous\n");
	int k=2;
	printf("0 ");
	d[1]=0;
	g=1;
	l=-1;
	for(int i=1;i<=h;i++)
	{
		if(a[i]>1)
		{
			for(int j=0;j<a[i];j++)
			{
				d[k]=d[g]+1;
				printf("%d ",g);
				k++;
			}
			g=k-a[i];
			l=-1;
		}
		else
		{
			d[k]=d[g]+1;
			printf("%d ",g);
			g=k;
			k++;
			l=-1;
		}
	}
	printf("\n");
	k=2;
	printf("0 ");
	d[1]=0;
	g=1;
	l=-1;
	for(int i=1;i<=h;i++)
	{
		if(a[i]>1)
		{
			if(l!=-1)
			{
				printf("%d ",l);
				d[k]=d[l]+1;
				k++;
				for(int j=1;j<a[i];j++)
				{
					d[k]=d[g]+1;
					printf("%d ",g);
					k++;
				}
			}
			else
			{
				for(int j=0;j<a[i];j++)
				{
					d[k]=d[g]+1;
					printf("%d ",g);
					k++;
				}
			}
			g=k-a[i];
			l=g+1;
		}
		else
		{
			d[k]=d[g]+1;
			printf("%d ",g);
			g=k;
			k++;
			l=-1;
		}
	}
	return 0;
}