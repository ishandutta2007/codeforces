#include <iostream>
#include <cstdio>
#include <cstring>
char c[100];
char k[100][100];
int s;
int l=1;
int b=1;
int main()
{
	scanf("%s",c);
	s=strlen(c);
	for(int mi=0;mi<s;mi++) k[0][mi]=c[mi];
	int n=s;
	int j;
	bool pos;
	bool f;
	int r;
	for(int b=1;b<n;b++)
	{
		pos=true;
		for(int nu=0;nu<l && pos;nu++)
		{
			f=true;
			j=b;
			r=0;
			while(j<n && f)
			{
				if(c[j]!=k[nu][r])
				{
					f=false;
				}
				j++;
				r++;
			}
			j=0;
			while(j<b && f)
			{
				if(c[j]!=k[nu][r])
				{
					f=false;
				}
				r++;
				j++;
			}
			if(f)
			{
				pos=false;
			}
		}
		if(pos)
		{
			j=b;
			r=0;
			while(j<n)
			{
				k[l][r]=c[j];
				j++;
				r++;
			}
			j=0;
			while(j<b)
			{
				k[l][r]=c[j];
				j++;
				r++;
			}
			l++;
		}
	}
	printf("%d",l);
	return 0;
}